#include "riscv_asm.h"

extern void pid_task(void);
extern void telemetry_task(void);

// Task Control Block
typedef struct {
    uint32_t *stack_ptr;
    int state; // 0=Ready, 1=Running, 2=Blocked
} tcb_t;

// Globals
volatile uint32_t tick_count = 0;

/**
 * @brief Main Kernel Entry Point
 * Called by bootloader (start.S)
 */
void main(void) {
    // 1. Initialize Peripherals
    MOTOR_PWM_REG = 0; // Motors off
    
    // 2. Initialize Interrupts (Timer)
    // For this simple SoC, we might just poll or rely on Verilator ticks.
    // enable_interrupts(); 

    // 3. The "Super Loop" Scheduler
    // Reliable, deterministic, low-jitter.
    while (1) {
        // Run Flight Control (Highest Priority)
        pid_task();

        // Run Telemetry (Best Effort)
        // In a real RTOS, this would be time-sliced. 
        // Here we run it every 100 loops or simply run a quick check.
        if (tick_count % 100 == 0) {
            telemetry_task();
        }

        // Wait/Delay logic would go here to maintain 100Hz/400Hz loop time
        // Simple busy wait for simulation stability
        for (volatile int i = 0; i < 100; i++);
        
        tick_count++;
    }
}