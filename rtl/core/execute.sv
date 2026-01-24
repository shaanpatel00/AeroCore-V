module execute (
    input  logic        clk,
    input  logic        rst_n,
    
    // Control Signals
    input  RISCV_PKG::alu_opcode_e alu_op,
    input  logic        pid_en,
    
    // Operands
    input  logic [31:0] op_a,
    input  logic [31:0] op_b,
    
    // CSR inputs for PID (Passed from Core/CSR unit)
    input  logic [31:0] pid_kp,
    input  logic [31:0] pid_ki,
    input  logic [31:0] pid_kd,
    
    // Output
    output logic [31:0] alu_result,
    output logic [31:0] pid_integ_wb // Integral term writeback
);
    import RISCV_PKG::*;

    logic [31:0] std_result;
    logic [31:0] pid_result;

    // 1. Standard ALU
    always_comb begin
        case (alu_op)
            ALU_ADD: std_result = op_a + op_b;
            ALU_SUB: std_result = op_a - op_b;
            ALU_SLL: std_result = op_a << op_b[4:0];
            ALU_SRL: std_result = op_a >> op_b[4:0];
            ALU_SRA: std_result = $signed(op_a) >>> op_b[4:0];
            ALU_SLT: std_result = ($signed(op_a) < $signed(op_b)) ? 32'b1 : 32'b0;
            ALU_SLTU:std_result = (op_a < op_b) ? 32'b1 : 32'b0;
            ALU_XOR: std_result = op_a ^ op_b;
            ALU_OR:  std_result = op_a | op_b;
            ALU_AND: std_result = op_a & op_b;
            default: std_result = 32'b0;
        endcase
    end

    // 2. Custom PID ALU Instance
    alu_pid u_pid_alu (
        .clk(clk),
        .rst_n(rst_n),
        .error(op_a),      // rs1
        .prev_error(op_b), // rs2
        .coeff_kp(pid_kp),
        .coeff_ki(pid_ki),
        .coeff_kd(pid_kd),
        .dt_fixed(32'h00010000), // Normalized dt=1.0 in Q16.16
        .control_out(pid_result),
        .integ_update(pid_integ_wb)
    );

    // 3. Result Selection
    assign alu_result = (pid_en) ? pid_result : std_result;

endmodule