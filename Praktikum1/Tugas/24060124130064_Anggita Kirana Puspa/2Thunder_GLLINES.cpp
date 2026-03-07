#include <GL/glut.h>
// Nama: Anggita Kirana Puspa
// NIM: 24060124130064
// Lab: E2

void thunder() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glColor3f(0.929f, 0.863f, 0.329f);
	
	//Garis1
	glVertex3f(-0.26f, 0.31f, 0.0f);
	glVertex3f(0.08f, 0.55f, 0.0f);
	
	//Garis2
	glVertex3f(-0.26f, 0.31f, 0.0f);
	glVertex3f(-0.30f, -0.40f, 0.0f);
	
	//Garis3
	glVertex3f(-0.30f, -0.40f, 0.0f);
	glVertex3f(-0.09f, -0.25f, 0.0f);
	
	//Garis4
	glVertex3f(-0.09f, -0.25f, 0.0f);
	glVertex3f(-0.19f, -0.84f, 0.0f);
	
	//Garis5
	glVertex3f(-0.19f, -0.84f, 0.0f);
	glVertex3f(0.14f, 0.0f, 0.0f);
	
	//Garis6
	glVertex3f(0.14f, 0.0f, 0.0f);
	glVertex3f(-0.07f, -0.05f, 0.0f);
	
	//Garis7
	glVertex3f(-0.07f, -0.05f, 0.0f);
	glVertex3f(0.08f, 0.55f, 0.0f);
	
	glEnd();
	glFlush();
}

void display(){
	thunder();
}

int main(int argc, char* argv[]) { 
	glClear (GL_COLOR_BUFFER_BIT);
	glutInit(&argc, argv);
	glutInitWindowSize (640,480);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Thunder");
	glutDisplayFunc (display);
	glClearColor(0.27f, 0.43f, 0.56f, 1.0f); 
	glutMainLoop();
	return 0;
}
