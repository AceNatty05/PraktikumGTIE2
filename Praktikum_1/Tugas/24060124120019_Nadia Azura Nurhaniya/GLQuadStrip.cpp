// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Gelombang dengan memanfaatkan GL_QUAD_STRIP

#include <GL/glut.h>

void Gelombang() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.6f, 1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.8f, 0.3f); 
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.8f, -0.3f);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Gelombang - GL_QUAD_STRIP");
    glutDisplayFunc(Gelombang);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
}
