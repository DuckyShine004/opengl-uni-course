#include <stdlib.h>
#include <shapes.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

const int n = 8;
const float vertices[n][2] = {{0, 200},   {150, 150}, {150, 250}, {200, 0},
                              {200, 400}, {250, 150}, {250, 250}, {400, 200}};

const int m = 8;
const int indices[m] = {1, 0, 2, 4, 6, 7, 5, 3};

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    draw_shape_2d(vertices, indices, m, GL_TRIANGLE_FAN);
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1080.0, 0.0, 720.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
    // Initialise GLUT with command-line parameters.
    glutInit(&argc, argv);

    // Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set the window size
    glutInitWindowSize(1080, 720);

    // Set the window position
    glutInitWindowPosition(0, 0);

    // Create the window
    glutCreateWindow("OPENGL UNI");

    // Initialize GLUT
    init();

    // Call "display" function
    glutDisplayFunc(display);

    // Enter the GLUT event loop
    glutMainLoop();

    return 0;
}
