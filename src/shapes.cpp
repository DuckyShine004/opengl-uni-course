#include "shapes.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void draw_shape_2d(const float vertices[][2], const int indices[], int n, GLenum mode) {
    glBegin(mode);
    for (int i = 0; i < n; i++) {
        glVertex2fv(vertices[indices[i]]);
    }
    glEnd();
}
