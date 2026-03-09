/* Nama File : Lingkaran.cpp
 * Deskripsi : Mengenerate bangun dasar lingkaran dengan
			   memanfaatkan teori lingkaran matematika
 * Pembuat   : Rafif Setya Imaduddin (24060124130115)
 * Tanggal   : 9 Maret 2026
 */

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

// Kamus Global
const float Pi = 3.14159f;

void Lingkaran(float Radius, int Segments) {
	// Kamus Lokal
	int i;
	float Angle;
	
	// Algoritma	
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < Segments; i++) {
		Angle = 2.0f * Pi * i / Segments;
		glVertex2f(Radius * cos(Angle), Radius * sin(Angle));
	}
	glEnd();
}

void display() {
	// Kamus Lokal
	
	// Algoritma
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glLineWidth(6.7f);
		Lingkaran(0.67f, 500);
	glPopMatrix();

	glFlush();
}

int main(int argc, char* argv[]) {
	// Kamus
	
	// Algoritma
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Lingkaran Putih");
	glutDisplayFunc(display);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	
	return 0;
}
