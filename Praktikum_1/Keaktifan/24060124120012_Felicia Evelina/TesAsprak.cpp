#include <GL/glut.h>

void segiempat5() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glRectf(-0.9f,  0.2f, -0.7f, -0.2f);
    glColor3f(0.0f, 1.0f, 2.0f); 
    glRectf(-0.6f,  0.7f, -0.4f, -0.8f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    glRectf(-0.6f,  0.2f, -0.4f, -0.2f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glRectf(-0.3f,  0.2f, -0.1f, -0.2f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glRectf( 0.0f,  0.2f,  0.2f, -0.2f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glRectf( 0.3f,  0.2f,  0.5f, -0.2f);
	glColor3f(2.0f, 1.0f, 0.0f); 
    glRectf( 0.7f, 0.6f, 0.9f, -0.6f);
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat");
    glutDisplayFunc(segiempat5);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
