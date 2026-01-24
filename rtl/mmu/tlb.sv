module tlb (
    input  logic        clk,
    input  logic        rst_n,
    
    // Core Interface (Request)
    input  logic [31:0] virt_addr,
    input  logic        req_valid,
    input  logic        is_store,    // 1=Write, 0=Read
    input  logic        is_fetch,    // 1=Instruction Fetch
    input  logic        priv_mode,   // 0=User, 1=Supervisor
    
    // Core Interface (Response)
    output logic [31:0] phys_addr,
    output logic        hit,
    output logic        page_fault,
    
    // PTW Interface (Refill)
    input  logic        update_en,
    input  logic [19:0] update_vpn,
    input  logic [19:0] update_ppn,
    input  logic [7:0]  update_perm, // RISC-V PTE bits (DAGUXWRV)
    
    // Management
    input  logic        flush        // SFENCE.VMA
);

    // --- Configuration ---
    // 16-Entry Fully Associative (Small but fast for Flight Control)
    localparam TLB_ENTRIES = 16;
    
    // --- Storage ---
    logic [19:0] vpn_cam [0:TLB_ENTRIES-1];
    logic [19:0] ppn_ram [0:TLB_ENTRIES-1];
    logic [7:0]  perm_ram [0:TLB_ENTRIES-1]; // R, W, X, U, G, A, D, V
    logic [TLB_ENTRIES-1:0] valid;
    
    // --- Lookup Logic ---
    logic [TLB_ENTRIES-1:0] match_vec;
    logic [3:0] match_idx;
    logic match_found;
    
    // Extract VPN/Offset
    logic [19:0] req_vpn;
    logic [11:0] req_offset;
    assign req_vpn    = virt_addr[31:12];
    assign req_offset = virt_addr[11:0];

    // CAM Search
    always_comb begin
        match_vec = 0;
        match_found = 0;
        match_idx = 0;
        
        for (int i = 0; i < TLB_ENTRIES; i++) begin
            if (valid[i] && (vpn_cam[i] == req_vpn)) begin
                match_vec[i] = 1;
                match_found = 1;
                match_idx = i[3:0];
            end
        end
    end
    
    assign hit = match_found;

    // --- Permission Check (Sv32) ---
    // PTE Bits: [7]D, [6]A, [5]G, [4]U, [3]X, [2]W, [1]R, [0]V
    logic [7:0] active_perm;
    logic       perm_ok;
    
    assign active_perm = perm_ram[match_idx];
    
    always_comb begin
        perm_ok = 1;
        
        // 1. Valid Check (Implicit in hit, but good for safety)
        if (!active_perm[0]) perm_ok = 0;
        
        // 2. Privilege Check (User accessing Supervisor page)
        // bit [4] is U-bit. If U=0, User cannot access.
        if (priv_mode == 0 && active_perm[4] == 0) perm_ok = 0;
        
        // 3. Supervisor Accessing User Page (Assuming SUM=0 for safety)
        if (priv_mode == 1 && active_perm[4] == 1) perm_ok = 0;
        
        // 4. Access Type Check
        if (is_fetch && !active_perm[3]) perm_ok = 0;      // Not Executable
        if (is_store && !active_perm[2]) perm_ok = 0;      // Not Writable
        if (!is_store && !is_fetch && !active_perm[1]) perm_ok = 0; // Not Readable
    end

    // --- Output Generation ---
    always_comb begin
        if (hit && perm_ok) begin
            phys_addr  = {ppn_ram[match_idx], req_offset};
            page_fault = 0;
        end else if (hit && !perm_ok) begin
            phys_addr  = 32'b0;
            page_fault = 1; // Protection Fault
        end else begin
            phys_addr  = 32'b0;
            page_fault = 0; // Miss (Core should trigger PTW)
        end
    end

    // --- Replacement & Refill ---
    // Simple Round-Robin Replacement
    logic [3:0] replace_ptr;
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            valid <= 0;
            replace_ptr <= 0;
        end else if (flush) begin
            valid <= 0;
            replace_ptr <= 0;
        end else if (update_en) begin
            vpn_cam[replace_ptr]  <= update_vpn;
            ppn_ram[replace_ptr]  <= update_ppn;
            perm_ram[replace_ptr] <= update_perm;
            valid[replace_ptr]    <= 1;
            replace_ptr <= replace_ptr + 1;
        end
    end

endmodule