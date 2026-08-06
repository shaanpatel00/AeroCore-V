module l2_controller (
    input  logic        clk,
    input  logic        rst_n,

    // L1 Interface (Client)
    input  logic [31:0] l1_addr,
    input  logic [31:0] l1_wdata,
    input  logic        l1_req,
    input  logic        l1_we,
    output logic [31:0] l1_rdata,
    output logic        l1_valid,

    // Main Memory / IO Interface
    output logic [31:0] mem_addr,
    output logic [31:0] mem_wdata,
    output logic        mem_req,
    output logic        mem_we,
    input  logic [31:0] mem_rdata,
    input  logic        mem_gnt    // Data Valid from RAM/IO
);

    // --- Configuration ---
    localparam WAYS = 4;
    localparam SETS = 128; // Larger than L1
    localparam INDEX_BITS = 7;
    localparam TAG_BITS = 23;

    logic [INDEX_BITS-1:0] index;
    logic [TAG_BITS-1:0]   tag_in;
    
    assign index  = l1_addr[8:2];
    assign tag_in = l1_addr[31:9];

    // --- Memory Arrays (4 Ways) ---
    logic [31:0] data_out [0:3];
    logic [TAG_BITS-1:0] tag_out [0:3];
    logic        valid_bit [0:3];
    
    logic way_we [0:3];
    logic [31:0] way_wdata;
    logic [TAG_BITS-1:0] way_tag_wdata;

    genvar i;
    generate
        for (i = 0; i < WAYS; i++) begin : ways
            // Data RAM
            cache_mem #(.DATA_WIDTH(32), .DEPTH(SETS)) data_store (
                .clk(clk), .we(way_we[i]), .addr(index), 
                .wdata(way_wdata), .rdata(data_out[i])
            );
            // Tag RAM (Assuming separate valid bit register for simplicity below)
            cache_mem #(.DATA_WIDTH(TAG_BITS), .DEPTH(SETS)) tag_store (
                .clk(clk), .we(way_we[i]), .addr(index), 
                .wdata(way_tag_wdata), .rdata(tag_out[i])
            );
        end
    endgenerate

    // Valid Bits and LRU Matrix
    // True LRU for 4-way requires a 6-bit triangular matrix per set.
    // [0]: Way 0 vs 1, [1]: 0 vs 2, [2]: 0 vs 3, [3]: 1 vs 2, [4]: 1 vs 3, [5]: 2 vs 3
    logic [SETS-1:0][3:0] valid_array; // 4 bits per set
    logic [SETS-1:0][5:0] lru_matrix;  // 6 bits per set

    // --- Hit Detection ---
    logic [3:0] hit_vector;
    logic       hit;
    logic [1:0] hit_way; // Encoded way index
    logic [31:0] hit_data;

    always_comb begin
        hit = 0;
        hit_way = 0;
        hit_vector = 0;
        hit_data = 0;
        for (int w = 0; w < WAYS; w++) begin
            if (valid_array[index][w] && (tag_out[w] == tag_in)) begin
                hit = 1;
                hit_vector[w] = 1;
                hit_way = w[1:0];
                hit_data = data_out[w];
            end
        end
    end

    // --- LRU Logic ---
    // Update: When a way is accessed, update the bits to mark it "newer" than others.
    // Replacement: Find the way that is "older" than all others.
    logic [1:0] victim_way;
    
    // Victim Selection Logic (Triangular Matrix Decode)
    always_comb begin
        // Checks which way is 'older' (0) in all comparisons involving it
        // Logic simplified for brevity; standard hardware algorithm
        if (!lru_matrix[index][0] && !lru_matrix[index][1] && !lru_matrix[index][2]) victim_way = 0;
        else if (lru_matrix[index][0] && !lru_matrix[index][3] && !lru_matrix[index][4]) victim_way = 1;
        else if (lru_matrix[index][1] && lru_matrix[index][3] && !lru_matrix[index][5]) victim_way = 2;
        else victim_way = 3;
    end

    // --- State Machine ---
    typedef enum logic [1:0] { IDLE, CHECK, REFILL, IO_BYPASS } l2_state_t;
    l2_state_t state, next_state;

    // cache_mem's read output lags its write by one cycle (no forwarding).
    // valid_array must lag the SAME way, or CHECK can see a "valid" way whose
    // tag_out/data_out haven't actually updated yet (false hit on stale/zero data).
    // victim_way/index must also be LATCHED at the moment of the write, since
    // they're combinational and the LRU matrix update (same trigger) can shift
    // victim_way before the delayed valid-bit update fires.
    logic                    refill_committed_d1;
    logic [INDEX_BITS-1:0]   refill_index_d1;
    logic [1:0]              refill_way_d1;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            valid_array <= '0;
            lru_matrix <= '0;
            refill_committed_d1 <= 0;
            refill_index_d1 <= '0;
            refill_way_d1 <= '0;
        end else begin
            state <= next_state;
            refill_committed_d1 <= (state == REFILL && mem_gnt);
            if (state == REFILL && mem_gnt) begin
                refill_index_d1 <= index;
                refill_way_d1   <= victim_way;
            end
            
            // Update LRU on Hit or Refill
            if ((state == CHECK && hit) || (state == REFILL && mem_gnt)) begin
                logic [1:0] acc_way;
                acc_way = (state == CHECK) ? hit_way : victim_way;
                
                if (acc_way == 0) begin lru_matrix[index][0]<=1; lru_matrix[index][1]<=1; lru_matrix[index][2]<=1; end
                if (acc_way == 1) begin lru_matrix[index][0]<=0; lru_matrix[index][3]<=1; lru_matrix[index][4]<=1; end
                if (acc_way == 2) begin lru_matrix[index][1]<=0; lru_matrix[index][3]<=0; lru_matrix[index][5]<=1; end
                if (acc_way == 3) begin lru_matrix[index][2]<=0; lru_matrix[index][4]<=0; lru_matrix[index][5]<=0; end
            end

            // Update Valid Bits one cycle after Refill, matching cache_mem's read latency.
            // Use the LATCHED index/way, not the live (possibly already-shifted) values.
            if (refill_committed_d1) begin
                valid_array[refill_index_d1][refill_way_d1] <= 1;
            end
        end
    end

    always_comb begin
        next_state = state;
        way_we = '{0,0,0,0};
        way_wdata = 0;
        way_tag_wdata = 0;
        
        l1_valid = 0;
        l1_rdata = hit_data;
        
        mem_req = 0;
        mem_we = 0;
        mem_addr = l1_addr;
        mem_wdata = l1_wdata;

        case (state)
            IDLE: begin
                if (l1_req) begin
                    // IO bypass check (e.g. 0x4000...)
                    if (l1_addr[31:16] == 16'h4000) next_state = IO_BYPASS;
                    else next_state = CHECK;
                end
            end

            CHECK: begin
                if (hit) begin
                    l1_valid = 1;
                    if (l1_we) begin
                        // Write Hit
                        way_we[hit_way] = 1;
                        way_wdata = l1_wdata;
                        way_tag_wdata = tag_in;
                        // Write-through to Mem? Or Write-Back? 
                        // Using Write-Through for simple Flight Controller reliability
                        mem_req = 1; 
                        mem_we = 1;
                    end
                    next_state = IDLE;
                end else begin
                    // MISS
                    next_state = REFILL;
                end
            end

            REFILL: begin
                mem_req = 1;
                mem_we = 0; // Read
                if (mem_gnt) begin
                    // Write to Victim Way
                    way_we[victim_way] = 1;
                    way_wdata = mem_rdata;
                    way_tag_wdata = tag_in;
                    next_state = CHECK; // Re-check to serve to L1
                end
            end

            IO_BYPASS: begin
                mem_req = 1;
                mem_we = l1_we;
                if (mem_gnt) begin
                    l1_rdata = mem_rdata;
                    l1_valid = 1;
                    next_state = IDLE;
                end
            end
        endcase
    end

endmodule