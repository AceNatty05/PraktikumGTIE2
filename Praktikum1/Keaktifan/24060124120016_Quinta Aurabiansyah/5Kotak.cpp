#include <GL/glut.h>

void kotak(float x, float y, float size, float r, float g, float b) {
    glColor3f(r, g, b); 
    glBegin(GL_QUADS);
        glVertex2f(x - size, y - size);
        glVertex2f(x + size, y - size);
        glVertex2f(x + size, y + size);
        glVertex2f(x - size, y + size);
    glEnd();

    // Garis Tepi
    glColor3f(0.0f, 0.0f, 0.0f); 
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - size, y - size);
        glVertex2f(x + size, y - size);
        glVertex2f(x + size, y + size);
        glVertex2f(x - size, y + size);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float s = 0.25f; // Ukuran kotak

    //Kepala
    kotak(0.0f, 0.6f, s, 0.4f, 0.6f, 0.9f); 
    
    //Badan
    kotak(0.0f, 0.0f, s, 0.3f, 0.5f, 0.8f); 
    
    //Tangan Kiri
    kotak(-0.51f, 0.0f, s, 0.5f, 0.7f, 1.0f); 
    
    //Tangan Kanan
    kotak(0.51f, 0.0f, s, 0.5f, 0.7f, 1.0f); 
    
    //Kaki
    kotak(0.0f, -0.6f, s, 0.2f, 0.4f, 0.7f); 

    // Mata
    float eyeSize = 0.05f; 
    kotak(-0.1f, 0.65f, eyeSize, 1.0f, 1.0f, 1.0f); // Mata Kiri 
    kotak( 0.1f, 0.65f, eyeSize, 1.0f, 1.0f, 1.0f); // Mata Kanan 

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); 
    glutCreateWindow("Robot kotak");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
