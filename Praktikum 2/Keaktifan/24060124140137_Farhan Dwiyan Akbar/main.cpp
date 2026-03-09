// Nama	: Farhan Dwiyan Akbar
// NIM	: 24060124140137

#include <gl/glut.h>

int sisi = 8;   

void snowFlake(){
	float sudut = 360.0 / sisi;
	
	for (int i = 0; i < sisi; i++) {
		glPushMatrix();
		
		glRotatef(i * sudut, 0, 0, 1);
		
		glBegin(GL_LINES);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.8, 0.0);
		
		glVertex2f(0.2, 0.0);
		glVertex2f(0.4, 0.2);
		
		glVertex2f(0.2, 0.0);
		glVertex2f(0.4, -0.2);
		
		glVertex2f(0.4, 0.0);
		glVertex2f(0.6, 0.2);	
		
		glVertex2f(0.4, 0.0);
		glVertex2f(0.6, -0.2);		
		
		glVertex2f(0.6, 0.0);
		glVertex2f(0.8, 0.2);
		
		glVertex2f(0.6, 0.0);
		glVertex2f(0.8, -0.2);
		
		glEnd();
		
		glPopMatrix();
	}
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1); 
    snowFlake();

    glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Snowflake");
	glutDisplayFunc(display);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutMainLoop();
	return 0;
}
