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
    assign dcache_ram_data = ram[dcache_addr[13:2]];

    always_ff @(posedge clk) begin
        if (dcache_we && !dcache_addr[30]) begin
            ram[dcache_addr[13:2]] <= dcache_wdata;
        end
    end

    // --- 2. IO MOCKING ---
    logic [7:0] uart_mock_rx_buffer;
    
    always_comb begin
        io_rdata = 32'b0;
        if (dcache_addr == 32'h40000000) begin
            io_rdata = ext_sensor_data;              // Read altitude from C++ Physics Engine
        end else if (dcache_addr == 32'h40000204) begin
            io_rdata = {24'b0, uart_mock_rx_buffer}; // Read RX Register
        end else if (dcache_addr == 32'h40000208) begin
            io_rdata = 32'h00000003;                 // Status Register: TX_READY & RX_VALID
        end
    end

    always_ff @(posedge clk) begin
        if (!rst_n) begin
             motor_pwm <= 0;
             uart_mock_rx_buffer <= 0;
        end else if (dcache_we) begin
             if (dcache_addr == 32'h40000100) begin
                 motor_pwm <= dcache_wdata[3:0]; 
             end else if (dcache_addr == 32'h40000200) begin
                 // Loopback: Save TX writes directly into the RX buffer
                 uart_mock_rx_buffer <= dcache_wdata[7:0]; 
             end
        end
    end

    // --- 3. RISC-V CORE ---
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
        // If address bit 30 is high, route to IO mock, else route to RAM
        .dcache_rdata(dcache_addr[30] ? io_rdata : dcache_ram_data), 
        .dcache_valid(1'b1)
    );

    // --- 4. VERIFICATION MONITOR ---
    always_ff @(posedge clk) begin
        if (rst_n && dcache_we && dcache_addr == 32'h40000200) begin
            // Print standard ASCII characters to terminal
            if (dcache_wdata[7:0] >= 8'h20 && dcache_wdata[7:0] <= 8'h7E) begin
                $write("%c", dcache_wdata[7:0]);
            end
            
            // Catch completion codes (Masked to 8 bits to prevent C sign-extension bugs)
            if (dcache_wdata[7:0] == 8'hFF) begin
                $display("\n[VERIFICATION] RESULT: PASS (0xFF detected)");
                $finish; 
            end else if (dcache_wdata[7:0] == 8'hEE) begin
                $display("\n[VERIFICATION] RESULT: FAIL (0xEE detected)");
                $fatal;  
            end
        end
    end

endmodule