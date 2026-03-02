#include <gl/glut.h>

void SegiEmpat(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.4f, 0.7f);
    
    glRectf(-0.20, -0.20, 0.20, 0.20);
    
    glColor3f(1.0f, 0.5f, 0.0f);
    glRectf(-0.30, 0.30, -0.18, 0.18);
    glRectf(0.18, 0.30, 0.30, 0.18);
	
	glColor3f(.05f, 0.0f, 0.5f);
	glRectf(0.35, 0.35, 0.55, 0.55);
	
	glColor3f(1.0f, 0.4f, 0.7f);
	glRectf(0.50, 0.50, 0.30, 0.30);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.15, 0.0, 0.0, 0.15);
    glRectf(0.10, 0.08, 0.15, 0.15);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(-0.12, 0.05, -0.05, 0.13);
    glRectf(0.11, 0.10, 0.13, 0.13);
    
    glFlush();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat");
    glutDisplayFunc(SegiEmpat);
    glClearColor(0.4f, 0.8f, 0.67f, 1.0f);
    glutMainLoop();

    return 0;
}

