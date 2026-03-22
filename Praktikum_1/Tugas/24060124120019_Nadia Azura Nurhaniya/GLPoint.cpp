// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Smile Face dengan memanfaatkan GL_POINT

#include <GL/glut.h>

void SmileFace() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0f);
    glBegin(GL_POINTS);

    glColor3f(1.0f, 1.0f, 0.0f);

	// lingkaran untuk kepalanya
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.2f, 0.35f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.3f, 0.0f);

	// mata
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.1f);
    glVertex2f(0.12f, 0.1f);

	// mulutnya
    glVertex2f(-0.15f, -0.05f);
    glVertex2f(-0.05f, -0.12f);
    glVertex2f(0.05f, -0.12f);
    glVertex2f(0.15f, -0.05f);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Smile Face - GL_POINTS");
    glutDisplayFunc(SmileFace);
    glClearColor(1.0f, 0.7f, 0.8f, 0.0f);
    glutMainLoop();
}
