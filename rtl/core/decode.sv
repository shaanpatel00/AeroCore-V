module decode (
    input  logic        clk,
    input  logic        rst_n,
    
    // Inputs from Fetch
    input  logic [31:0] instr,
    input  logic [31:0] pc,
    
    // Writeback Inputs (Forwarding handled in core)
    input  logic        wb_en,
    input  logic [4:0]  wb_addr,
    input  logic [31:0] wb_data,
    
    // Outputs to Execute
    output RISCV_PKG::alu_opcode_e alu_op,
    output RISCV_PKG::op_a_sel_e   op_a_sel,
    output RISCV_PKG::op_b_sel_e   op_b_sel,
    output logic [31:0] imm,
    output logic        mem_we,
    output logic        mem_re,
    output logic        wb_en_out,
    output RISCV_PKG::wb_mux_sel_e wb_mux,
    output logic        pid_en,      // NEW: Enable PID ALU
    
    // Register File Outputs
    output logic [31:0] rs1_data,
    output logic [31:0] rs2_data,
    output logic [4:0]  rs1_addr,
    output logic [4:0]  rs2_addr,
    output logic [4:0]  rd_addr
);
    import RISCV_PKG::*;

    // Instruction Decoding
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;
    
    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];
    assign rd_addr  = instr[11:7];
    assign rs1_addr = instr[19:15];
    assign rs2_addr = instr[24:20];

    // Immediate Generation
    always_comb begin
        case (opcode)
            OPCODE_OPIMM, OPCODE_LOAD, OPCODE_JALR: 
                imm = {{20{instr[31]}}, instr[31:20]}; // I-Type
            OPCODE_STORE: 
                imm = {{20{instr[31]}}, instr[31:25], instr[11:7]}; // S-Type
            OPCODE_BRANCH: 
                imm = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0}; // B-Type
            OPCODE_JAL: 
                imm = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0}; // J-Type
            OPCODE_LUI, OPCODE_AUIPC: 
                imm = {instr[31:12], 12'b0}; // U-Type
            default: 
                imm = 32'b0;
        endcase
    end

    // Control Logic
    always_comb begin
        // Defaults
        alu_op   = ALU_ADD;
        op_a_sel = OPA_REG;
        op_b_sel = OPB_REG;
        wb_en_out= 0;
        mem_we   = 0;
        mem_re   = 0;
        wb_mux   = WB_ALU;
        pid_en   = 0;

        case (opcode)
            OPCODE_OP: begin
                wb_en_out = 1;
                case (funct3)
                    3'b000: alu_op = (funct7[5]) ? ALU_SUB : ALU_ADD;
                    3'b001: alu_op = ALU_SLL;
                    3'b010: alu_op = ALU_SLT;
                    3'b011: alu_op = ALU_SLTU;
                    3'b100: alu_op = ALU_XOR;
                    3'b101: alu_op = (funct7[5]) ? ALU_SRA : ALU_SRL;
                    3'b110: alu_op = ALU_OR;
                    3'b111: alu_op = ALU_AND;
                endcase
            end
            
            OPCODE_OPIMM: begin
                wb_en_out = 1;
                op_b_sel  = OPB_IMM;
                case (funct3)
                    3'b000: alu_op = ALU_ADD; // ADDI
                    3'b010: alu_op = ALU_SLT;
                    3'b011: alu_op = ALU_SLTU;
                    3'b100: alu_op = ALU_XOR;
                    3'b110: alu_op = ALU_OR;
                    3'b111: alu_op = ALU_AND;
                    3'b001: alu_op = ALU_SLL;
                    3'b101: alu_op = (funct7[5]) ? ALU_SRA : ALU_SRL;
                endcase
            end

            OPCODE_LOAD: begin
                wb_en_out = 1;
                op_b_sel  = OPB_IMM;
                mem_re    = 1;
                wb_mux    = WB_MEM;
            end

            OPCODE_STORE: begin
                op_b_sel = OPB_IMM;
                mem_we   = 1;
            end
            
            OPCODE_LUI: begin
                wb_en_out = 1;
                op_a_sel  = OPA_ZERO; // 0 + imm
                op_b_sel  = OPB_IMM;
            end

            // --- CUSTOM PID INSTRUCTION ---
            OPCODE_CUSTOM0: begin
                wb_en_out = 1;
                pid_en    = 1;
                alu_op    = ALU_PID;
                // rs1=Error, rs2=PrevError, rd=ControlOutput
            end
        endcase
    end

    // Register File Instantiation
    regfile u_regfile (
        .clk(clk),
        .rst_n(rst_n),
        .raddr_a(rs1_addr),
        .rdata_a(rs1_data),
        .raddr_b(rs2_addr),
        .rdata_b(rs2_data),
        .waddr(wb_addr),
        .wdata(wb_data),
        .wen(wb_en)
    );

endmodule