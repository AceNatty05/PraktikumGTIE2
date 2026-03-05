#include <GL/glut.h> 

void dumb_selfie(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.85f, 0.8f);
    glRectf(-0.5, -0.5, 0.5, 0.5);
    glFlush();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(0.2, 0.0, 0.6, 0.4);
    glFlush();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.6, 0.0, -0.2,  0.4);
    glFlush();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(0.4, 0.0, 0.6, 0.2);
    glFlush();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(-0.5, 0.1, -0.3, 0.3);
    glFlush();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(-0.7, 0.5, 0.7, 0.6);
    glFlush();
        
	glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.5, 0.6, 0.5, 0.7);
    glFlush();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(-0.5, 0.7, 0.5, 0.75);
    glFlush();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.5, 0.75, 0.5, 0.85);
    glFlush();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(-0.5, 0.85, 0.5, 0.90);
    glFlush();

    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(-0.2, -0.4, 0.2, -0.2);
    glFlush();   
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.1, -0.3, 0.1, -0.6);
    glFlush();   
}

void display(){
	dumb_selfie();
}

int main(int argc, char* argv[]) { 
 
	glutInit(&argc, argv);
	glutInitWindowSize (640,640);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Garis");
	glutDisplayFunc (display);
	glClearColor(0.2f, 0.5f, 0.6f, 1.0f); 
	glutMainLoop();
	return 0;
}
