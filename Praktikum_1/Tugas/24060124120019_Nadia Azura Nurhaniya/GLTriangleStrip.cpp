// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen dengan memanfaatkan GL_TRIANGLE_STRIP

#include <GL/glut.h>

void TriangleStrip() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1f, 0.2f, 0.3f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.6f, 0.3f);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("GL_TRIANGLE_STRIP");
    glutDisplayFunc(TriangleStrip);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutMainLoop();
}
