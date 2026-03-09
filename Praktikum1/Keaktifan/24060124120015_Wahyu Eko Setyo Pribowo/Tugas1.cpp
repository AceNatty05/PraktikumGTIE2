#include <GL/glut.h>

void kotak(float x, float y, float size) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.3f, 0.6f, 0.9f);

    float s = 0.3f;

    // Baris bawah (3 kubus)
    kotak(-0.6f, -0.5f, s);
    kotak(-0.2f, -0.5f, s);
    kotak(0.2f, -0.5f, s);

    // Baris atas (2 kubus)
    kotak(-0.4f, -0.1f, s);
    kotak(0.0f, -0.1f, s);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Kubus Bertingkat");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
