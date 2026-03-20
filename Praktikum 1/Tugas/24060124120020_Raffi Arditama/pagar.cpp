#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // strip segitiga
    glColor3f(0.6f, 0.3f, 0.1f); // Coklat
    glBegin(GL_TRIANGLE_STRIP);
        // Pasangan 1
        glVertex2f(-0.8f, 0.3f);   
        glVertex2f(-0.8f, -0.5f); 
        // Pasangan 2
        glVertex2f(-0.6f, 0.5f);   
        glVertex2f(-0.6f, -0.5f);
        // Pasangan 3
        glVertex2f(-0.4f, 0.3f);   
        glVertex2f(-0.4f, -0.5f);        
        // Pasangan 4
        glVertex2f(-0.2f, 0.5f);   
        glVertex2f(-0.2f, -0.5f);  
        // Pasangan 5
        glVertex2f(0.0f, 0.3f);
        glVertex2f(0.0f, -0.5f);
        // Pasangan 6
        glVertex2f(0.2f, 0.5f);
        glVertex2f(0.2f, -0.5f);
        // Pasangan 7
        glVertex2f(0.4f, 0.3f);
        glVertex2f(0.4f, -0.5f);
        // Pasangan 8
        glVertex2f(0.6f, 0.5f);
        glVertex2f(0.6f, -0.5f);
        // Pasangan 9
        glVertex2f(0.8f, 0.3f);
        glVertex2f(0.8f, -0.5f);
    glEnd();
    // Tanah
    glColor3f(0.3f, 0.6f, 0.2f); 
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-1.0f, -0.5f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -0.5f);
        glVertex2f(1.0f, -1.0f);
    glEnd();
    
}

void init() {
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Biru praroro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_TRIANGLE_STRIP - Pagar");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
