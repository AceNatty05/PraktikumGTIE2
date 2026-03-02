/* Nama : Aqiatillah Rezi Zhafran
   NIM : 24060124140124
   LAB : E2 
*/
#include <GL/glut.h>

void piramida() {
    glColor3f(1,0,0);
    glRectf(-0.6,-0.6,-0.2,-0.3);
    glColor3f(0,1,0);
    glRectf(-0.2,-0.6,0.2,-0.3);
    glColor3f(0,0,1);
    glRectf(0.2,-0.6,0.6,-0.3);
    
    glColor3f(1,1,0);
    glRectf(-0.4,-0.3,0.0,0.0);
    glColor3f(1,0,1);
    glRectf(0.0,-0.3,0.4,0.0);

    glColor3f(0,1,1);
    glRectf(-0.2,0.0,0.2,0.3);

    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    piramida();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Piramida Segiempat ");
    glutDisplayFunc(display);
    glClearColor(0.85, 0.85, 0.85, 1);
    glutMainLoop();
    return 0;
}
