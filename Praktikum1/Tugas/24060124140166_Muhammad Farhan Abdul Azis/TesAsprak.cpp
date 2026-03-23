// TUGAS 1 & 2: Demonstrasi semua fungsi primitif OpenGL
// GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLE_FAN,
// GL_TRIANGLE_STRIP, GL_QUADS, GL_QUAD_STRIP

#include <gl/glut.h>

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9f,  0.9f);
        glVertex2f(-0.7f,  0.7f);
        glVertex2f(-0.8f,  0.5f);
        glVertex2f(-0.6f,  0.5f);
    glEnd();
    glColor3f(1.0f, 0.5f, 0.0f); // Oranye
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5f,  0.9f);
        glVertex2f(-0.3f,  0.9f);
        glVertex2f(-0.2f,  0.7f);
        glVertex2f(-0.4f,  0.5f);
        glVertex2f(-0.6f,  0.7f);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f( 0.0f,  0.7f); // titik pusat
        glVertex2f(-0.1f,  0.5f);
        glVertex2f( 0.0f,  0.45f);
        glVertex2f( 0.1f,  0.5f);
        glVertex2f( 0.15f, 0.65f);
        glVertex2f( 0.1f,  0.85f);
        glVertex2f(-0.05f, 0.9f);
        glVertex2f(-0.1f,  0.5f);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f( 0.2f,  0.9f);
        glColor3f(0.0f, 0.8f, 0.2f); glVertex2f( 0.2f,  0.6f);
        glColor3f(0.0f, 1.0f, 0.5f); glVertex2f( 0.4f,  0.9f);
        glColor3f(0.0f, 0.8f, 0.7f); glVertex2f( 0.4f,  0.6f);
        glColor3f(0.0f, 1.0f, 0.8f); glVertex2f( 0.6f,  0.9f);
        glColor3f(0.0f, 0.8f, 1.0f); glVertex2f( 0.6f,  0.6f);
        glColor3f(0.2f, 0.6f, 1.0f); glVertex2f( 0.8f,  0.9f);
        glColor3f(0.0f, 0.4f, 1.0f); glVertex2f( 0.8f,  0.6f);
    glEnd();
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glBegin(GL_QUADS);
        // Quad pertama
        glVertex2f(-0.9f,  0.3f);
        glVertex2f(-0.6f,  0.3f);
        glVertex2f(-0.6f,  0.1f);
        glVertex2f(-0.9f,  0.1f);
        // Quad kedua
        glVertex2f(-0.5f,  0.3f);
        glVertex2f(-0.2f,  0.3f);
        glVertex2f(-0.2f,  0.1f);
        glVertex2f(-0.5f,  0.1f);
        // Quad ketiga
        glVertex2f(-0.1f,  0.3f);
        glVertex2f( 0.2f,  0.3f);
        glVertex2f( 0.2f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();
    glColor3f(0.5f, 0.0f, 1.0f); // Ungu
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.9f, -0.1f);
        glVertex2f(-0.9f, -0.3f);
        glVertex2f(-0.6f, -0.1f);
        glVertex2f(-0.6f, -0.3f);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f(-0.3f, -0.3f);
        glVertex2f( 0.0f, -0.1f);
        glVertex2f( 0.0f, -0.3f);
        glVertex2f( 0.3f, -0.1f);
        glVertex2f( 0.3f, -0.3f);
        glVertex2f( 0.6f, -0.1f);
        glVertex2f( 0.6f, -0.3f);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 1 & 2");
    glutDisplayFunc(Display);
    glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
    glutMainLoop();
    return 0;
}
