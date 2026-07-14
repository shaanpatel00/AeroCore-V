module riscv_core (
    input  logic        clk,
    input  logic        rst_n,
    
    output logic [31:0] icache_addr,
    output logic        icache_req,
    input  logic [31:0] icache_data,
    input  logic        icache_valid,
    
    output logic [31:0] dcache_addr,
    output logic [31:0] dcache_wdata,
    output logic        dcache_we,
    output logic        dcache_req,
    input  logic [31:0] dcache_rdata,
    input  logic        dcache_valid
    
);
    import RISCV_PKG::*;

    logic [31:0] if_pc, if_instr;
    logic [31:0] if_pc_plus_4;
    
    alu_opcode_e id_alu_op;
    op_a_sel_e   id_op_a_sel;
    op_b_sel_e   id_op_b_sel;
    logic [31:0] id_rs1, id_rs2, id_imm;
    logic [31:0] id_op_a, id_op_b;
    logic        id_pid_en;
    logic [4:0]  id_rd;
    logic        id_wb_en;
    wb_mux_sel_e id_wb_mux;
    
    logic [31:0] csr_kp = 32'h00050000;
    logic [31:0] csr_ki = 32'h00004CCC;
    logic [31:0] csr_kd = 32'h00028000;
    logic [31:0] pid_integ;

    logic [31:0] ex_result;
    logic [31:0] pid_integ_next;
    
    // --- Branch & Jump Logic ---
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic is_branch, is_jal, is_jalr;
    logic branch_taken;
    logic core_pc_load;
    logic [31:0] core_pc_target;
    
    logic core_stall;
    assign core_stall = dcache_req && !dcache_valid;

    logic id_wb_en_gated;
    assign id_wb_en_gated = id_wb_en && !core_stall;

    assign opcode = if_instr[6:0];
    assign funct3 = if_instr[14:12];
    assign is_branch = (opcode == OPCODE_BRANCH);
    assign is_jal    = (opcode == OPCODE_JAL);
    assign is_jalr   = (opcode == OPCODE_JALR);

    always_comb begin
        branch_taken = 0;
        if (is_branch) begin
            case (funct3)
                3'b000: branch_taken = (id_rs1 == id_rs2); // BEQ
                3'b001: branch_taken = (id_rs1 != id_rs2); // BNE
                3'b100: branch_taken = ($signed(id_rs1) < $signed(id_rs2)); // BLT
                3'b101: branch_taken = ($signed(id_rs1) >= $signed(id_rs2)); // BGE
                3'b110: branch_taken = (id_rs1 < id_rs2); // BLTU
                3'b111: branch_taken = (id_rs1 >= id_rs2); // BGEU
                default: branch_taken = 0;
            endcase
        end
    end

    assign core_pc_load = (is_branch & branch_taken) | is_jal | is_jalr;
    assign core_pc_target = is_jalr ? ((id_rs1 + id_imm) & ~32'b1) : (if_pc + id_imm);

    // --- Memory Read Byte Extraction (LB/LBU for Strings) ---
    logic [31:0] mem_read_data;
    always_comb begin
        if (opcode == OPCODE_LOAD) begin
            if (funct3 == 3'b000) begin // LB
                case (ex_result[1:0])
                    2'b00: mem_read_data = {{24{dcache_rdata[7]}}, dcache_rdata[7:0]};
                    2'b01: mem_read_data = {{24{dcache_rdata[15]}}, dcache_rdata[15:8]};
                    2'b10: mem_read_data = {{24{dcache_rdata[23]}}, dcache_rdata[23:16]};
                    2'b11: mem_read_data = {{24{dcache_rdata[31]}}, dcache_rdata[31:24]};
                endcase
            end else if (funct3 == 3'b100) begin // LBU
                case (ex_result[1:0])
                    2'b00: mem_read_data = {24'b0, dcache_rdata[7:0]};
                    2'b01: mem_read_data = {24'b0, dcache_rdata[15:8]};
                    2'b10: mem_read_data = {24'b0, dcache_rdata[23:16]};
                    2'b11: mem_read_data = {24'b0, dcache_rdata[31:24]};
                endcase
            end else begin
                mem_read_data = dcache_rdata; // LW
            end
        end else begin
            mem_read_data = dcache_rdata;
        end
    end

    // --- Writeback Mux ---
    logic [31:0] core_wb_data;
    always_comb begin
        case (id_wb_mux)
            WB_ALU: core_wb_data = ex_result;
            WB_MEM: core_wb_data = mem_read_data;
            WB_PC4: core_wb_data = if_pc_plus_4;
            default: core_wb_data = ex_result;
        endcase
    end

    // 1. Fetch
    fetch u_fetch (
        .clk(clk),
        .rst_n(rst_n),
        .stall(!icache_valid || core_stall),
        .pc_load(core_pc_load),
        .pc_target(core_pc_target),
        .icache_addr(icache_addr),
        .icache_req(icache_req),
        .icache_gnt(icache_valid),
        .pc_out(if_pc),
        .pc_plus_4_out(if_pc_plus_4)
    );
    assign if_instr = icache_data;

    // 2. Decode
    decode u_decode (
        .clk(clk),
        .rst_n(rst_n),
        .instr(if_instr),
        .pc(if_pc),
        .wb_en(id_wb_en_gated),
        .wb_addr(id_rd),
        .wb_data(core_wb_data),
        .alu_op(id_alu_op),
        .op_a_sel(id_op_a_sel),
        .op_b_sel(id_op_b_sel),
        .imm(id_imm),
        .mem_we(dcache_we),
        .mem_re(dcache_req),
        .wb_en_out(id_wb_en),
        .wb_mux(id_wb_mux),
        .pid_en(id_pid_en),
        .rs1_data(id_rs1),
        .rs2_data(id_rs2),
        .rs1_addr(),
        .rs2_addr(),
        .rd_addr(id_rd)
    );

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

    assign dcache_addr  = ex_result;
    assign dcache_wdata = id_rs2;

    always_ff @(posedge clk) begin
        if (!rst_n) pid_integ <= 0;
        else if (id_pid_en && !core_stall) pid_integ <= pid_integ_next;
    end

endmodule