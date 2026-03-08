#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // titikk
    glColor3f(1.0, 0.0, 0.0);  
    glPointSize(6);            
    glBegin(GL_POINTS);
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.3, 0.3);
        glVertex2f(-0.1, 0.5);
        glVertex2f(0.1, 0.3);
        glVertex2f(0.3, 0.5);
    glEnd();

    // garis
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-0.8, -0.5);
        glVertex2f(-0.4, -0.2);

        glVertex2f(-0.4, -0.2);
        glVertex2f(0.0, -0.5);

        glVertex2f(0.0, -0.5);
        glVertex2f(0.4, -0.2);

        glVertex2f(0.4, -0.2);
        glVertex2f(0.8, -0.5);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("GL_POINTS dan GL_LINES");

    glutDisplayFunc(display);

    glClearColor(0,0,0,0);
    gluOrtho2D(-1,1,-1,1);

    glutMainLoop();
    return 0;
}
