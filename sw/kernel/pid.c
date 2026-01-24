#include "riscv_asm.h"

// Fixed Point Math: Q16.16
#define TO_FIXED(x) ((int32_t)((x) * 65536.0))
#define TARGET_ALT  TO_FIXED(50.0) // 50 Meters

// Global State
volatile int32_t prev_error = 0;
volatile int32_t current_alt = 0;

/**
 * @brief The Flight Control Task
 * This function is called periodically by the scheduler.
 */
void pid_task(void) {
    // 1. Read Sensor Data (Simulated SPI)
    // In simulation, physics engine writes to this address
    current_alt = SPI_DATA_REG; 

    // 2. Calculate Error
    int32_t error = TARGET_ALT - current_alt;

    // 3. HARDWARE ACCELERATION
    // Instead of ~50 cycles of soft-float or ~20 cycles of integer math,
    // this executes in 1 cycle + pipeline latency.
    // The ALU internally handles P, I, D terms and saturation.
    int32_t control_out = custom_pid_op(error, prev_error);

    // 4. Update State
    prev_error = error;

    // 5. Actuate Motors
    // Convert control output (Q16.16) to PWM (0-15)
    // Shift right by 16 to get integer part, then clamp.
    int32_t pwm = (control_out >> 16);
    
    if (pwm > 15) pwm = 15;
    if (pwm < 0)  pwm = 0;

    MOTOR_PWM_REG = pwm;
}

/**
 * @brief Telemetry Task (Lower Priority)
 * Sends debug info out via UART (Simulated)
 */
void telemetry_task(void) {
    // Determine status based on altitude
    // This runs only when PID task yields or is waiting
    if (current_alt < TO_FIXED(10.0)) {
        // Status: Takeoff
    } else if (current_alt > TO_FIXED(45.0)) {
        // Status: Hovering
    }
    // (UART code omitted for brevity)
}