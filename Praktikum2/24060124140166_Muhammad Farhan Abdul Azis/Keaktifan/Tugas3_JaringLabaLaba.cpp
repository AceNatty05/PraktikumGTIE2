#include <GL/glut.h>
#include <math.h>

void drawWebBranch() {
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.8, 0.0);
    float cos45 = 0.707106;
    float sin45 = 0.707106;
    float rings = 3.5; 
    for (int i = 1; i <= rings; i++) {
        float r = 0.8 * i / rings;
        glVertex2f(r, 0.0); 
        glVertex2f(r * cos45, r * sin45);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White
    glLineWidth(2.0f);
    
    int sides = 8;
    for (int i = 0; i < sides; i++) {
        glPushMatrix();
        glRotated(i * (360.0 / sides), 0.0, 0.0, 1.0);
        drawWebBranch();
        glPopMatrix();
    }
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Keaktifan Jaring Laba-laba");
    glutDisplayFunc(display);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glutMainLoop();
    return 0;
}
