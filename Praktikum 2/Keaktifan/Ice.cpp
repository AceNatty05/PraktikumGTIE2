// Nama         : Harits Permana
// NIM          : 24060124140131
// Lab          : E2
// Deskripsi    : Membuat Ice menggunakan prinsip lingkaran

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void drawBranch()
{
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.5);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.0, 0.3);
        glVertex2f(-0.1, 0.4);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.0, 0.3);
        glVertex2f(0.1, 0.4);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.0, 0.45);
        glVertex2f(-0.08, 0.52);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.0, 0.45);
        glVertex2f(0.08, 0.52);
    glEnd();
}

void show()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.8, 0.9, 1.0);

    for(int i=0;i<10;i++)
    {
        glPushMatrix();
        glRotatef(i * 36.0, 0,0,1);
        drawBranch();
        glPopMatrix();
    }

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); 
    glutInitWindowSize(640, 480); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutCreateWindow("Simple"); 
    glutDisplayFunc(show); 
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); 
    glutMainLoop(); 
    return 0; 
}