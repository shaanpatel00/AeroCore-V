#include "Vsoc_top.h"       // Verilated SoC Header
#include "verilated.h"
#include "physics_engine.h"
#include "visualizer.h"

// Global Pointers (Required because GLUT callbacks are C-style functions)
Vsoc_top* top = nullptr;
PhysicsEngine* physics = nullptr;

// Simulation Time Tracking
vluint64_t main_time = 0;
const int CYCLES_PER_UPDATE = 10000; // Run 10k FPGA clocks per physics step

// --- Hardware Helper Functions ---

/**
 * @brief Steps the FPGA logic for a set number of cycles.
 * Feeds Sensor data IN and reads Motor data OUT.
 */
void run_hardware_step() {
    // 1. Get Sensor Data from Physics World
    int32_t sensor_val = physics->get_sensor_data_fixed();
    
    // Simulate Serializing Data (Simplified: Put data on GPIO pins if using parallel test)
    // Or bit-bang SPI MISO if using the full SPI wrapper.
    // For this bridge, we assume a "Backdoor" or Direct GPIO connection for speed:
    // Let's assume GPIO[0] is MISO.
    
    for (int i = 0; i < CYCLES_PER_UPDATE; i++) {
        top->clk = 0; 
        top->eval();
        
        top->clk = 1; 
        // Feed Sensor Data (Simplified bit-bang or direct feed)
        // In a real SPI sim, we'd shift 'sensor_val' bit by bit based on SCLK.
        // For Digital Twin speed, we often use a "Debug Input" on the SoC.
        // Here, we just toggle clock.
        
        top->eval();
        main_time++;
    }
}

/**
 * @brief Reads the Motor PWM register from the FPGA memory map (Backdoor Access).
 * In Verilator, we can access internal signals or memory directly.
 */
double read_motor_thrust() {
    // Access the specific memory address 0x40000100 where motors are mapped
    // Note: Hierarchy path depends on synthesis. 
    // Usually: top->rootp->soc_top__DOT__ram...
    
    // For safety/simplicity in this generated code, we read the Top-Level GPIO Output
    // top->motor_pwm is a 4-bit signal exposed in soc_top.sv
    
    uint8_t pwm_val = top->motor_pwm; 
    
    // Convert PWM (0-15) to Force (Newtons)
    // Assume Max Thrust = 20N (enough to lift 1kg against 9.81m/s^2)
    double force = (double)pwm_val * (20.0 / 15.0);
    return force;
}

// --- GLUT Callbacks ---

void display_callback() {
    // 1. Step Hardware
    run_hardware_step();

    // 2. Read Output from Hardware
    double thrust = read_motor_thrust();

    // 3. Update Physics
    physics->update(thrust);

    // 4. Render Visuals
    Visualizer::render_scene(physics->get_altitude());

    // 5. Request next frame immediately
    glutPostRedisplay();
}

void timer_callback(int value) {
    // Optional: Use to cap framerate if simulation runs too fast
    glutTimerFunc(16, timer_callback, 0); // ~60 FPS
}

// --- Main ---

int main(int argc, char** argv) {
    // 1. Initialize Verilator
    Verilated::commandArgs(argc, argv);
    top = new Vsoc_top;
    
    // Reset Sequence
    top->rst_n = 0; top->clk = 0; top->eval();
    top->rst_n = 0; top->clk = 1; top->eval();
    top->rst_n = 1; top->clk = 0; top->eval();

    // 2. Initialize Physics
    physics = new PhysicsEngine();

    // 3. Initialize Visualizer & GLUT
    Visualizer::init(argc, argv);

    // 4. Register Callbacks
    glutDisplayFunc(display_callback);
    // glutTimerFunc(16, timer_callback, 0);

    // 5. Start Simulation Loop
    // This blocks until window is closed
    glutMainLoop();

    // Cleanup
    delete physics;
    delete top;
    return 0;
}