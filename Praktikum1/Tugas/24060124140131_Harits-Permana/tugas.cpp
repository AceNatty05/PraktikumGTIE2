#include <GL/glut.h>

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9f, 0.8f);
        glVertex2f(-0.7f, 0.5f);
        glVertex2f(-0.5f, 0.8f);
        glVertex2f(-0.3f, 0.5f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.3f, 0.8f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.7f, 0.8f);
        glVertex2f(0.9f, 0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.7f, -0.2f);
        glVertex2f(-0.9f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.5f, 0.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    // GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(0.3f, -0.2f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.7f, -0.2f);
        glVertex2f(0.9f, -0.5f);
    glEnd();

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f, -0.8f);
        glVertex2f(-0.7f, -0.8f);
        glVertex2f(-0.7f, -0.6f);
        glVertex2f(-0.9f, -0.6f);
    glEnd();

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.3f, -0.8f);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.5f, -0.8f);
        glVertex2f(0.5f, -0.6f);
        glVertex2f(0.7f, -0.8f);
        glVertex2f(0.7f, -0.6f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Contoh Semua Primitive OpenGL");
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
