// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : membuat Snowflake dengan menggunakan rotasi

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void Snowflake() {
    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        glRotated(i * 45.0, 0.0, 0.0, 1.0); 
        glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f); 
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.0f, 0.25f); glVertex2f(0.12f, 0.35f);  
        glVertex2f(0.0f, 0.25f); glVertex2f(-0.12f, 0.35f); 
        glVertex2f(0.0f, 0.38f); glVertex2f(0.10f, 0.45f);  
        glVertex2f(0.0f, 0.38f); glVertex2f(-0.10f, 0.45f); 
        glEnd();
        glPopMatrix();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5.0f);
    glColor3f(0.7f, 0.85f, 0.9f); 
    Snowflake(); 
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Snowflake");
    glutDisplayFunc(display);
    glClearColor(0.3f, 0.1f, 0.1f, 1.0f); 
    glutMainLoop();
    return 0;
}
