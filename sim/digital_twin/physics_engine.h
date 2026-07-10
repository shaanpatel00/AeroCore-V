#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

#include <stdint.h>

class PhysicsEngine {
private:
    // State
    double z_pos;       // Altitude (meters)
    double z_vel;       // Velocity Z (m/s)
    double z_accel;     // Acceleration Z (m/s^2)
    
    // Constants
    const double mass;          // kg
    const double gravity;       // m/s^2
    const double drag_coeff;    // Drag factor
    const double dt;            // Simulation timestep (s)
    
public:
    PhysicsEngine();

    /**
     * @brief Steps the physics simulation forward by one timestep.
     * @param motor_force_z Total vertical thrust in Newtons (from FPGA)
     */
    void update(double motor_force_z);

    // --- Getters for Visualization ---
    double get_altitude() const;
    double get_velocity() const;

    // --- Getters for Sensor Emulation (FPGA Inputs) ---
    /**
     * @brief Returns altitude in Q16.16 fixed-point format for the SoC
     */
    int32_t get_sensor_data_fixed();
}; // <-- Added missing closing brace and semicolon

#endif // PHYSICS_ENGINE_H