#include <windows.h>      // WAJIB: pertama
#include <GL/gl.h>         // KEDUA: OpenGL inti
#include <GL/glu.h>        // KETIGA: OpenGL utility
#include <GL/glut.h>       // KEEMPAT: GLUT (sudah include gl.h dan glu.h sebenarnya)

void point(void) { 
	glClear (GL_COLOR_BUFFER_BIT);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f( 0.0f, 0.8f, 0.9f);
	glEnd(); 
	glFlush();

} 

int main(int argc, char* argv[]) { 

	glutInit(&argc, argv);
	glutInitWindowSize (640,480);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Titik");
	glutDisplayFunc (point);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); 
	glutMainLoop();
	return 0;
}
