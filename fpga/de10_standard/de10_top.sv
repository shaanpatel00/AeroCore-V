module de10_top (
    // --- Clock & Reset ---
    input  logic        CLOCK_50, // 50MHz Onboard Oscillator
    input  logic [3:0]  KEY,      // Pushbuttons (Active Low)
    
    // --- User Interface ---
    input  logic [9:0]  SW,       // Switches
    output logic [9:0]  LEDR,     // Red LEDs
    output logic [6:0]  HEX0,     // 7-Segment Display (Debug)
    output logic [6:0]  HEX1,
    
    // --- GPIO Header 0 (External Hardware) ---
    // Mapping:
    // GPIO[0] = SPI_MISO (Input from IMU)
    // GPIO[1] = SPI_MOSI (Output to IMU)
    // GPIO[2] = SPI_SCLK (Output to IMU)
    // GPIO[3] = SPI_CS_N (Chip Select)
    // GPIO[5:4] = Unused
    // GPIO[9:6] = Motor PWM Outputs 0-3
    inout  logic [35:0] GPIO
);

    // 1. Signal Declarations
    logic rst_n;
    logic spi_miso, spi_mosi, spi_sclk, spi_cs_n;
    logic [3:0] motor_pwm;
    
    // 2. Reset Logic (KEY0 is Reset)
    // Synchronize the asynchronous reset button to the clock domain
    logic rst_sync_1, rst_sync_2;
    always_ff @(posedge CLOCK_50) begin
        rst_sync_1 <= KEY[0];
        rst_sync_2 <= rst_sync_1;
    end
    assign rst_n = rst_sync_2;

    // 3. SoC Instantiation
    soc_top u_soc (
        .clk(CLOCK_50),
        .rst_n(rst_n),
        
        // SPI Interface (IMU)
        .spi_miso(spi_miso),
        .spi_mosi(spi_mosi),
        .spi_sclk(spi_sclk),
        
        // Motor Interface
        .motor_pwm(motor_pwm)
    );
    
    // 4. Pin Mapping (GPIO Header 0)
    // Inputs
    assign spi_miso = GPIO[0];
    
    // Outputs
    assign GPIO[1] = spi_mosi;
    assign GPIO[2] = spi_sclk;
    assign GPIO[3] = 1'b1; // CS_N (Manual or tied high if unused)
    
    assign GPIO[6] = motor_pwm[0];
    assign GPIO[7] = motor_pwm[1];
    assign GPIO[8] = motor_pwm[2];
    assign GPIO[9] = motor_pwm[3];
    
    // 5. Debug LEDs
    // Visualize Motor PWM activity on LEDs
    assign LEDR[3:0] = motor_pwm;
    
    // Visualize Reset State
    assign LEDR[9] = !rst_n;

    // Turn off unused HEX displays
    assign HEX0 = 7'b1111111;
    assign HEX1 = 7'b1111111;

endmodule