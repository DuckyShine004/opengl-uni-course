#include <stdlib.h>
#include <shapes.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Vector3 {
  public:
    float x;
    float y;
    float z;

    Vector3(float x = 0.0, float y = 0.0, float z = 0.0) : x(x), y(y), z(z) {
    }
};

const static int numVertices = 5;
const int numIndices = 12;

static Vector3 verticesTriangles[numVertices] = {
    Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 5.0), Vector3(2.5, 0.0, 2.5),
    Vector3(5.0, 0.0, 5.0), Vector3(5.0, 0.0, 0.0),
};

const int indices[] = {
    2, 0, 1, 2, 1, 3, 2, 3, 4, 2, 4, 0,
};

void drawTriangleTile(Vector3 verticesTriangles[]) {
    Vector3 u;

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.5, 0.0);
    for (int i = 0; i < 3; i++) {
        u = verticesTriangles[indices[i]];
        glVertex3f(u.x, u.y, u.z);
    }

    glColor3f(0.0, 0.0, 1.0);
    for (int i = 3; i < numIndices; i++) {
        u = verticesTriangles[indices[i]];
        glVertex3f(u.x, u.y, u.z);
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); // Ensure we're in Modelview mode
    glLoadIdentity();           // Reset transformations
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    drawTriangleTile(verticesTriangles);
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 20.0, 0.0, 20.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW); // Switch to the Modelview matrix
    glLoadIdentity();
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
