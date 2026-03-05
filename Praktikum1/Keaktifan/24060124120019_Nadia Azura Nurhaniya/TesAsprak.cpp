#include <GL/glut.h>

void Jendela() {
    // membersihkan layar dan men-set dalam format warna
    glClear(GL_COLOR_BUFFER_BIT);

    // memastikan seluruh perintah tereksekusi
    glFlush();
}

void point() { 
	glClear (GL_COLOR_BUFFER_BIT);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f( 0.0f, 0.9f, 0.0f);
	glEnd(); 
	glFlush();
}

void Garis() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0,  -1.0, 0.0);
        glVertex3f(1.0, 1.0, 1.0);
    glEnd();

    glFlush();
}

void Segitiga()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.10, -0.10, 0.00);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.10, -0.10, 0.00);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.00, 0.10, 0.00);
    glEnd();

    glFlush();
}

void SegiEmpat()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.18,  0.18,  0.18, -0.18);

    glFlush();
}

void segiempat5() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5f, 0.0f, 0.7f);
    glRectf(-0.50, -0.50,  0.50,  0.50);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.40, -0.40,  0.40,  0.40);

    glColor3f(0.5f, 0.0f, 0.7f);
    glRectf(-0.30, -0.30,  0.30,  0.30);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.20, -0.20,  0.20,  0.20);

    glColor3f(0.5f, 0.0f, 0.7f);
    glRectf(-0.10, -0.10,  0.10,  0.10);

    glFlush();
}

void display(){
	segiempat5();
}

int main(int argc, char* argv[]) { 
	glClear (GL_COLOR_BUFFER_BIT);
	glutInit(&argc, argv);
	glutInitWindowSize (640,480);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Lima Segiempat");
	glutDisplayFunc (display);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); 
	glutMainLoop();
	return 0;
}

