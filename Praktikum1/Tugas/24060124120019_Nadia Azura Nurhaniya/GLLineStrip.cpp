// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Gunung dengan memanfaatkan GL_LINE_STRIPE

#include <GL/glut.h>

void Gunung() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.2f, 0.8f, 0.2f); 

    glVertex2f(-0.9f, -0.3f); 
    glVertex2f(-0.6f, 0.2f);  
    glVertex2f(-0.3f, -0.3f); 
    glVertex2f(0.0f, 0.3f);   
    glVertex2f(0.3f, -0.3f);  
    glVertex2f(0.6f, 0.2f);   
    glVertex2f(0.9f, -0.3f);  
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Gunung - GL_LINE_STRIP");
    glutDisplayFunc(Gunung);
    glClearColor(0.7f, 0.85f, 1.0f, 0.0f); 
    glutMainLoop();
}
