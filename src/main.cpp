#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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
    glutCreateWindow("A Simple OpenGL Windows Application with GLUT");

    // Initialize GLUT
    init();

    // Call "display" function
    glutDisplayFunc(display);

    // Enter the GLUT event loop
    glutMainLoop();

    return 0;
}
