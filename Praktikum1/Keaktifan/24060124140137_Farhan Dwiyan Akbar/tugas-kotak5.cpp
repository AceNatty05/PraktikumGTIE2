#include <GL/glut.h>

void SegiEmpat5(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.4, -0.4, -0.2, -0.2);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(-0.2, -0.4, 0.0, -0.2);
    
    glColor3f(1.0f, 0.0f, 1.0f);
    glRectf(0.0, -0.20, 0.2, -0.4);
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(0.0, 0.0, 0.2, -0.2);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(0.0, 0.0, -0.2, -0.2);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(0.0, 0.0, 0.2, 0.2);
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat Lima");
    glutDisplayFunc(SegiEmpat5);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
