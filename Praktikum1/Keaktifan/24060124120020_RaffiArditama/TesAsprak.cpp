#include <GL/glut.h>

void SegiEmpat(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.18, 0.18, 0.18, -0.18);
    glFlush();
}

void SegiEmpat5(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.95, -0.5, 0.95, -0.3);
    glFlush();

//    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.95, -0.25, 0.95, -0.05);
    glFlush();
    
//    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(0.0, 0.0,0.95,0.95);
    glFlush();

    glColor3f(1.0f, 1.0f, 0.0f);
    glRectf(0.05,0.05, 0.90, 0.44);
    glFlush();
    
//    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(0.05, 0.46, 0.90, 0.90);
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat Assemble");
    glutDisplayFunc(SegiEmpat5);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
