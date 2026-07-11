#ifndef VISUALIZER_H
#define VISUALIZER_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/freeglut.h>
#endif

class Visualizer {
public:
    /**
     * @brief Initializes GLUT window and OpenGL state.
     * @param argc Command line argument count
     * @param argv Command line arguments
     */
    static void init(int argc, char** argv);

    /**
     * @brief Main rendering function called by the display loop.
     * @param altitude The current altitude of the drone to draw.
     */
    static void render_scene(double altitude);

private:
    static void draw_ground();
    static void draw_drone();
};

#endif // VISUALIZER_H