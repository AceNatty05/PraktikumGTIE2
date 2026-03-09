// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Bintang dengan memanfaatkan GL_LINE_LOOP

#include <GL/glut.h>

void Bintang() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 0.0f); 

    glVertex2f(0.0f, 0.5f);    
    glVertex2f(0.15f, 0.15f);
    glVertex2f(0.5f, 0.15f);   
    glVertex2f(0.25f, -0.1f);
    glVertex2f(0.35f, -0.45f); 
    glVertex2f(0.0f, -0.2f);   
    glVertex2f(-0.35f, -0.45f);
    glVertex2f(-0.25f, -0.1f);
    glVertex2f(-0.5f, 0.15f);  
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Bintang - GL_LINE_LOOP");
    glutDisplayFunc(Bintang);
    glClearColor(0.3f, 0.3f, 0.9f, 0.0f);
    glutMainLoop();
}

