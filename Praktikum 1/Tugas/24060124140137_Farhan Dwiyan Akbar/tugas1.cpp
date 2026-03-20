#include <GL/glut.h>

// Nama	: Farhan Dwiyan Akbar
// NIM	: 24060124140137

void badan(){
	glBegin(GL_QUADS);
	glVertex2f(-0.2, 0.4);
	glVertex2f(0.2, 0.4);
	glVertex2f(0.2, -0.2);
	glVertex2f(-0.2, -0.2);
	glEnd();
}

void kepala(){
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.1, 0.6);
	glVertex2f(0.1, 0.6);
	glVertex2f(0.1, 0.4);
	glVertex2f(-0.1, 0.4);
	glEnd();
}

void tanganKanan(){
	glBegin(GL_QUAD_STRIP);
	glVertex2f(0.2, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.5, 0.3);
	
	glVertex2f(0.5, 0.2);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.2, 0.2);
	glEnd();
}

void tanganKiri(){
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-0.2, 0.3);
	glVertex2f(-0.4, 0.3);
	glVertex2f(-0.5, 0.3);
	
	glVertex2f(-0.5, 0.2);
	glVertex2f(-0.4, 0.2);
	glVertex2f(-0.2, 0.2);
	glEnd();
}

void kakiKanan(){
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(0.2, -0.2);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.1, -0.3);
	glVertex2f(0.1, -0.4);
	glVertex2f(0.3, -0.4);
	glVertex2f(0.05, -0.3);
	glEnd();
}

void kakiKiri(){
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.2, -0.2);
	glVertex2f(-0.1, -0.2);
	glVertex2f(-0.1, -0.3);
	glVertex2f(-0.1, -0.4);
	glVertex2f(-0.3, -0.4);
	glVertex2f(-0.05, -0.3);
	glEnd();
}

void tongkat(){
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.45, -0.4);
	glVertex2f(0.45, 0.65);
	glEnd();
}

void kepalaTongkat(){
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.45, 0.65);  
	glVertex2f(0.4, 0.7);
	glVertex2f(0.5, 0.7);
	glVertex2f(0.45, 0.75);
	glVertex2f(0.4, 0.7);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	badan();
	kepala();
	tanganKanan();
	tanganKiri();
	kakiKanan();
	kakiKiri();
	tongkat();
	kepalaTongkat();
	glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Membuat Robot");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();
    return 0;
}
