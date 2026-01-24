#include "physics_engine.h"
#include <cmath>
#include <algorithm>

PhysicsEngine::PhysicsEngine() 
    : z_pos(0.0), z_vel(0.0), z_accel(0.0),
      mass(1.0), gravity(9.81), drag_coeff(0.05), dt(0.01) 
{
    // dt = 0.01s matches the 100Hz simulation rate
}

void PhysicsEngine::update(double motor_force_z) {
    // 1. Calculate Drag (Opposes Velocity)
    // Drag = -Cd * v * |v|
    double drag = -drag_coeff * z_vel * std::abs(z_vel);

    // 2. Calculate Net Force
    // F_net = Thrust + Drag - Gravity
    double gravity_force = mass * gravity;
    double net_force = motor_force_z + drag - gravity_force;

    // 3. Newton's Second Law (F = ma)
    z_accel = net_force / mass;

    // 4. Semi-Implicit Euler Integration
    z_vel += z_accel * dt;
    z_pos += z_vel * dt;

    // 5. Ground Constraint (Cannot fall below z=0)
    if (z_pos < 0.0) {
        z_pos = 0.0;
        if (z_vel < 0.0) z_vel = 0.0; // Stop downward velocity
    }
}

double PhysicsEngine::get_altitude() const {
    return z_pos;
}

double PhysicsEngine::get_velocity() const {
    return z_vel;
}

int32_t PhysicsEngine::get_sensor_data_fixed() {
    // Convert double to Q16.16 Fixed Point
    // Ex: 50.0 meters -> 50 * 65536 = 3,276,800
    return (int32_t)(z_pos * 65536.0);
}