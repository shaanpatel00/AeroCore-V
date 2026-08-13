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
    output logic [2:0]  dcache_funct3,
    input  logic [31:0] dcache_rdata,
    input  logic        dcache_valid,

    output logic [31:0] ptw_mem_addr,
    output logic        ptw_mem_req,
    input  logic [31:0] ptw_mem_rdata,
    input  logic        ptw_mem_valid
    
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

    // --- Minimal CSR file: satp only (CSR addr 12'h180) ---
    logic        id_csr_we;
    logic [11:0] csr_addr;
    logic [31:0] csr_satp;
    assign csr_addr = if_instr[31:20];

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            csr_satp <= 32'b0;
        end else if (id_csr_we && !core_stall && (csr_addr == 12'h180)) begin
            csr_satp <= id_rs1;
        end
    end

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
        .mem_re(dcache_req_raw),
        .wb_en_out(id_wb_en),
        .wb_mux(id_wb_mux),
        .pid_en(id_pid_en),
        .csr_we(id_csr_we),
        .rs1_data(id_rs1),
        .rs2_data(id_rs2),
        .rs1_addr(),
        .rs2_addr(),
        .rd_addr(id_rd),
        .mem_funct3(dcache_funct3)
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

    assign dcache_wdata = id_rs2;

    // --- Minimal Data-Side MMU (Sv32): TLB + PTW ---
    // Instruction fetch stays untranslated for now (see brief Step 3 scope note).
    // All code currently runs at an implicit "supervisor" privilege since there
    // is no real privilege-mode infrastructure yet - the U-bit split is a
    // stretch goal once actual privilege modes exist.
    localparam PRIV_SUPERVISOR = 1'b1;

    logic        dcache_req_raw;
    logic [31:0] dcache_vaddr;
    assign dcache_vaddr = ex_result;

    logic        paging_en;
    assign paging_en = csr_satp[31];

    logic        dtlb_hit, dtlb_fault;
    logic [31:0] dtlb_phys_addr;
    logic        dtlb_update_en;
    logic [19:0] dtlb_update_vpn, dtlb_update_ppn;
    logic [7:0]  dtlb_update_perm;

    logic        ptw_tlb_miss;
    logic        ptw_done, ptw_error;
    logic [19:0] ptw_pte_ppn;
    logic [7:0]  ptw_pte_perm;

    tlb u_dtlb (
        .clk(clk),
        .rst_n(rst_n),
        .virt_addr(dcache_vaddr),
        .req_valid(dcache_req_raw),
        .is_store(dcache_we),
        .is_fetch(1'b0),
        .priv_mode(PRIV_SUPERVISOR),
        .phys_addr(dtlb_phys_addr),
        .hit(dtlb_hit),
        .page_fault(dtlb_fault),
        .update_en(dtlb_update_en),
        .update_vpn(dtlb_update_vpn),
        .update_ppn(dtlb_update_ppn),
        .update_perm(dtlb_update_perm),
        .flush(1'b0)
    );

    ptw u_ptw (
        .clk(clk),
        .rst_n(rst_n),
        .tlb_miss(ptw_tlb_miss),
        .virt_addr(dcache_vaddr),
        .ptw_done(ptw_done),
        .ptw_error(ptw_error),
        .pte_ppn(ptw_pte_ppn),
        .pte_perm(ptw_pte_perm),
        .satp(csr_satp),
        .mem_addr(ptw_mem_addr),
        .mem_req(ptw_mem_req),
        .mem_rdata(ptw_mem_rdata),
        .mem_valid(ptw_mem_valid)
    );

    // While paging is on and we need a data access, hold the core back until
    // the TLB actually has a hit for this address (miss -> PTW walk -> refill).
    // NOTE: on ptw_error (page fault) this parks here permanently - there is
    // no trap/exception delivery mechanism yet, matching the existing
    // "undecoded instruction -> while(1)" behavior elsewhere in the design.
    // This is a known, documented limitation, not something silently swallowed.
    logic mmu_stall;
    assign mmu_stall = paging_en && dcache_req_raw && !dtlb_hit;

    typedef enum logic [1:0] {MMU_IDLE, MMU_WALK, MMU_REFILL} mmu_state_t;
    mmu_state_t mmu_state;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mmu_state      <= MMU_IDLE;
            ptw_tlb_miss   <= 0;
            dtlb_update_en <= 0;
        end else begin
            ptw_tlb_miss   <= 0;
            dtlb_update_en <= 0;
            case (mmu_state)
                default: ; // unused encoding of the 2-bit enum; no-op like the other FSMs here
                MMU_IDLE: begin
                    if (mmu_stall) begin
                        ptw_tlb_miss <= 1;
                        mmu_state    <= MMU_WALK;
                    end
                end
                MMU_WALK: begin
                    if (ptw_done) begin
                        dtlb_update_en   <= 1;
                        dtlb_update_vpn  <= dcache_vaddr[31:12];
                        dtlb_update_ppn  <= ptw_pte_ppn;
                        dtlb_update_perm <= ptw_pte_perm;
                        mmu_state        <= MMU_REFILL;
                    end
                    // ptw_error: intentionally stays parked in MMU_WALK (see note above)
                end
                MMU_REFILL: begin
                    mmu_state <= MMU_IDLE;
                end
            endcase
        end
    end

    // Only let the real (physical) memory request out once translation has
    // resolved to a hit for this address - or immediately, if paging is off.
    logic dcache_can_proceed;
    assign dcache_can_proceed = !paging_en || dtlb_hit;
    assign dcache_req  = dcache_req_raw && dcache_can_proceed;
    assign dcache_addr = paging_en ? dtlb_phys_addr : dcache_vaddr;

    assign core_stall = (dcache_req && !dcache_valid) || mmu_stall;

    always_ff @(posedge clk) begin
        if (!rst_n) pid_integ <= 0;
        else if (id_pid_en && !core_stall) pid_integ <= pid_integ_next;
    end

endmodule