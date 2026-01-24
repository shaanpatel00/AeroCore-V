module riscv_core (
    input  logic        clk,
    input  logic        rst_n,

    // I-Cache Interface
    output logic [31:0] icache_addr,
    output logic        icache_req,
    input  logic [31:0] icache_data,
    input  logic        icache_valid,

    // D-Cache Interface
    output logic [31:0] dcache_addr,
    output logic [31:0] dcache_wdata,
    output logic        dcache_we,
    output logic        dcache_req,
    input  logic [31:0] dcache_rdata,
    input  logic        dcache_valid
);
    import RISCV_PKG::*;

    // --- Signals ---
    // Fetch -> Decode
    logic [31:0] if_pc, if_instr;
    
    // Decode -> Execute
    alu_opcode_e id_alu_op;
    op_a_sel_e   id_op_a_sel;
    op_b_sel_e   id_op_b_sel;
    logic [31:0] id_rs1, id_rs2, id_imm;
    logic [31:0] id_op_a, id_op_b;
    logic        id_pid_en;
    logic [4:0]  id_rd;
    logic        id_wb_en;
    
    // PID CSRs (Mocked for simplicity)
    logic [31:0] csr_kp = 32'h00050000; // 5.0
    logic [31:0] csr_ki = 32'h00004CCC; // 0.3
    logic [31:0] csr_kd = 32'h00028000; // 2.5
    logic [31:0] pid_integ;

    // Execute Outputs
    logic [31:0] ex_result;
    logic [31:0] pid_integ_next;
    
    // --- Stages ---

    // 1. Fetch
    fetch u_fetch (
        .clk(clk),
        .rst_n(rst_n),
        .stall(!icache_valid), // Stall if I-Cache miss
        .pc_load(0),           // Branching not fully wired in this snippet
        .pc_target(32'b0),
        .icache_addr(icache_addr),
        .icache_req(icache_req),
        .icache_gnt(icache_valid),
        .pc_out(if_pc),
        .pc_plus_4_out()
    );
    assign if_instr = icache_data;

    // 2. Decode
    decode u_decode (
        .clk(clk),
        .rst_n(rst_n),
        .instr(if_instr),
        .pc(if_pc),
        .wb_en(id_wb_en),     // Loopback for simple test
        .wb_addr(id_rd),
        .wb_data(ex_result),
        .alu_op(id_alu_op),
        .op_a_sel(id_op_a_sel),
        .op_b_sel(id_op_b_sel),
        .imm(id_imm),
        .mem_we(dcache_we),
        .mem_re(dcache_req), // If mem_re is high, we req D-Cache
        .wb_en_out(id_wb_en),
        .wb_mux(),
        .pid_en(id_pid_en),
        .rs1_data(id_rs1),
        .rs2_data(id_rs2),
        .rs1_addr(),
        .rs2_addr(),
        .rd_addr(id_rd)
    );

    // Operand Muxing
    assign id_op_a = (id_op_a_sel == OPA_REG) ? id_rs1 : 
                     (id_op_a_sel == OPA_PC)  ? if_pc  : 32'b0;
    assign id_op_b = (id_op_b_sel == OPB_REG) ? id_rs2 : id_imm;

    // 3. Execute
    execute u_execute (
        .clk(clk),
        .rst_n(rst_n),
        .alu_op(id_alu_op),
        .pid_en(id_pid_en),
        .op_a(id_op_a),
        .op_b(id_op_b),
        .pid_kp(csr_kp),
        .pid_ki(csr_ki),
        .pid_kd(csr_kd),
        .alu_result(ex_result),
        .pid_integ_wb(pid_integ_next)
    );
    
    // D-Cache Assignments
    assign dcache_addr  = ex_result;
    assign dcache_wdata = id_rs2; // STORE data comes from rs2

    // Update Integral Term on PID op
    always_ff @(posedge clk) begin
        if (!rst_n) pid_integ <= 0;
        else if (id_pid_en) pid_integ <= pid_integ_next;
    end

endmodule