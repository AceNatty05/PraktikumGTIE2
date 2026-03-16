/*Nama	: Muhammad Fauzan Akbar
  NIM	: 24060124140139
  LAB	: GTI E1
*/
#include <GL/glut.h>
#include <math.h>

void Lingkaran() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.4f, 0.0f);
    glLineWidth(8.0f);

    glPushMatrix();
    glScalef(0.6f, 0.6f, 1.0f);
    glBegin(GL_LINE_LOOP);
        GLint circle_points = 100;
        static double PI = 3.14159265;
        for (int i = 0; i < circle_points; i++) {
            float angle = 2 * PI * i / circle_points;
            glVertex2f(cos(angle), sin(angle));
        }
    glEnd();
    glPopMatrix();

    glFlush();
}

void display() {
    Lingkaran();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Lingkaran");
    glClearColor(0.10f, 0.10f, 0.18f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
