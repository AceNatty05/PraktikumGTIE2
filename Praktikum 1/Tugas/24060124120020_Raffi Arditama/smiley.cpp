#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Mata kiri
    glPointSize(15.0f);
    glColor3f(1.0f, 1.0f, 0.8f);
    glBegin(GL_POINTS);
        glVertex2f(-0.2f, 0.2f);
    glEnd();
    
    // Mata kanan
    glBegin(GL_POINTS);
        glVertex2f(0.2f, 0.2f);
    glEnd();
    
    // Mulut
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(-0.1f, -0.25f);
        glVertex2f(0.0f, -0.25f);
        glVertex2f(0.1f, -0.25f);
        glVertex2f(0.2f, -0.2f);
        glVertex2f(0.3f, -0.1f);
    glEnd();
    
    // Hidung
    glPointSize(8.0f);
    glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.0f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_POINTS - Wajah Senyum");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
