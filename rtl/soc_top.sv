module soc_top (
    input  logic        clk,
    input  logic        rst_n,
    
    // SPI Interface (to external IMU/ESP32)
    input  logic        spi_miso,
    output logic        spi_mosi,
    output logic        spi_sclk,
    
    // Motor PWM Outputs
    output logic [3:0]  motor_pwm
);

    // Internal Memory Signals
    /* verilator lint_off UNOPTFLAT */
    logic [31:0] mem_addr, mem_wdata, mem_rdata;
    /* verilator lint_on UNOPTFLAT */
    logic        mem_we;
    
    // Core Cache Interface Signals
    logic [31:0] icache_addr;
    logic        icache_req;
    logic [31:0] dcache_addr;
    logic [31:0] dcache_wdata;
    logic        dcache_we;
    logic        dcache_req;

    // 1. RISC-V Core Instance
    // Properly mapping the split I-Cache and D-Cache interfaces
    riscv_core u_core (
        .clk(clk), 
        .rst_n(rst_n),
        
        .icache_addr(icache_addr),
        .icache_req(icache_req),
        .icache_data(mem_rdata),
        .icache_valid(1'b1), // Always hit for this simple SRAM simulation
        
        .dcache_addr(dcache_addr),
        .dcache_wdata(dcache_wdata),
        .dcache_we(dcache_we),
        .dcache_req(dcache_req),
        .dcache_rdata(mem_rdata),
        .dcache_valid(1'b1)
    );

    // Memory Arbiter: D-Cache (loads/stores) gets priority over I-Cache (fetches)
    assign mem_addr  = dcache_req ? dcache_addr : icache_addr;
    assign mem_we    = dcache_we;
    assign mem_wdata = dcache_wdata;

    // 2. Memory / IO Map
    // 0x0000_0000 - 0x0001_0000: Instruction/Data RAM
    // 0x4000_0000: IO Peripherals
    logic [31:0] ram_rdata;
    logic [31:0] io_rdata;
    
    always_comb begin
        if (mem_addr[30]) mem_rdata = io_rdata; // 0x4000...
        else              mem_rdata = ram_rdata; // 0x0000...
    end

    // 3. Block RAM (System Memory)
    logic [31:0] ram [0:4095];
    
    // Pre-load the RAM with your compiled C test!
    initial begin
        $readmemh("../../sim/tests/uart_loopback_test.hex", ram);
    end

    always_ff @(posedge clk) begin
        if (mem_we && !mem_addr[30])
            ram[mem_addr[13:2]] <= mem_wdata;
        ram_rdata <= ram[mem_addr[13:2]];
    end
    
    // 4. IO Peripherals (Motors)
    always_ff @(posedge clk) begin
        if (!rst_n) begin
             motor_pwm <= 0;
        end else if (mem_we && mem_addr == 32'h40000100) begin
             // Software writes thrust directly here
             motor_pwm <= mem_wdata[3:0]; 
        end
    end
    
    // Tie off unused IO read data to prevent floating wires in simulation
    assign io_rdata = 32'b0;

// 5. Verification UART Monitor (Simulation Only)
    // Synthesis tools ignore $write and $display, so this is safe for the FPGA!
    always_ff @(posedge clk) begin
        if (rst_n && mem_we && mem_addr == 32'h40000200) begin
            
            // Print standard ASCII characters
            if (mem_wdata >= 32'h20 && mem_wdata <= 32'h7E) begin
                $write("%c", mem_wdata[7:0]);
            end
            
            // Check for PASS/FAIL execution codes
            if (mem_wdata == 32'h000000FF) begin
                $display("\n[VERIFICATION] RESULT: PASS (0xFF detected)");
                $finish; // Exits cleanly with a success code (0)
            end else if (mem_wdata == 32'h000000EE) begin
                $display("\n[VERIFICATION] RESULT: FAIL (0xEE detected)");
                $fatal;  // Exits immediately with an error code (1) for GitHub Actions
            end
        end
    end
endmodule