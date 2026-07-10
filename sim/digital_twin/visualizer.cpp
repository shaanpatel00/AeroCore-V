#include "visualizer.h"
#include <cmath>

void Visualizer::init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("RISC-V SoC Digital Twin");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Dark background
} // <-- Added missing closing brace

void Visualizer::draw_ground() {
    // Draw a grid for the ground
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    for(int i = -50; i <= 50; i += 5) {
        glVertex3f(i, -50, 0); glVertex3f(i, 50, 0);
        glVertex3f(-50, i, 0); glVertex3f(50, i, 0);
    }
    glEnd();
} // <-- Added missing closing brace

void Visualizer::draw_drone() {
    // Simple Wireframe Sphere for the Drone
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glutWireSphere(1.0, 10, 10);
} // <-- Added missing closing brace

void Visualizer::render_scene(double altitude) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Camera Setup
    // Eye(50, 50, 20), LookAt(0, 0, 10), Up(0, 0, 1)
    gluLookAt(40.0, 40.0, 30.0, 
               0.0, 0.0, 10.0, 
               0.0, 0.0, 1.0);
               
    draw_ground();
    
    // Draw Target Altitude Marker (Red line at 50m)
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-10, 0, 50); glVertex3f(10, 0, 50);
    glVertex3f(0, -10, 50); glVertex3f(0, 10, 50);
    glEnd();
    
    // Move to Drone Position and Draw
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, (float)altitude);
    draw_drone();
    glPopMatrix();
    
    glutSwapBuffers();
} // <-- Added missing closing brace