#include <GL/glut.h>
//	Nama: Anggita Kirana Puspa
//   	NIM: 24060124130064
//   	Lab: E2
 
 void crown() {
 	glClear(GL_COLOR_BUFFER_BIT);
 	glLineWidth(5.0f);
 	glBegin(GL_LINE_STRIP);
 	glColor3f(0.92f, 0.68f, 0.36f);
 	
 	glVertex3f(-0.90f, 0.20f, 0.0f);
 	glVertex3f(-0.55f, 0.60f, 0.0f);
 	glVertex3f(-0.15f, 0.20f, 0.0f);
 	glVertex3f(0.15f, 0.20f, 0.0f);
 	glVertex3f(0.55f, 0.60f, 0.0f);
 	glVertex3f(0.90f, 0.20f, 0.0f);
 	glVertex3f(0.50f, -0.90f, 0.0f);
 	glVertex3f(-0.50f, -0.90f, 0.0f);
 	glVertex3f(-0.90f, 0.20f, 0.0f);
 	
 	
 	glEnd();
 	glFlush();
 }
 
 void display(){
 	crown();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (800,600);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Crown");
 	glutDisplayFunc (display);
 	glClearColor(0.922f, 0.506f, 0.361f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }
