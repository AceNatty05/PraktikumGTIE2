// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Jendela dengan memanfaatkan GL_QUADS

#include <GL/glut.h>

void jendela() {
    glClear(GL_COLOR_BUFFER_BIT);
    // frame jendela 
    glColor3f(0.4f, 0.2f, 0.1f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.6f);
        glVertex2f(0.6f, 0.6f);
        glVertex2f(0.6f, -0.6f);
        glVertex2f(-0.6f, -0.6f);
    glEnd();

    // kaca kiri atas
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(-0.05f, 0.5f);
        glVertex2f(-0.05f, 0.05f);
        glVertex2f(-0.5f, 0.05f);
    glEnd();
    // kaca kiri bawah
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.05f);
        glVertex2f(-0.05f, -0.05f);
        glVertex2f(-0.05f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
    glEnd();

    // kaca kanan atas
    glBegin(GL_QUADS);
        glVertex2f(0.05f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, 0.05f);
        glVertex2f(0.05f, 0.05f);
    glEnd();
    // kaca kanan bawah
    glBegin(GL_QUADS);
        glVertex2f(0.05f, -0.05f);
        glVertex2f(0.5f, -0.05f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.05f, -0.5f);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Jendela - GL_QUADS");
    glutDisplayFunc(jendela);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
}
