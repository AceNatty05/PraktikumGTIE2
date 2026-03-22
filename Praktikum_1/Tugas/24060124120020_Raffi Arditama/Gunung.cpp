#include <GL/glut.h>


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Gunung 1
    glLineWidth(4.0f);
    glColor3f(0.3f, 0.5f, 0.2f); 
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9f, -0.5f);  
        glVertex2f(-0.6f, 0.3f);   
        glVertex2f(-0.4f, -0.1f);  
        glVertex2f(-0.1f, 0.5f);   
        glVertex2f(0.2f, 0.0f);    
        glVertex2f(0.5f, 0.2f);    
        glVertex2f(0.9f, -0.5f);   
    glEnd();
    
    //tanah
    glColor3f(0.6f, 0.4f, 0.2f); 
    glBegin(GL_LINE_STRIP);
        glVertex2f(-1.0f, -0.5f);
        glVertex2f(1.0f, -0.5f);
    glEnd();
    
    // Matahari
    glColor3f(1.0f, 0.8f, 0.0f); // Kuning
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.4f, 0.7f);
        glVertex2f(-0.35f, 0.75f);
        glVertex2f(-0.3f, 0.7f);
        glVertex2f(-0.35f, 0.65f);
        glVertex2f(-0.4f, 0.7f);
    glEnd();
    
    // Awan 1
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glLineWidth(6.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.3f, 0.7f);
        glVertex2f(0.35f, 0.75f);
        glVertex2f(0.4f, 0.75f);
        glVertex2f(0.45f, 0.7f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f); // Biru langit
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_LINE_STRIP - Gunung");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
