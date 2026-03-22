// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Sparkle dengan memanfaatkan GL_LINES

#include <GL/glut.h>

void Sparkle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); 

    // garis vertikal
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.0f, -0.4f);

    // garis horizontal
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.4f, 0.0f);

    // garis diagonal 1
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(0.3f, -0.3f);

    // garis diagonal 2
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, 0.3f);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Sparkle - GL_LINES");
    glutDisplayFunc(Sparkle);
    glClearColor(0.0f, 0.2f, 0.5f, 0.0f);
    glutMainLoop();
}

