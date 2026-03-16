#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592653589793;

void drawWheel() {
    // Ban
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1);
    int circle_points = 50;
    for (int i = 0; i < circle_points; i++) {
        float angle = 2 * PI * i / circle_points;
        glVertex2f(0.15 * cos(angle), 0.15 * sin(angle));
    }
    glEnd();
    
    // Rim
    glColor3f(0.8, 0.8, 0.8);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++) {
        float angle = 2 * PI * i / 8;
        glVertex2f(0.15 * cos(angle), 0.15 * sin(angle));
        glVertex2f(0.0, 0.0);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Bodi mobil
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0.1);
    glVertex2f(-0.6, 0.1);
    glEnd();
    
    // Atap
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.1);
    glVertex2f(0.4, 0.1);
    glVertex2f(0.2, 0.3);
    glVertex2f(-0.2, 0.3);
    glEnd();
    glPopMatrix();
    
    // Ban belakang
    glPushMatrix();
    glTranslatef(-0.4, -0.2, 0.0);
    glRotated(45.0, 0.0, 0.0, 1.0);
    drawWheel();
    glPopMatrix();
    // Ban depan    
    glPushMatrix();
    glTranslatef(0.4, -0.2, 0.0);
    glRotated(45.0, 0.0, 0.0, 1.0);
    drawWheel();
    glPopMatrix();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 2 - Mobil 2D");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
