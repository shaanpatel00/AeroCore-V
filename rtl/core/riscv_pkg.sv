package RISCV_PKG;
    // --- Standard RISC-V Opcodes ---
    parameter OPCODE_OP     = 7'h33; // R-Type
    parameter OPCODE_OPIMM  = 7'h13; // I-Type
    parameter OPCODE_LOAD   = 7'h03;
    parameter OPCODE_STORE  = 7'h23;
    parameter OPCODE_BRANCH = 7'h63;
    parameter OPCODE_JAL    = 7'h6F;
    parameter OPCODE_JALR   = 7'h67;
    parameter OPCODE_LUI    = 7'h37;
    parameter OPCODE_AUIPC  = 7'h17;
    
    // --- CUSTOM EXTENSION ---
    // PID Accelerator Opcode (Custom-0)
    parameter OPCODE_CUSTOM0 = 7'h0B; 

    // --- ALU Operations ---
    typedef enum logic [6:0] {
        ALU_NOP   = 7'b0000000,
        ALU_ADD   = 7'b0011000,
        ALU_SUB   = 7'b0011001,
        ALU_SLL   = 7'b0011010,
        ALU_SLT   = 7'b0011011,
        ALU_SLTU  = 7'b0011100,
        ALU_XOR   = 7'b0011101,
        ALU_SRL   = 7'b0011110,
        ALU_SRA   = 7'b0011111,
        ALU_OR    = 7'b0100000,
        ALU_AND   = 7'b0100001,
        
        // Custom ALU Op
        ALU_PID   = 7'b1111111
    } alu_opcode_e;

    // --- Mux Selectors ---
    typedef enum logic [1:0] {
        OPA_REG = 2'b00,
        OPA_PC  = 2'b01,
        OPA_ZERO= 2'b10
    } op_a_sel_e;

    typedef enum logic [1:0] {
        OPB_REG = 2'b00,
        OPB_IMM = 2'b01
    } op_b_sel_e;
    
    typedef enum logic [1:0] {
        WB_ALU = 2'b00,
        WB_MEM = 2'b01,
        WB_PC4 = 2'b10
    } wb_mux_sel_e;

endpackage