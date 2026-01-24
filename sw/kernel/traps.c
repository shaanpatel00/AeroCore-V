#include "riscv_asm.h"

/**
 * @brief C-level Trap Handler
 * Called by the assembly vector table (not shown, usually in start.S)
 */
void handle_trap(uint32_t mcause, uint32_t mepc) {
    // Check if it's an Interrupt (Async) or Exception (Sync)
    int is_interrupt = (mcause & 0x80000000);
    int cause_code   = (mcause & 0x7FFFFFFF);

    if (is_interrupt) {
        switch (cause_code) {
            case 7: // Machine Timer Interrupt
                // Acknowledge Timer
                // Trigger Scheduler switch if using Preemption
                break;
            default:
                break;
        }
    } else {
        // Exception
        switch (cause_code) {
            case 12: // Instruction Page Fault
            case 13: // Load Page Fault
            case 15: // Store Page Fault
                // MMU Error!
                // 1. Read bad address
                // uint32_t bad_addr = csrr(CSR_MTVAL);
                // 2. If it's a stack growth issue, handle it.
                // 3. Otherwise, PANIC.
                while(1) { MOTOR_PWM_REG = 0; } // Kill motors
                break;
                
            case 2: // Illegal Instruction
                // Could be our Custom Instruction if not enabled?
                while(1); 
                break;
                
            default:
                while(1);
        }
    }
    
    // Return handled (assembly wrapper will execute mret)
}