#include "riscv_asm.h"

extern void pid_task(void);
extern void telemetry_task(void);
extern void mmu_init(void);

#define NUM_TASKS  2
#define PRIO_HIGH  0
#define PRIO_LOW   1

typedef struct {
    void (*task_fn)(void);
    uint32_t period_ticks; // Run every N ticks
    uint32_t priority;     // Lower number = higher priority
    uint32_t last_run;
} tcb_t;

volatile uint32_t tick_count = 0;

tcb_t task_table[NUM_TASKS] = {
    { pid_task,       1,   PRIO_HIGH, 0 }, // Flight control: every tick
    { telemetry_task, 100, PRIO_LOW,  0 }, // Telemetry: every 100 ticks
};

void scheduler_run(void) {
    // Scan tasks in priority order (0 = highest). Run any task whose
    // period has elapsed, highest priority first.
    for (uint32_t prio = PRIO_HIGH; prio <= PRIO_LOW; prio++) {
        for (int i = 0; i < NUM_TASKS; i++) {
            if (task_table[i].priority == prio &&
                (tick_count - task_table[i].last_run) >= task_table[i].period_ticks) {
                task_table[i].task_fn();
                task_table[i].last_run = tick_count;
            }
        }
    }
}

void main(void) {
    mmu_init();      // Enable Sv32 paging before anything else runs
    MOTOR_PWM_REG = 0; // Motors off

    while (1) {
        scheduler_run();
        for (volatile int i = 0; i < 100; i++); // Simple busy wait
        tick_count++;
    }
}