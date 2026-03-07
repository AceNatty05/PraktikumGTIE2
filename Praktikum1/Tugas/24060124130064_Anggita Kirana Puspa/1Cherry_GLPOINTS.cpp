#include <GL/glut.h>
// Nama: Anggita Kirana Puspa
// NIM: 24060124130064
// Lab: E2

void cherry() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 1.0f);
	//point A
	glVertex3f(0.5f, 0.18f, 0.0f);
	//point B
	glVertex3f(0.44f, 0.25f, 0.0f);
	//point C
	glVertex3f(0.395f, 0.32f, 0.0f);
	//point D
	glVertex3f(0.375f, 0.404f, 0.0f);
	//point E
	glVertex3f(0.42f, 0.49f, 0.0f);
	//point F
	glVertex3f(0.484f, 0.52f, 0.0f);
	//point G
	glVertex3f(0.547f, 0.513f, 0.0f);
	//point H
	glVertex3f(0.588f, 0.483f, 0.0f);
	//point I
	glVertex3f(0.64f, 0.496f, 0.0f);
	//point J
	glVertex3f(0.702f, 0.51f, 0.0f);
	//point K
	glVertex3f(0.744f, 0.463f, 0.0f);
	//point L
	glVertex3f(0.747f, 0.398f, 0.0f);
	//point M
	glVertex3f(0.715f, 0.328f, 0.0f);
	//point N
	glVertex3f(0.684f, 0.257f, 0.0f);
	//point O
	glVertex3f(0.6f, 0.2f, 0.0f);
	//point P
	glVertex3f(0.613f, 0.57f, 0.0f);
	//point Q
	glVertex3f(0.656f, 0.65f, 0.0f);
	//point R
	glVertex3f(0.72f, 0.732f, 0.0f);
	
	glEnd();
	glFlush();
}

void display(){
	cherry();
}

int main(int argc, char* argv[]) { 
	glClear (GL_COLOR_BUFFER_BIT);
	glutInit(&argc, argv);
	glutInitWindowSize (640,480);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Cherry on Top");
	glutDisplayFunc (display);
	glClearColor(1.0f, 1.0f, 0.4f, 1.0f); 
	glutMainLoop();
	return 0;
}
