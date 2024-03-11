cmake_minimum_required(VERSION 3.22.1)
project(opengl-uni-course)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(include)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Add source files
set(SOURCE_FILES src/main.cpp src/shapes.cpp)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Set up OpenGL preference so you don't get the annoying warnings each time you run cmake
set(OpenGL_GL_PREFERENCE "GLVND")

# Find and link OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
