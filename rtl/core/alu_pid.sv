/**
 * Custom PID ALU Extension (Opcode: Custom-0)
 * Performs: Output = (Kp*Error) + (Ki*Integral) + (Kd*(Error-Prev))
 * Optimized for Q16.16 Fixed Point Math.
 */
module alu_pid (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] error,          // rs1: Current Error
    input  logic [31:0] prev_error,     // rs2: Previous Error
    input  logic [31:0] coeff_kp,       // From CSR
    input  logic [31:0] coeff_ki,       // From CSR
    input  logic [31:0] coeff_kd,       // From CSR
    input  logic [31:0] dt_fixed,       // Time delta (Q16.16)
    
    output logic [31:0] control_out,    // Result to rd
    output logic [31:0] integ_update    // New integral to write back to CSR
);

    // Q16.16 Fixed Point Constants
    localparam MAX_OUT = 32'h00320000; // 50.0
    localparam MIN_OUT = -32'h00320000;

    logic signed [63:0] p_term, i_term, d_term;
    logic signed [63:0] integral_accum;
    logic signed [31:0] error_diff;

    always_comb begin
        // 1. Proportional Term
        p_term = $signed(error) * $signed(coeff_kp);

        // 2. Integral Term (Accumulate)
        // Simulate: integral += error * dt
        integral_accum = $signed(error) * $signed(dt_fixed);
        // Current I-term contribution
        i_term = $signed(integral_accum[47:16]) * $signed(coeff_ki); 

        // 3. Derivative Term
        // Simulate: (error - prev_error) / dt * Kd
        error_diff = $signed(error) - $signed(prev_error);
        d_term = $signed(error_diff) * $signed(coeff_kd); 

        // 4. Summation (Shift Q16 back to 32-bit register format)
        control_out = (p_term[47:16] + i_term[47:16] + d_term[47:16]);

        // 5. Output Saturation (Safety)
        if ($signed(control_out) > $signed(MAX_OUT)) control_out = MAX_OUT;
        else if ($signed(control_out) < $signed(MIN_OUT)) control_out = MIN_OUT;
        
        // Output new integral accumulator for SW to store
        integ_update = integral_accum[31:0];
    end
endmodule