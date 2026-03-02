#include <gl/glut.h>
// Nama: Anggita Kirana Puspa
// NIM: 24060124130064
// Lab: E2

void SegiEmpat5() {
	  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glRectf(-0.2f,  0.1f, 0.4f, -0.1f);
    
    glColor3f(0.0f, 1.0f, 0.0f); 
    glRectf(0.0f,  -0.3f, 0.4f, -0.1f);
    
    glColor3f(1.0f, 0.0f, 1.0f); 
    glRectf(-0.2f,  0.1f, -0.1f, -0.2f);
    
	  glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.10f, -0.10,  0.10,  0.10);

    glColor3f(0.0f, 1.0f, 1.0f); 
    glRectf( 0.3f,  0.2f,  0.5f, -0.1f);
    
    glFlush();
}

void display(){
	SegiEmpat5();
}

int main(int argc, char* argv[]) { 
	glClear (GL_COLOR_BUFFER_BIT);
	glutInit(&argc, argv);
	glutInitWindowSize (640,480);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("SegiEmpatLima");
	glutDisplayFunc (display);
	glClearColor(1.0f, 1.0f, 0.4f, 1.0f); 
	glutMainLoop();
	return 0;
}
