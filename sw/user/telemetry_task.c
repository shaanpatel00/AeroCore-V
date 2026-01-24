#include <stdint.h>

// --- System Definitions (Replicated from kernel/riscv_asm.h) ---
#define MMIO_BASE       0x40000000
// UART TX Register (Assuming mapped at offset 0x200 in soc_top.sv)
#define UART_TX_REG     (*((volatile uint32_t*)(MMIO_BASE + 0x200)))
#define UART_STATUS_REG (*((volatile uint32_t*)(MMIO_BASE + 0x204)))

// --- Global State Access (Externs from kernel/pid.c) ---
extern volatile int32_t current_alt; // Q16.16 format
extern volatile int32_t prev_error;  // Q16.16 format

// --- Helper Functions ---

/**
 * @brief Simple busy-wait write character to UART
 */
void uart_putc(char c) {
    // In a real hardware implementation, check TX_READY bit here
    // while((UART_STATUS_REG & 0x1) == 0); 
    UART_TX_REG = c;
}

/**
 * @brief Prints a null-terminated string
 */
void uart_puts(const char* str) {
    while (*str) {
        uart_putc(*str++);
    }
}

/**
 * @brief Prints a 32-bit integer as Hexadecimal
 */
void uart_print_hex(uint32_t val) {
    uart_puts("0x");
    for (int i = 28; i >= 0; i -= 4) {
        uint32_t nibble = (val >> i) & 0xF;
        if (nibble < 10) uart_putc('0' + nibble);
        else             uart_putc('A' + (nibble - 10));
    }
}

/**
 * @brief Converts Q16.16 fixed point to decimal string (e.g., "50.25")
 */
void uart_print_fixed(int32_t val) {
    // Integer part
    int32_t integer = val >> 16;
    
    // Fractional part (approximate for display)
    // Mask lower 16 bits, multiply by 100, divide by 65536
    uint32_t frac = (val & 0xFFFF);
    uint32_t frac_dec = (frac * 100) / 65536;

    // Handle negative
    if (val < 0) {
        uart_putc('-');
        integer = -integer;
    }

    // Print Integer
    // Simple itoa (up to 3 digits for this drone)
    if (integer >= 100) uart_putc('0' + (integer / 100) % 10);
    if (integer >= 10)  uart_putc('0' + (integer / 10) % 10);
    uart_putc('0' + (integer % 10));

    uart_putc('.');

    // Print Fraction (2 decimal places)
    if (frac_dec < 10) uart_putc('0');
    if (frac_dec >= 10) uart_putc('0' + (frac_dec / 10));
    uart_putc('0' + (frac_dec % 10));
}

// --- Main Task ---

/**
 * @brief Telemetry Task
 * Called by the scheduler in sw/kernel/sched.c
 * * Logic:
 * 1. Read global system state (Altitude, Error).
 * 2. Format into a human-readable string.
 * 3. Send via UART.
 */
void telemetry_task(void) {
    // 1. Header
    uart_puts("[TEL] Alt: ");

    // 2. Altitude (Fixed Point)
    uart_print_fixed(current_alt);
    uart_puts(" m | Err: ");

    // 3. Error (Fixed Point)
    uart_print_fixed(prev_error);
    
    // 4. Status Check
    // Thresholds: < 1m (Grounded), > 45m (Target reached)
    int32_t alt_int = current_alt >> 16;
    if (alt_int < 1) {
        uart_puts(" | STATUS: GROUND");
    } else if (alt_int > 45) {
        uart_puts(" | STATUS: HOVER");
    } else {
        uart_puts(" | STATUS: ASCENT");
    }

    uart_puts("\r\n");
}