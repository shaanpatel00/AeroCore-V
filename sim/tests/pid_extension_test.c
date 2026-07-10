#include <stdint.h>

// Define the custom instruction using RISC-V .insn directive
// Format: R-type instruction
// Opcode: 0x0B, funct3: 0x0, funct7: 0x00
// custom_pid rd, rs1, rs2
#define CUSTOM_PID_CALC(rd, error, prev_error) \
    __asm__ volatile ( \
        ".insn r 0x0B, 0, 0, %0, %1, %2" \
        : "=r" (rd) \
        : "r" (error), "r" (prev_error) \
    )

int main() {
    int32_t current_error = 150;
    int32_t previous_error = 100;
    int32_t pid_output;
    
    // In hardware, the ALU will multiply these by pre-configured 
    // Kp, Ki, and Kd coefficients inside alu_pid.sv.
    // For this test, we assume Kp=2, Kd=1, Ki=0 for a known mock result:
    // Output = (150 * 2) + ((150 - 100) * 1) = 300 + 50 = 350
    int32_t expected_output = 350;

    // Execute the custom hardware instruction
    CUSTOM_PID_CALC(pid_output, current_error, previous_error);

    // Verify the hardware calculated the correct result in 1 cycle
    if (pid_output == expected_output) {
        return 0; // PASS
    } else {
        return 1; // FAIL
    }
}
