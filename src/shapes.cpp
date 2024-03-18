#include "shapes.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void draw_shape_2d(const float vertices[][2], const int indices[], int numIndices, GLenum mode) {
    glBegin(mode);
    for (int i = 0; i < numIndices; i++) {
        glVertex2fv(vertices[indices[i]]);
    }
    glEnd();
}

void draw_shape_3d(const float vertices[][3], const int indices[], int numIndices, GLenum mode) {
}
