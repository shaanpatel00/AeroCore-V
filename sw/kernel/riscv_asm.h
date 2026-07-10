#ifndef RISCV_ASM_H
#define RISCV_ASM_H
#include <stdint.h>

// --- CSR Definitions ---
#define CSR_MSTATUS     0x300
#define CSR_MIE         0x304
#define CSR_MTVEC       0x305
#define CSR_MSCRATCH    0x340
#define CSR_MEPC        0x341
#define CSR_MCAUSE      0x342
#define CSR_MTVAL       0x343
#define CSR_MIP         0x344

// --- Memory Mapped IO (Match soc_top.sv) ---
#define MMIO_BASE       0x40000000
#define SPI_DATA_REG    (*((volatile uint32_t*)(MMIO_BASE + 0x00)))
#define SPI_STATUS_REG  (*((volatile uint32_t*)(MMIO_BASE + 0x04))) 
#define MOTOR_PWM_REG   (*((volatile uint32_t*)(MMIO_BASE + 0x100)))

// --- Custom PID Instruction ---
static inline int32_t custom_pid_op(int32_t error, int32_t prev_error) {
    int32_t result;
    asm volatile(
        ".insn r 0x0B, 0, 0, %0, %1, %2"
        : "=r"(result)
        : "r"(error), "r"(prev_error)
    );
    return result;
} // <-- Added

// --- CSR Access Macros ---
#define csrw(csr, val)  asm volatile ("csrw %0, %1" :: "i"(csr), "r"(val))

#endif