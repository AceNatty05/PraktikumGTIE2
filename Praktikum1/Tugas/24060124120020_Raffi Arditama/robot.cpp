#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.7f, 0.7f, 0.7f); // Abu-abu
    
    // Kepala
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, 0.3f); 
        glVertex2f(0.25f, 0.3f);  
        glVertex2f(0.25f, 0.7f);  
        glVertex2f(-0.25f, 0.7f); 
    glEnd();
    
    // Badan
    glColor3f(0.5f, 0.5f, 0.8f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.35f, -0.3f);  
        glVertex2f(0.35f, -0.3f); 
        glVertex2f(0.35f, 0.25f); 
        glVertex2f(-0.35f, 0.25f);
    glEnd();
    
    // Tangan kiri
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.4f, 0.0f);
        glVertex2f(-0.4f, 0.2f);
        glVertex2f(-0.6f, 0.2f);
    glEnd();
    
    // Tangan kanan
    glBegin(GL_QUADS);
        glVertex2f(0.4f, 0.0f);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.4f, 0.2f);
    glEnd();
    
    // Kaki kiri
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.7f);
        glVertex2f(-0.1f, -0.7f);
        glVertex2f(-0.1f, -0.3f);
        glVertex2f(-0.25f, -0.3f);
    glEnd();
    
    // Kaki kanan
    glBegin(GL_QUADS);
        glVertex2f(0.1f, -0.7f);
        glVertex2f(0.25f, -0.7f);
        glVertex2f(0.25f, -0.3f);
        glVertex2f(0.1f, -0.3f);
    glEnd();
    
    // Mata kiri 
    glColor3f(0.0f, 1.0f, 0.0f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, 0.5f);
        glVertex2f(-0.08f, 0.5f);
        glVertex2f(-0.08f, 0.58f);
        glVertex2f(-0.15f, 0.58f);
    glEnd();
    
    // Mata kanan
    glBegin(GL_QUADS);
        glVertex2f(0.08f, 0.5f);
        glVertex2f(0.15f, 0.5f);
        glVertex2f(0.15f, 0.58f);
        glVertex2f(0.08f, 0.58f);
    glEnd();
    
    // Mulut
    glLineWidth(3.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.1f, 0.4f);
        glVertex2f(0.1f, 0.4f);
    glEnd();
    
    // Tombol
    glPointSize(10.0f);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_POINTS);
        glVertex2f(0.0f, 0.05f);
        glVertex2f(0.0f, -0.05f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.9f, 0.9f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_QUADS - Robot");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
