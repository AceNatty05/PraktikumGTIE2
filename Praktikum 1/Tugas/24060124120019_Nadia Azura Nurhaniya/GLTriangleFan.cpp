// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Diamond dengan memanfaatkan GL_TRIANGLE_FAN

#include <GL/glut.h>

void Diamond() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(-0.6f, 0.3f);
    glVertex2f(-0.4f, 0.5f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(-0.6f, 0.3f);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Diamond - GL_TRIANGLE_FAN");
    glutDisplayFunc(Diamond);
    glClearColor(1.0, 1.0f, 1.0f, 0.0f);
    glutMainLoop();
}
