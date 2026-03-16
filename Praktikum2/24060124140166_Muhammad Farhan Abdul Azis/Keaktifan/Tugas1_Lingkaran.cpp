#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592653589793;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    int circle_points = 100;
    for (int i = 0; i < circle_points; i++) {
        float angle = 2 * PI * i / circle_points;
        glVertex2f(0.5 * cos(angle), 0.5 * sin(angle));
    }
    glEnd();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 1 - Lingkaran");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
