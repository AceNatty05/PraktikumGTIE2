/* Nama File : Snowflake.cpp
 * Deskripsi : Mengenerate gambar dengan bangun dasar primitif, 
			   serta melakukan transformasi translasi, rotasi, dan push/pop matrix menggunakan library glut
 * Pembuat   : Rafif Setya Imaduddin (24060124130115)
 * Tanggal   : 9 Maret 2026
 */

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

// Kamus Global
const float Pi = 3.14159f;

void Snowflake(float Radius, int Segments) {
	// Kamus Lokal
	int i;
	float Angle;
	
	// Algoritma
	Angle = 360.0f / Segments;
	
	for (i = 0; i < Segments; i++) {
		glPushMatrix();
			// Transformasi - Rotasi
			glRotatef(Angle * i, 0.0f, 0.0f, 1.0f);
			
			// Body - Bottom
			glBegin(GL_LINES);
				glColor3f(0.5f ,0.7f, 0.9f);
				glVertex2f(0.0f, 0.0f);
				glVertex2f(0.0f, 0.1f);
			glEnd();
			
			// Body - Top
			glBegin(GL_LINES);
				glColor3f(0.5f ,0.7f, 0.9f);
				glVertex2f(0.0f, 0.2f);
				glVertex2f(0.0f, Radius);
			glEnd();
			
			// Branch - Main Right
			glBegin(GL_LINES);
				glVertex2f(0.0f, Radius * 0.7f);
				glVertex2f(Radius * 0.15f, Radius * 0.95f);
			glEnd();
			
			// Branch - Main Left
			glBegin(GL_LINES);
				glVertex2f(0.0f, Radius * 0.7f);
				glVertex2f(Radius * (-0.15f), Radius * 0.95f);
			glEnd();
			
			// Branch - Mini Left
			glBegin(GL_LINES);
				glColor3f(0.6f ,0.8f, 1.0f);
				glVertex2f(0.0f, Radius * 0.7f);
				glVertex2f(Radius * (-0.07f), Radius * 0.9f);
			glEnd();
			
			// Branch - Mini Right
			glBegin(GL_LINES);
				glVertex2f(0.0f, Radius * 0.7f);
				glVertex2f(Radius * (0.07f), Radius * 0.9f);
			glEnd();

			// Inner - Bottom
			glBegin(GL_LINES);
					glColor3f(0.5f ,0.7f, 0.9f);
				glVertex2f(Radius * (-0.085f), 0.1f);
				glVertex2f(Radius * (0.085f), 0.1f);
			glEnd();
			
			// Inner - Top
			glBegin(GL_LINES);
				glVertex2f(Radius * (-0.175f), 0.2f);
				glVertex2f(Radius * (0.175f), 0.2f);
			glEnd();
			
			// Triangle -  Right
			glBegin(GL_TRIANGLES);
				glColor3f(0.6f ,0.8f, 1.0f);
				glVertex2f(Radius * (-0.04f), 0.2f);
				glVertex2f(Radius * (0.04f), 0.2f);
				glVertex2f(0.2f, -0.3f);
			glEnd();
			
			// Triangle - Left
			glBegin(GL_TRIANGLES);
				glColor3f(0.5f ,0.7f, 0.9f);
				glVertex2f(Radius * (-0.04f), 0.2f);
				glVertex2f(Radius * (0.04f), 0.2f);
				glVertex2f(-0.2f, -0.3f);
			glEnd();
			
			// Triangle - Outer
			glBegin(GL_TRIANGLES);
				glColor3f(0.6f ,0.8f, 1.0f);
				glVertex2f(Radius * (-0.06f), 0.205f);
				glVertex2f(Radius * (0.06f), 0.205f);
				glVertex2f(0.0f, 0.3f);
			glEnd();

		glPopMatrix();
	}	
}

void display() {
	// Kamus Lokal
	
	// Algoritma
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
		glLineWidth(5.0f);
		Snowflake(0.5f, 8);
	glPopMatrix();
	
	glFlush();
}

int main(int argc, char* argv[]) {
	// Kamus
	
	// Algoritma
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Snowflake Biru");
	glutDisplayFunc(display);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glutMainLoop();
	
	return 0;
}
