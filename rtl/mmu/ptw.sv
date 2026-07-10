module ptw (
    input  logic        clk,
    input  logic        rst_n,
    
    // TLB Interface
    input  logic        tlb_miss,     // Trigger
    input  logic [31:0] virt_addr,    // Address causing miss
    output logic        ptw_done,     // Refill complete
    output logic        ptw_error,    // Access Exception
    output logic [19:0] pte_ppn,      // Result PPN
    output logic [7:0]  pte_perm,     // Result Permissions
    
    // SATP Register (Root Page Table Pointer)
    input  logic [31:0] satp,         // [31]=Mode, [21:0]=PPN
    
    // Memory Interface (Read Only for Walker)
    output logic [31:0] mem_addr,
    output logic        mem_req,
    input  logic [31:0] mem_rdata,
    input  logic        mem_valid
);
    // --- Sv32 Constants ---
    localparam PAGESIZE = 4096;
    localparam PTE_SIZE = 4;

    // --- State Machine ---
    typedef enum logic [2:0] {
        IDLE,
        LEVEL1_REQ,  // Fetch L1 PTE
        LEVEL1_WAIT, // Wait for L1 Data
        LEVEL0_REQ,  // Fetch L0 PTE (Leaf)
        LEVEL0_WAIT, // Wait for L0 Data
        DONE,
        ERROR
    } state_t;
    
    state_t state, next_state;

    // --- VPN Extraction ---
    logic [9:0] vpn1;
    logic [9:0] vpn0;
    assign vpn1 = virt_addr[31:22];
    assign vpn0 = virt_addr[21:12];

    // --- Holding Registers ---
    logic [31:0] pte_l1; // Level 1 Page Table Entry
    logic [31:0] pte_l0; // Level 0 Page Table Entry

    // --- FSM Logic ---
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) state <= IDLE;
        else        state <= next_state;
    end
    
    // Data Capture
    always_ff @(posedge clk) begin
        if (state == LEVEL1_WAIT && mem_valid) pte_l1 <= mem_rdata;
        if (state == LEVEL0_WAIT && mem_valid) pte_l0 <= mem_rdata;
    end

    always_comb begin
        next_state = state;
        ptw_done = 0;
        ptw_error = 0;
        mem_req = 0;
        mem_addr = 0;
        pte_ppn = 0;
        pte_perm = 0;
        
        case (state)
            IDLE: begin
                if (tlb_miss && satp[31]) begin // Only walk if Paging Enabled (Mode=1)
                    next_state = LEVEL1_REQ;
                end
            end
            
            // --- Level 1 Walk (Root) ---
            LEVEL1_REQ: begin
                // Addr = (satp.ppn * PAGESIZE) + (vpn1 * PTE_SIZE)
                mem_addr = {satp[21:0], 12'b0} + {20'b0, vpn1, 2'b00};
                mem_req = 1;
                next_state = LEVEL1_WAIT;
            end
            
            LEVEL1_WAIT: begin
                if (mem_valid) begin
                    // Check Valid Bit (bit 0) and Read/Write/Execute (bits 3:1)
                    if (!mem_rdata[0]) begin
                        next_state = ERROR; // Invalid PTE
                    end else if (!(mem_rdata[1] || mem_rdata[2] || mem_rdata[3])) begin
                        // Pointer to next level
                        next_state = LEVEL0_REQ;
                    end else begin
                        // Mega-page (Leaf at L1 - simplified handling)
                        next_state = DONE;
                    end
                end
            end

            // --- Level 0 Walk (Leaf) ---
            LEVEL0_REQ: begin
                // Addr = (pte_l1.ppn * PAGESIZE) + (vpn0 * PTE_SIZE)
                mem_addr = {pte_l1[29:10], 12'b0} + {20'b0, vpn0, 2'b00};
                mem_req = 1;
                next_state = LEVEL0_WAIT;
            end

            LEVEL0_WAIT: begin
                if (mem_valid) begin
                    if (!mem_rdata[0]) begin
                        next_state = ERROR;
                    end else begin
                        next_state = DONE;
                    end
                end
            end

            DONE: begin
                ptw_done = 1;
                pte_ppn = (state == LEVEL0_WAIT) ? pte_l0[29:10] : pte_l1[29:10]; 
                pte_perm = (state == LEVEL0_WAIT) ? pte_l0[7:0] : pte_l1[7:0];
                next_state = IDLE;
            end

            ERROR: begin
                ptw_error = 1;
                next_state = IDLE;
            end
        endcase
    end
endmodule