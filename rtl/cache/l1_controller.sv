module l1_controller (
    input  logic        clk,
    input  logic        rst_n,

    // CPU Interface
    input  logic [31:0] cpu_addr,
    input  logic [31:0] cpu_wdata,
    input  logic        cpu_req,    // Valid request
    input  logic        cpu_we,     // Write Enable
    output logic [31:0] cpu_rdata,
    output logic        cpu_valid,  // Data ready (Hit or Refill complete)

    // L2 Interface
    output logic [31:0] l2_addr,
    output logic [31:0] l2_wdata,
    output logic        l2_req,
    output logic        l2_we,
    input  logic [31:0] l2_rdata,
    input  logic        l2_valid
);

    // --- Configuration ---
    // 4KB Cache: 64 Sets, 64-byte lines (simplified to 32-bit words for this demo)
    // To match your "Lab 2" simplicity, we assume 1 word per line for easy logic,
    // but standard caches use wider lines. Sticking to 1-word lines (32-bit) for readability.
    
    localparam SETS = 64;
    localparam INDEX_BITS = 6;  // log2(64)
    localparam TAG_BITS = 24;   // 32 - 6 - 2 (byte offset)

    // --- Signals ---
    logic [INDEX_BITS-1:0] index;
    logic [TAG_BITS-1:0]   tag_in;
    logic [TAG_BITS-1:0]   tag_read;
    logic                  valid_bit_read;
    logic [31:0]           data_read;
    
    // RAM Control
    logic ram_we;
    logic [31:0] ram_wdata;
    logic [TAG_BITS:0] tag_wdata; // Tag + Valid Bit

    assign index  = cpu_addr[7:2];
    assign tag_in = cpu_addr[31:8];

    // IO Region Detection (Bypass Cache for 0x4000_XXXX)
    logic is_io;
    assign is_io = (cpu_addr[31:16] == 16'h4000);

    // --- State Machine ---
    typedef enum logic [1:0] {
        IDLE,
        COMPARE,
        ALLOCATE,
        IO_ACCESS
    } state_t;
    state_t state, next_state;

    // --- RAM Instantiation ---
    // Data RAM
    cache_mem #(.DATA_WIDTH(32), .DEPTH(SETS)) data_ram (
        .clk(clk),
        .we(ram_we),
        .addr(index),
        .wdata(ram_wdata),
        .rdata(data_read)
    );

    // Tag RAM (Stores Tag + 1 Valid Bit)
    cache_mem #(.DATA_WIDTH(TAG_BITS+1), .DEPTH(SETS)) tag_ram (
        .clk(clk),
        .we(ram_we),
        .addr(index),
        .wdata(tag_wdata),
        .rdata({valid_bit_read, tag_read})
    );

    // --- FSM ---
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) state <= IDLE;
        else        state <= next_state;
    end

    always_comb begin
        next_state = state;
        ram_we = 0;
        ram_wdata = 0;
        tag_wdata = 0;
        
        // Outputs
        cpu_valid = 0;
        cpu_rdata = data_read;
        
        // L2 Interface Defaults
        l2_req = 0;
        l2_we  = 0;
        l2_addr = cpu_addr;
        l2_wdata = cpu_wdata;

        case (state)
            IDLE: begin
                if (cpu_req) begin
                    if (is_io) next_state = IO_ACCESS;
                    else       next_state = COMPARE;
                end
            end

            COMPARE: begin
                // Check Hit
                if (valid_bit_read && (tag_read == tag_in)) begin
                    // HIT
                    cpu_valid = 1;
                    
                    if (cpu_we) begin
                        // Write-Through to L2 (Simple policy)
                        // Also update L1
                        ram_we = 1;
                        ram_wdata = cpu_wdata;
                        tag_wdata = {1'b1, tag_in};
                        
                        // Send to L2
                        l2_req = 1;
                        l2_we  = 1;
                    end
                    next_state = IDLE;
                end else begin
                    // MISS
                    next_state = ALLOCATE;
                end
            end

            ALLOCATE: begin
                // Request data from L2
                l2_req = 1;
                l2_we  = 0;
                
                if (l2_valid) begin
                    // Refill L1
                    ram_we = 1;
                    ram_wdata = l2_rdata;
                    tag_wdata = {1'b1, tag_in}; // Mark valid
                    
                    next_state = COMPARE; // Retry the access
                end
            end
            
            IO_ACCESS: begin
                // Bypass L1, talk directly to L2 (which talks to memory map)
                // In a real SoC, this might go to a separate Bus Bridge, 
                // but here we pipe it through L2 interface for simplicity.
                l2_req = 1;
                l2_we  = cpu_we;
                
                if (l2_valid) begin
                    cpu_rdata = l2_rdata;
                    cpu_valid = 1;
                    next_state = IDLE;
                end
            end
        endcase
    end
endmodule