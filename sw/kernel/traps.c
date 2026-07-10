#include "riscv_asm.h"

void handle_trap(uint32_t mcause, uint32_t mepc) {
    int is_interrupt = (mcause & 0x80000000);
    int cause_code   = (mcause & 0x7FFFFFFF);
    
    if (is_interrupt) {
        switch (cause_code) {
            case 7: // Machine Timer Interrupt
                break;
            default:
                break;
        }
    } else {
        switch (cause_code) {
            case 12: // Instruction Page Fault
            case 13: // Load Page Fault
            case 15: // Store Page Fault
                while(1) { MOTOR_PWM_REG = 0; } // Kill motors
                break;
            case 2: // Illegal Instruction
                while(1); 
                break;
            default:
                while(1);
        }
    }
} // <-- Added