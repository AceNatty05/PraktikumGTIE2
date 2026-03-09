// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : membuat Snowflakes d

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void Snowflake() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glColor3f(0.5f, 0.9f, 1.0f);

    int numArms = 6; 
    float mainLength = 0.5f; 
    float branchLength = 0.12f; 

    for (int i = 0; i < numArms; i++) {
        glPushMatrix();
        glRotatef(i * 60.0f, 0,0,1); 
        glBegin(GL_LINES);
        glVertex2f(0,0); glVertex2f(0, mainLength);
       
        for(float p=0.2f; p<=mainLength; p+=0.15f) {
            glVertex2f(0, p); glVertex2f(-branchLength, p + branchLength);
            glVertex2f(0, p); glVertex2f(branchLength, p + branchLength);
        }
        
        glVertex2f(0,0); glVertex2f(0.35f,0.35f);
        glVertex2f(0,0); glVertex2f(-0.35f,0.35f);
        glEnd();
        glPopMatrix();
    }
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Snowflake");
    glutDisplayFunc(Snowflake);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glutMainLoop();
    return 0;
}
