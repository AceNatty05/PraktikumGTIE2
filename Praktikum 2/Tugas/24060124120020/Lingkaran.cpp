#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); // merah

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // titik pusat
        for (int i = 0; i <= 360; i++) {
            float a = i * 3.14159f / 180.0f;
            glVertex2f(cosf(a) * 0.5f, sinf(a) * 0.5f);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Lingkaran");
    glutDisplayFunc(display);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // putih

    glutMainLoop();
    return 0;
}
