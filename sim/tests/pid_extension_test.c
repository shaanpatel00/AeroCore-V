#include <stdint.h>
#define UART_TX_REG     (*(volatile uint32_t*)(0x40000200))
#define UART_STATUS_REG (*(volatile uint32_t*)(0x40000208))
#define TX_READY_BIT    0x1

void uart_send(uint32_t c) {
    while (!(UART_STATUS_REG & TX_READY_BIT));
    UART_TX_REG = c;
}

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
    int32_t current_error = 0x00010000;  // 1.0 in Q16.16
    int32_t previous_error = 0x00008000; // 0.5 in Q16.16
    int32_t pid_output;
    
    // Hardware CSR defaults (set in riscv_core.sv): Kp=5.0, Ki=0.3, Kd=2.5 (Q16.16)
    // P = 1.0*5.0=5.0 | I = (1.0*dt)*0.3=0.3 | D = (1.0-0.5)*2.5=1.25
    // Output = 5.0 + 0.3 + 1.25 = 6.550048828125 (Q16.16)
    int32_t expected_output = 0x00068CCC;

    // Execute the custom hardware instruction
    CUSTOM_PID_CALC(pid_output, current_error, previous_error);

    // Verify the hardware calculated the correct result in 1 cycle
    if (pid_output == expected_output) {
        uart_send(0xFF); // PASS
        return 0;
    } else {
        uart_send(0xEE); // FAIL
        return 1;
    }
}
