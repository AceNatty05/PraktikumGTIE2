#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float xc = 0.0;
    float yc = 0.0;
    float r = 0.5;

    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 100; i++) {
        float theta = 2 * 3.1416 * i / 100;
        float x = xc + r * cos(theta);
        float y = yc + r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Tugas 1 - Lingkaran");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

