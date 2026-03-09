#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Pizza 8 potongan
    glColor3f(1.0f, 0.8f, 0.3f); // Kuning 
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);     // Pusat pizza
        
        glVertex2f(0.0f, 0.6f);     // Atas
        glVertex2f(0.4f, 0.4f);     // Kanan atas
        glVertex2f(0.6f, 0.0f);     // Kanan
        glVertex2f(0.4f, -0.4f);    // Kanan bawah
        glVertex2f(0.0f, -0.6f);    // Bawah
        glVertex2f(-0.4f, -0.4f);   // Kiri bawah
        glVertex2f(-0.6f, 0.0f);    // Kiri
        glVertex2f(-0.4f, 0.4f);    // Kiri atas
        glVertex2f(0.0f, 0.6f);     // Kembali ke atas 
    glEnd();
    
    
    // Garis potongan
    glLineWidth(2.0f);
    glColor3f(0.6f, 0.4f, 0.1f); // Coklat
    glBegin(GL_LINES);
        // Garis vertikal
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 0.6f);
        
        // Garis horizontal
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.6f, 0.0f);
        
        // Garis diagonal 1
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.4f, 0.4f);
        
        // Garis diagonal 2
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.4f, -0.4f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f); // Abu-abu terang
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_TRIANGLE_FAN - Pizza");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
