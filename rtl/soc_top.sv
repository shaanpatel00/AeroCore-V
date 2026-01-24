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
    // Internal Signals
    logic [31:0] mem_addr, mem_wdata, mem_rdata;
    logic        mem_we;
    
    // 1. RISC-V Core Instance
    // (Simplified instantiation)
    riscv_core u_core (
        .clk(clk), .rst_n(rst_n),
        .mem_addr(mem_addr),
        .mem_wdata(mem_wdata),
        .mem_we(mem_we),
        .mem_rdata(mem_rdata)
    );

    // 2. Memory / IO Map
    // 0x0000_0000 - 0x0001_0000: Instruction/Data RAM
    // 0x4000_0000: SPI Status/Data
    // 0x4000_0100: Motor Control Register
    
    logic [31:0] ram_rdata;
    logic [31:0] io_rdata;

    always_comb begin
        if (mem_addr[30]) mem_rdata = io_rdata; // 0x4000...
        else              mem_rdata = ram_rdata; // 0x0000...
    end

    // 3. Block RAM (System Memory)
    logic [31:0] ram [0:4095];
    always_ff @(posedge clk) begin
        if (mem_we && !mem_addr[30])
            ram[mem_addr[13:2]] <= mem_wdata;
        ram_rdata <= ram[mem_addr[13:2]];
    end
    
    // 4. IO Peripherals (SPI & Motors)
    always_ff @(posedge clk) begin
        if (!rst_n) begin
             motor_pwm <= 0;
        end else if (mem_we && mem_addr == 32'h40000100) begin
             // Software writes thrust directly here
             motor_pwm <= mem_wdata[3:0]; 
        end
    end
endmodule