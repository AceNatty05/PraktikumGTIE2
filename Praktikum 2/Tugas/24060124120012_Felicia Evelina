#include <GL/glut.h>
#include <GL/glut.h>
#include <math.h>

void Mobil(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();

glPushMatrix();
glColor3f(0.0f, 0.8f, 0.0f); 
glBegin(GL_QUADS);
glVertex2f(-1.0f, -1.0f);  
glVertex2f( 1.0f, -1.0f);  
glVertex2f( 1.0f, -0.15f); 
glVertex2f(-1.0f, -0.15f); 
glEnd();
glPopMatrix();

glColor3f(1.0f, 0.6f, 0.7f);
glBegin(GL_POLYGON);
glVertex2f(-0.4f, 0.1f);
glVertex2f(-0.5f, 0.0f);
glVertex2f(-0.5f, -0.1f);
glVertex2f(0.4f,  -0.1f);
glVertex2f(0.4f,  0.1f);
glEnd();

glColor3f(1.0f, 0.8f, 0.9f);
glBegin(GL_POLYGON);
glVertex2f(-0.4f, 0.1f);
glVertex2f(-0.3f, 0.2f);
glVertex2f(-0.1f, 0.2f);
glVertex2f(-0.1f, 0.1f);
glEnd();

glColor3f(1.2f, 0.6f, 0.9f);
glBegin(GL_POLYGON);
glVertex2f(-0.1f, 0.3f);
glVertex2f(-0.1f, 0.1f);
glVertex2f(0.4f, 0.1f);
glVertex2f(0.4f, 0.3f);
glEnd();

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLES);
glVertex2f(0.4f, 0.1f);
glVertex2f(0.7f, 0.1f);
glVertex2f(0.7f, 0.4f);
glEnd();

glColor3f(1.0f, 0.5f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.4f, 0.1f);
glVertex2f(0.7f, 0.1f);
glVertex2f(0.7f, 0.0f);
glVertex2f(0.4f, 0.0f);
glEnd();

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.7f, 0.0f);
glVertex2f(0.4f, 0.0f);
glVertex2f(0.4f, -0.1f);
glVertex2f(0.7f, -0.1f);
glEnd();

glColor3f(0.0f, 0.5f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(0.0f, 0.25f);
glVertex2f(0.3f, 0.25f);
glVertex2f(0.3f, 0.1f);
glVertex2f(0.0f, 0.1f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
glVertex2f(0.15f, 0.25f);
glVertex2f(0.15f, 0.1f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_LINES);
glVertex2f(0.0f, 0.17f);
glVertex2f(0.3f, 0.17f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(0.2f, 0.6f);
glVertex2f(0.4f, 0.75f);
glVertex2f(0.7f, 0.6f);
glVertex2f(0.6f, 0.75f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(-0.9f, 0.8f);
glVertex2f(-0.8f, 0.9f);
glVertex2f(-0.4f, 0.8f);
glVertex2f(-0.6f, 0.9f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(-0.5f, 0.4f);
glVertex2f(-0.4f, 0.5f);
glVertex2f(-0.1f, 0.4f);
glVertex2f(-0.2f, 0.5f);
glEnd();

float PI = 3.1415921;
glPushMatrix();
glTranslatef(-0.3f, -0.1f, 0.0f); 
glColor3f(0.2f, 0.2f, 0.2f); 
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
float angle = 2 * PI * i / 100;
glVertex2f(cos(angle) * 0.12f , sin(angle) * 0.12f);
}
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
for(int i = 0; i < 6; i++) {
glBegin(GL_LINES);
glVertex2f(0.0f, 0.0f);
glVertex2f( 0.12f, 0.0f);
glEnd();
glRotatef(60.0, 0.0, 0.0, 1.0);
}

glPushMatrix();
glTranslatef(0.5f, 0.0f, 0.0f); 
glColor3f(0.2f, 0.2f, 0.2f); 
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
float angle = 2 * PI * i / 100;
glVertex2f(cos(angle) * 0.12f, sin(angle) * 0.12f);
}
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
for(int i = 0; i < 6; i++) {
glBegin(GL_LINES);
glVertex2f(0.0f, 0.0f);
glVertex2f( 0.12f, 0.0f);
glEnd();
glRotatef(60.0, 0.0, 0.0, 1.0);
}
glPopMatrix(); 

glPushMatrix(); 
glTranslatef(-0.4f, 0.7f, 0.0f); 
glColor3f(1.0f, 0.5f, 0.0f); 
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
float angle = 2 * PI * i / 100;
glVertex2f(cos(angle) * 0.20f, sin(angle) * 0.20f);
}
glEnd();
glPopMatrix();

glPushMatrix(); 
glTranslatef(-0.4f, 0.7f, 0.0f); 
glColor3f(1.0f, 1.0f, 0.0f); 
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
float angle = 2 * PI * i / 100;
glVertex2f(cos(angle) *  0.15f, sin(angle) *  0.15f);
}
glEnd();

glPopMatrix();
glFlush();
}

int main(int argc, char** argv) {
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("MOBIL NGUEEENG");
    glutDisplayFunc(Mobil);
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f); 
    glutMainLoop();
    return 0;
}
}
