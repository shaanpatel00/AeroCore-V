cmake_minimum_required(VERSION 3.10)
project(DigitalTwin)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Verilator REQUIRED)

add_executable(sim_twin verilator/main_tb.cpp)

# Link Verilator generated objects (placeholder logic)
# In reality, you run `verilator --cc` first, then link the .a file
target_link_libraries(sim_twin ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})