#ifndef SHAPES_H
#define SHAPES_H

#ifdef __APPLE__
#include <GLUT/glut.h> // For macOS
#else
#include <GL/glut.h> // For most other systems
#endif

void draw_shape_2d(const float vertices[][2], const int indices[], int n, GLenum mode);

#endif
