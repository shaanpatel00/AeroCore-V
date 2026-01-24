module uart (
    input  logic        clk,
    input  logic        rst_n,
    
    // CPU Interface
    input  logic [7:0]  tx_data,
    input  logic        tx_start,
    output logic        tx_busy,
    
    input  logic        rx_pin,
    output logic        tx_pin
);

    // 115200 Baud @ 50MHz
    localparam CLKS_PER_BIT = 434;
    
    logic [8:0] clk_count;
    logic [2:0] bit_index;
    logic [7:0] tx_shifter;
    logic       tx_active;
    
    typedef enum logic [1:0] {IDLE, START, DATA, STOP} tx_state_t;
    tx_state_t tx_state;
    
    assign tx_busy = tx_active;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tx_state <= IDLE;
            tx_pin   <= 1;
            tx_active <= 0;
            clk_count <= 0;
            bit_index <= 0;
        end else begin
            case (tx_state)
                IDLE: begin
                    tx_pin <= 1;
                    if (tx_start) begin
                        tx_state <= START;
                        tx_shifter <= tx_data;
                        tx_active <= 1;
                        clk_count <= 0;
                    end
                end
                
                START: begin
                    tx_pin <= 0; // Start Bit
                    if (clk_count < CLKS_PER_BIT-1) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count <= 0;
                        tx_state <= DATA;
                        bit_index <= 0;
                    end
                end
                
                DATA: begin
                    tx_pin <= tx_shifter[bit_index];
                    if (clk_count < CLKS_PER_BIT-1) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count <= 0;
                        if (bit_index < 7) begin
                            bit_index <= bit_index + 1;
                        end else begin
                            tx_state <= STOP;
                        end
                    end
                end
                
                STOP: begin
                    tx_pin <= 1; // Stop Bit
                    if (clk_count < CLKS_PER_BIT-1) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        tx_state <= IDLE;
                        tx_active <= 0;
                    end
                end
            endcase
        end
    end
endmodule