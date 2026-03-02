// NAMA  : Muchammad Yuda Tri Ananda
// NIM   : 24060124110142
// KELAS : E
// Tugas : 1. Selain membuat titik menggunakan GL_POINT, garis menggunakan GL_LINES

#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846f;

void lingkarann(float centerX, float centerY, float radius, int segments)
{
	glBegin(GL_LINES);
	for (int i = 0; i < segments; i++) {
		float angle1 = 2.0f * PI * i / segments;
		float angle2 = 2.0f * PI * (i + 1) / segments;

		float x1 = centerX + radius * std::cos(angle1);
		float y1 = centerY + radius * std::sin(angle1);
		float x2 = centerX + radius * std::cos(angle2);
		float y2 = centerY + radius * std::sin(angle2);

		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	}
	glEnd();
}

void displayy()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2.0f);
	lingkarann(0.0f, 0.0f, 0.6f, 120);

	glColor3f(0.2f, 0.8f, 1.0f);
	lingkarann(-0.2f, 0.15f, 0.1f, 40);
	lingkarann(0.2f, 0.15f, 0.1f, 40);

	glPointSize(6.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex2f(-0.2f, 0.15f);
	glVertex2f(0.2f, 0.15f);
	glEnd();

	glColor3f(1.0f, 0.8f, 0.2f);
	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.1f);
	glVertex2f(-0.04f, -0.1f);

	glVertex2f(-0.04f, -0.1f);
	glVertex2f(0.04f, -0.1f);
	glEnd();

	glColor3f(1.0f, 0.4f, 0.6f);
	glBegin(GL_LINES);
	glVertex2f(-0.25f, -0.25f);
	glVertex2f(-0.15f, -0.32f);

	glVertex2f(-0.15f, -0.32f);
	glVertex2f(-0.05f, -0.35f);

	glVertex2f(-0.05f, -0.35f);
	glVertex2f(0.05f, -0.35f);

	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.15f, -0.32f);

	glVertex2f(0.15f, -0.32f);
	glVertex2f(0.25f, -0.25f);
	glEnd();

	glPointSize(3.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	for (float x = -0.45f; x <= 0.45f; x += 0.04f) {
		glVertex2f(x, 0.62f);
	}
	glEnd();

	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Tugas 1 - myudakk");

	glClearColor(0.05f, 0.05f, 0.12f, 1.0f);
	glutDisplayFunc(displayy);

	glutMainLoop();
	return 0;
}

