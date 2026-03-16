#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Syal merah 
    glColor3f(0.9f, 0.2f, 0.2f); // Merah
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.7f, 0.5f);   
        glVertex2f(-0.7f, 0.3f);   
    
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.4f, 0.2f);
        
        glVertex2f(-0.1f, 0.3f);
        glVertex2f(-0.1f, 0.1f);
        
        glVertex2f(0.2f, 0.2f);
        glVertex2f(0.2f, 0.0f);
        
        glVertex2f(0.5f, 0.1f);
        glVertex2f(0.5f, -0.1f);
        
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.7f, -0.2f);
    glEnd();
    
    // Garis tengah 
    glLineWidth(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.7f, 0.4f);
        glVertex2f(-0.4f, 0.3f);
        glVertex2f(-0.1f, 0.2f);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.7f, -0.1f);
    glEnd();
    
    // Rumbai
    glLineWidth(3.0f);
    glColor3f(0.9f, 0.2f, 0.2f);
    glBegin(GL_LINES);
        glVertex2f(-0.7f, 0.5f);
        glVertex2f(-0.75f, 0.6f);
        
        glVertex2f(-0.7f, 0.4f);
        glVertex2f(-0.77f, 0.5f);
        
        glVertex2f(-0.7f, 0.3f);
        glVertex2f(-0.75f, 0.4f);
    glEnd();
    
    // Rumbai kanan
    glBegin(GL_LINES);
        glVertex2f(0.7f, 0.0f);
        glVertex2f(0.75f, 0.1f);
        
        glVertex2f(0.7f, -0.1f);
        glVertex2f(0.77f, 0.0f);
        
        glVertex2f(0.7f, -0.2f);
        glVertex2f(0.75f, -0.1f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1.0f, 0.95f, 0.9f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_QUAD_STRIP - Syal");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

