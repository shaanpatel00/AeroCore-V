#include "riscv_asm.h"

extern void pid_task(void);
extern void telemetry_task(void);

typedef struct {
    uint32_t *stack_ptr;
    int state; // 0=Ready, 1=Running, 2=Blocked
} tcb_t;

volatile uint32_t tick_count = 0;

void main(void) {
    MOTOR_PWM_REG = 0; // Motors off
    
    while (1) {
        pid_task();
        
        if (tick_count % 100 == 0) {
            telemetry_task();
        }
        
        for (volatile int i = 0; i < 100; i++); // Simple busy wait
        
        tick_count++;
    }
} // <-- Added