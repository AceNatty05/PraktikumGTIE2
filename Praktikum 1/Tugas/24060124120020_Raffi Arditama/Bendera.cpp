#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Tiang bendera
    glLineWidth(5.0f);
    glColor3f(0.4f, 0.2f, 0.0f); // Coklat
    glBegin(GL_LINES);
        glVertex2f(-0.6f, -0.8f);
        glVertex2f(-0.6f, 0.6f);
    glEnd();
    
    // Bendera 
    glLineWidth(3.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6f, 0.6f);   // Kiri atas
        glVertex2f(0.2f, 0.6f);    // Kanan atas
        glVertex2f(0.2f, 0.3f);    // Kanan bawah
        glVertex2f(-0.6f, 0.3f);   // Kiri bawah
    glEnd();
    
    // Bintang 
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2f, 0.55f);  // Atas
        glVertex2f(-0.25f, 0.45f); // Kiri bawah
        glVertex2f(-0.15f, 0.50f); // Kanan tengah
        glVertex2f(-0.25f, 0.50f); // Kiri tengah
        glVertex2f(-0.15f, 0.45f); // Kanan bawah
    glEnd();
    
    // Tanah
    glColor3f(0.3f, 0.6f, 0.2f); // Hijau
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, -0.8f);
        glVertex2f(1.0f, -0.8f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();
    
    glFlush();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Biru langit
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL_LINE_LOOP - Bendera");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
