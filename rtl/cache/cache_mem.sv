module cache_mem #(
    parameter DATA_WIDTH = 32,
    parameter DEPTH      = 64
) (
    input  logic                   clk,
    input  logic                   we,
    input  logic [$clog2(DEPTH)-1:0] addr,
    input  logic [DATA_WIDTH-1:0]  wdata,
    output logic [DATA_WIDTH-1:0]  rdata
);

    logic [DATA_WIDTH-1:0] ram [0:DEPTH-1];

    always_ff @(posedge clk) begin
        if (we)
            ram[addr] <= wdata;
        // Read-during-write: New data
        rdata <= ram[addr];
    end

endmodule