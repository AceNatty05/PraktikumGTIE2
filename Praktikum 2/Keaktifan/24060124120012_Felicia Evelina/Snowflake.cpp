#include <gl/glut.h>

void Garis(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 1.0f);

    glPushMatrix(); 
    for(int i = 0; i < 4; i++)
    {
        glBegin(GL_LINES);

        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.6, 0.6, 0.0);
        
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.2, 0.4, 0.0);
        
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.4, 0.2, 0.0);
        
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.2, 0.4, 0.0);
        
        glVertex3f(0.4, 0.4, 0.0);
        glVertex3f(0.4, 0.6, 0.0);
        
        glVertex3f(0.4, 0.4, 0.0);
        glVertex3f(0.6, 0.4, 0.0);

        glEnd();

        glRotatef(90.0, 0.0, 0.0, 1.0);
    }
    glPopMatrix(); 

    glPushMatrix(); 
    for(int i = 0; i < 4; i++)
    {
        glBegin(GL_LINES);

        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.8, 0.0);
        
        glVertex3f(0.0, 0.4, 0.0);
        glVertex3f(-0.2, 0.6, 0.0);
        
        glVertex3f(0.0, 0.4, 0.0);
        glVertex3f(0.2, 0.6, 0.0);

        glEnd();

        glRotatef(90.0, 0.0, 0.0, 1.0);
    }
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Snowflake");

    glClearColor(1.0f, 0.8f, 1.0f, 1.0f);

    glutDisplayFunc(Garis);
    glutMainLoop();

    return 0;
}
