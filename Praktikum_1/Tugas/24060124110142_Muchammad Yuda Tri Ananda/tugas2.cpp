// NAMA  : Muchammad Yuda Tri Ananda
// NIM   : 24060124110142
// KELAS : E
// 2. buatlah program yang memanfaatkan fungsi GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP, GL_QUADS, dan GL_QUAD_STRIP.

#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846f;

void drawLineStrip()
{
	glColor3f(1.0f, 0.4f, 0.4f);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.90f, 0.65f);
	glVertex2f(-0.75f, 0.78f);
	glVertex2f(-0.60f, 0.62f);
	glVertex2f(-0.45f, 0.76f);
	glVertex2f(-0.30f, 0.60f);
	glEnd();
}

void drawLineLoop()
{
	glColor3f(0.4f, 1.0f, 0.5f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.15f, 0.60f);
	glVertex2f(0.35f, 0.78f);
	glVertex2f(0.55f, 0.70f);
	glVertex2f(0.52f, 0.50f);
	glVertex2f(0.25f, 0.45f);
	glEnd();
}

void drawTriangleFan()
{
	float centerX = -0.62f;
	float centerY = 0.00f;
	float radius = 0.20f;
	int segments = 24;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.9f, 0.3f);
	glVertex2f(centerX, centerY);
	for (int i = 0; i <= segments; ++i) {
		float angle = 2.0f * PI * i / segments;
		float x = centerX + radius * std::cos(angle);
		float y = centerY + radius * std::sin(angle);
		glColor3f(1.0f, 0.6f, 0.2f);
		glVertex2f(x, y);
	}
	glEnd();
}

void drawTriangleStrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.4f, 0.8f, 1.0f);
	glVertex2f(-0.05f, 0.20f);
	glVertex2f(0.05f, -0.10f);

	glColor3f(0.2f, 0.6f, 1.0f);
	glVertex2f(0.20f, 0.24f);
	glVertex2f(0.30f, -0.06f);

	glColor3f(0.1f, 0.4f, 0.9f);
	glVertex2f(0.45f, 0.18f);
	glVertex2f(0.55f, -0.08f);
	glEnd();
}

void drawQuads()
{
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.3f, 1.0f);
	glVertex2f(-0.90f, -0.35f);
	glVertex2f(-0.55f, -0.35f);
	glVertex2f(-0.55f, -0.70f);
	glVertex2f(-0.90f, -0.70f);
	glEnd();
}

void drawQuadStrip()
{
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.3f, 1.0f, 0.95f);
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.05f, -0.75f);

	glColor3f(0.2f, 0.9f, 0.8f);
	glVertex2f(0.20f, -0.30f);
	glVertex2f(0.20f, -0.70f);

	glColor3f(0.1f, 0.75f, 0.7f);
	glVertex2f(0.35f, -0.38f);
	glVertex2f(0.35f, -0.78f);

	glColor3f(0.05f, 0.55f, 0.6f);
	glVertex2f(0.50f, -0.32f);
	glVertex2f(0.50f, -0.72f);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3.0f);

	drawLineStrip();
	drawLineLoop();
	drawTriangleFan();
	drawTriangleStrip();
	drawQuads();
	drawQuadStrip();

	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(900, 650);
	glutCreateWindow("Tugas 2 - myudakk");

	glClearColor(0.08f, 0.08f, 0.12f, 1.0f);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}


