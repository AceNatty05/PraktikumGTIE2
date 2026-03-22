#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(3.0f);
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    
    glBegin(GL_LINES);
        //sisi kiri
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.2f);
        
        //sisi kanan
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.2f);
        
        //bawah
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        
        //atas
        glVertex2f(-0.5f, 0.2f);
        glVertex2f(0.5f, 0.2f);
        
        // Atap - kiri
        glVertex2f(-0.5f, 0.2f);
        glVertex2f(0.0f, 0.6f);
        
        // Atap - kanan
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.0f, 0.6f);
        
        // Pintu - kiri
        glVertex2f(-0.15f, -0.5f);
        glVertex2f(-0.15f, -0.1f);
        
        // Pintu - kanan
        glVertex2f(0.15f, -0.5f);
        glVertex2f(0.15f, -0.1f);
        
        // Pintu - atas
        glVertex2f(-0.15f, -0.1f);
        glVertex2f(0.15f, -0.1f);
        
        // Jendela - kotak
        glVertex2f(-0.4f, 0.0f);
        glVertex2f(-0.25f, 0.0f);
        
        glVertex2f(-0.4f, 0.15f);
        glVertex2f(-0.25f, 0.15f);
        
        glVertex2f(-0.4f, 0.0f);
        glVertex2f(-0.4f, 0.15f);
        
        glVertex2f(-0.25f, 0.0f);
        glVertex2f(-0.25f, 0.15f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Background biru muda
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_LINES - Rumah Sederhana");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
