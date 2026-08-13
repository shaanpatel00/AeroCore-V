module soc_top (
    input  logic        clk,
    input  logic        rst_n,
    
    // --- NEW: Digital Twin Sensor Backdoor ---
    input  logic [31:0] ext_sensor_data,
    
    // SPI Interface (to external IMU/ESP32)
    input  logic        spi_miso,
    output logic        spi_mosi,
    output logic        spi_sclk,
    
    // Motor PWM Outputs
    output logic [3:0]  motor_pwm
);

    // Core Cache Interface Signals
    logic [31:0] icache_addr;
    logic        icache_req;
    logic [31:0] dcache_addr;
    logic [31:0] dcache_wdata;
    logic        dcache_we;
    logic        dcache_req;
    logic [2:0]  dcache_funct3;

    // RAM and IO logic
    logic [31:0] ram [0:4095];
    logic [31:0] icache_ram_data;
    logic [31:0] dcache_ram_data;
    logic [31:0] io_rdata;

    // Load the Flight Control Kernel
    initial begin
        $readmemh("../../sw/kernel.hex", ram); // Update this path to your actual compiled kernel!
    end

    // --- 1. TRUE DUAL-PORT COMBINATIONAL RAM ---
    // Instruction Cache gets Port A, Data Cache gets Port B
    assign icache_ram_data = ram[icache_addr[13:2]];
    assign dcache_ram_data = ram[l2_mem_addr[13:2]];

    always_ff @(posedge clk) begin
        if (l2_mem_we && l2_mem_req && !l2_mem_addr[30]) begin
            ram[l2_mem_addr[13:2]] <= l2_mem_wdata;
        end
    end

    // --- 1b. PTW Backdoor Read Port ---
    // The page table walker needs its own read path into main memory,
    // independent of the CPU's I/D cache traffic. This is a simple
    // request/latch/respond wrapper giving 1-cycle read latency, matching
    // the req/valid protocol ptw.sv expects from its memory interface.
    logic [31:0] ptw_mem_addr;
    logic        ptw_mem_req;
    logic [31:0] ptw_mem_rdata;
    logic        ptw_mem_valid;
    logic [31:0] ptw_addr_latched;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ptw_mem_valid <= 0;
        end else begin
            ptw_mem_valid <= ptw_mem_req;
            if (ptw_mem_req) ptw_addr_latched <= ptw_mem_addr;
        end
    end
    assign ptw_mem_rdata = ram[ptw_addr_latched[13:2]];

    // --- 2. IO MOCKING ---
    logic [7:0] uart_mock_rx_buffer;
    
    always_comb begin
        io_rdata = 32'b0;
        if (l2_mem_addr == 32'h40000000) begin
            io_rdata = ext_sensor_data;              // Read altitude from C++ Physics Engine
        end else if (l2_mem_addr == 32'h40000204) begin
            io_rdata = {24'b0, uart_mock_rx_buffer}; // Read RX Register
        end else if (l2_mem_addr == 32'h40000208) begin
            io_rdata = 32'h00000003;                 // Status Register: TX_READY & RX_VALID
        end
    end

    always_ff @(posedge clk) begin
        if (!rst_n) begin
             motor_pwm <= 0;
             uart_mock_rx_buffer <= 0;
        end else if (l2_mem_we && l2_mem_req) begin
             if (l2_mem_addr == 32'h40000100) begin
                 motor_pwm <= l2_mem_wdata[3:0]; 
             end else if (l2_mem_addr == 32'h40000200) begin
                 uart_mock_rx_buffer <= l2_mem_wdata[7:0]; 
             end
        end
    end

    // --- 3. RISC-V CORE ---
    // L1-to-core signals renamed; L1-to-memory ("L2 side") signals added
    logic [31:0] l1_mem_addr, l1_mem_wdata, l1_mem_rdata;
    logic        l1_mem_req, l1_mem_we, l1_mem_valid;
    logic [31:0] l2_mem_addr, l2_mem_wdata, l2_mem_rdata;
    logic        l2_mem_req, l2_mem_we, l2_mem_valid;
    logic [31:0] core_dcache_rdata;
    logic        core_dcache_valid;

    riscv_core u_core (
        .clk(clk), 
        .rst_n(rst_n),
        .icache_addr(icache_addr),
        .icache_req(icache_req),
        .icache_data(icache_ram_data), 
        .icache_valid(1'b1),
        .dcache_addr(dcache_addr),
        .dcache_wdata(dcache_wdata),
        .dcache_we(dcache_we),
        .dcache_req(dcache_req),
        .dcache_funct3(dcache_funct3),
        .dcache_rdata(core_dcache_rdata),
        .dcache_valid(core_dcache_valid),
        .ptw_mem_addr(ptw_mem_addr),
        .ptw_mem_req(ptw_mem_req),
        .ptw_mem_rdata(ptw_mem_rdata),
        .ptw_mem_valid(ptw_mem_valid)
    );

    `ifdef BYPASS_L1
        assign core_dcache_rdata = l2_mem_rdata;
        assign core_dcache_valid = l2_mem_valid;
        assign l2_mem_addr  = dcache_addr;
        assign l2_mem_wdata = dcache_wdata;
        assign l2_mem_req   = dcache_req;
        assign l2_mem_we    = dcache_we;
    `else
        l1_controller u_l1 (
            .clk(clk),
            .rst_n(rst_n),
            .cpu_addr(dcache_addr),
            .cpu_wdata(dcache_wdata),
            .cpu_req(dcache_req),
            .cpu_we(dcache_we),
            .cpu_funct3(dcache_funct3),
            .cpu_rdata(core_dcache_rdata),
            .cpu_valid(core_dcache_valid),
            .l2_addr(l1_mem_addr),
            .l2_wdata(l1_mem_wdata),
            .l2_req(l1_mem_req),
            .l2_we(l1_mem_we),
            .l2_rdata(l1_mem_rdata),
            .l2_valid(l1_mem_valid)
        );

        l2_controller u_l2 (
            .clk(clk),
            .rst_n(rst_n),
            .l1_addr(l1_mem_addr),
            .l1_wdata(l1_mem_wdata),
            .l1_req(l1_mem_req),
            .l1_we(l1_mem_we),
            .l1_rdata(l1_mem_rdata),
            .l1_valid(l1_mem_valid),
            .mem_addr(l2_mem_addr),
            .mem_wdata(l2_mem_wdata),
            .mem_req(l2_mem_req),
            .mem_we(l2_mem_we),
            .mem_rdata(l2_mem_rdata),
            .mem_gnt(l2_mem_valid)
        );
    `endif

    /*
    assign core_dcache_rdata = l1_mem_rdata;
    assign core_dcache_valid = l1_mem_valid;
    assign l1_mem_addr  = dcache_addr;
    assign l1_mem_wdata = dcache_wdata;
    assign l1_mem_req   = dcache_req;
    assign l1_mem_we    = dcache_we;
    */

    // Memory/IO now serves the L2 controller instead of L1 directly
    // Simulate realistic DRAM-style backing memory latency (8 cycles per access)
    localparam MEM_LATENCY = 8;
    logic [3:0] mem_delay_cnt;
    logic       mem_pending;

    assign l2_mem_rdata = l2_mem_addr[31:16] == 16'h4000 ? io_rdata : dcache_ram_data;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mem_delay_cnt <= 0;
            mem_pending   <= 0;
            l2_mem_valid  <= 0;
        end else if (l2_mem_req && !mem_pending) begin
            mem_pending  <= 1;
            mem_delay_cnt <= MEM_LATENCY - 1;
            l2_mem_valid <= 0;
        end else if (mem_pending) begin
            if (mem_delay_cnt == 0) begin
                l2_mem_valid <= 1;
                mem_pending  <= 0;
            end else begin
                mem_delay_cnt <= mem_delay_cnt - 1;
                l2_mem_valid <= 0;
            end
        end else begin
            l2_mem_valid <= 0;
        end
    end

    // --- 4. VERIFICATION MONITOR ---
    always_ff @(posedge clk) begin
        if (rst_n && l2_mem_we && l2_mem_req && l2_mem_valid && l2_mem_addr == 32'h40000200) begin
            if (l2_mem_wdata[7:0] >= 8'h20 && l2_mem_wdata[7:0] <= 8'h7E) begin
                $write("%c", l2_mem_wdata[7:0]);
            end
            if (l2_mem_wdata[7:0] == 8'hFF) begin
                $display("\n[VERIFICATION] RESULT: PASS (0xFF detected)");
                $finish; 
            end else if (l2_mem_wdata[7:0] == 8'hEE) begin
                $display("\n[VERIFICATION] RESULT: FAIL (0xEE detected)");
                $fatal;  
            end
        end
    end

endmodule