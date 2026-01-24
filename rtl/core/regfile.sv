module regfile (
    input  logic        clk,
    input  logic        rst_n,
    
    input  logic [4:0]  raddr_a,
    output logic [31:0] rdata_a,
    
    input  logic [4:0]  raddr_b,
    output logic [31:0] rdata_b,
    
    input  logic [4:0]  waddr,
    input  logic [31:0] wdata,
    input  logic        wen
);
    logic [31:0] regs [0:31];

    // Read Logic (Asynchronous)
    assign rdata_a = (raddr_a == 0) ? 32'b0 : regs[raddr_a];
    assign rdata_b = (raddr_b == 0) ? 32'b0 : regs[raddr_b];

    // Write Logic (Synchronous)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Optional: Reset registers for simulation cleanliness
            for (int i=0; i<32; i++) regs[i] <= 32'b0;
        end else if (wen && waddr != 0) begin
            regs[waddr] <= wdata;
        end
    end

endmodule