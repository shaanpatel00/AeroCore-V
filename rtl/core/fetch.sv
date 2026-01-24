module fetch (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        stall,
    
    // Branch/Jump Interface
    input  logic        pc_load,      // Take Branch/Jump
    input  logic [31:0] pc_target,    // Target Address
    
    // I-Cache Interface
    output logic [31:0] icache_addr,
    output logic        icache_req,
    input  logic        icache_gnt,   // Stall if cache misses
    
    // Pipeline Output
    output logic [31:0] pc_out,
    output logic [31:0] pc_plus_4_out
);
    logic [31:0] pc;
    logic [31:0] next_pc;

    assign pc_plus_4_out = pc + 4;
    assign icache_addr = pc;
    assign icache_req  = !rst_n ? 0 : 1; // Always fetch unless reset
    assign pc_out = pc;

    // Next PC Logic
    always_comb begin
        if (pc_load) 
            next_pc = pc_target;
        else 
            next_pc = pc + 4;
    end

    // PC Register
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 32'h0000_0000; // Reset Vector
        end else if (!stall && icache_gnt) begin
            pc <= next_pc;
        end
        // Else hold PC
    end

endmodule