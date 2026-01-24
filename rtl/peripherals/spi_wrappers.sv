module spi_wrapper (
    input  logic        clk,        // System Clock (e.g., 50MHz)
    input  logic        rst_n,

    // CPU Interface (Memory Mapped)
    input  logic [7:0]  tx_data,    // Byte to transmit
    input  logic        start,      // Trigger transaction
    output logic [7:0]  rx_data,    // Received byte
    output logic        busy,       // Transaction in progress

    // Physical SPI Interface
    output logic        spi_sclk,
    output logic        spi_mosi,
    input  logic        spi_miso,
    output logic        spi_cs_n
);

    // --- Configuration ---
    // Clock Divider: 50MHz / 50 = 1MHz SPI Clock
    localparam CLK_DIV = 50; 
    
    // --- State Machine ---
    typedef enum logic [1:0] {
        IDLE,
        TRANSFER,
        FINISH
    } state_t;
    state_t state;

    logic [5:0]  bit_count;     // 0-7 bits
    logic [7:0]  shift_reg;
    logic [7:0]  clk_cnt;       // Divider counter
    logic        sclk_enable;   // Toggles SCLK
    logic        sclk_edge;     // Rising/Falling edge strobe

    // Clock Generation
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            clk_cnt <= 0;
            sclk_enable <= 0;
            sclk_edge <= 0;
        end else if (state == TRANSFER) begin
            if (clk_cnt == (CLK_DIV/2 - 1)) begin
                clk_cnt <= 0;
                sclk_enable <= ~sclk_enable; // Toggle
                sclk_edge <= 1; // Pulse for logic update
            end else begin
                clk_cnt <= clk_cnt + 1;
                sclk_edge <= 0;
            end
        end else begin
            clk_cnt <= 0;
            sclk_enable <= 0; // Mode 0: Idle Low
            sclk_edge <= 0;
        end
    end

    assign spi_sclk = sclk_enable;

    // Shift Register Logic
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            shift_reg <= 0;
            bit_count <= 0;
            rx_data <= 0;
            busy <= 0;
            spi_cs_n <= 1;
        end else begin
            case (state)
                IDLE: begin
                    spi_cs_n <= 1;
                    busy <= 0;
                    if (start) begin
                        state <= TRANSFER;
                        shift_reg <= tx_data;
                        bit_count <= 0;
                        busy <= 1;
                        spi_cs_n <= 0; // Select Slave
                    end
                end

                TRANSFER: begin
                    if (sclk_edge) begin
                        if (sclk_enable == 0) begin 
                            // Falling Edge: Setup MOSI (Already set by shift)
                        end else begin 
                            // Rising Edge: Sample MISO & Shift
                            shift_reg <= {shift_reg[6:0], spi_miso};
                            
                            if (bit_count == 7) begin
                                state <= FINISH;
                            end else begin
                                bit_count <= bit_count + 1;
                            end
                        end
                    end
                end

                FINISH: begin
                    // Wait one half-cycle to finish last bit duration
                    if (sclk_edge) begin
                        rx_data <= shift_reg;
                        busy <= 0;
                        spi_cs_n <= 1;
                        state <= IDLE;
                    end
                end
            endcase
        end
    end

    assign spi_mosi = shift_reg[7]; // MSB First

endmodule