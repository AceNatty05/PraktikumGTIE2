/* Nama File : fungsiGluts.cpp
 * Deskripsi : Menampilkan fungsi-fungsi Glut
 * Pembuat   : Rafif Setya Imaduddin (24060124130115)
 * Tanggal   : 7 Maret 2026
 */

#include <GL/glut.h>

// Kamus Global
int Mode;
const int totalMode = 8;

void timer(int Value) {
	// Kamus Lokal

	// Algoritma
	Mode = (Mode + 1) % totalMode;
	
	glutPostRedisplay();
	glutTimerFunc(1000, timer, 0);
}

void fungsi() {
	// Kamus Lokal

	// Algoritma
    glClear(GL_COLOR_BUFFER_BIT);
    // > Garis
    glColor3f(0.5f, 0.0f, 1.0f);
    glLineWidth(4.0);
	
	// > Perpindahan Mode
	switch (Mode) {
		case 0:
			glBegin(GL_LINE_STRIP);
			break;
		case 1:
			glBegin(GL_LINE_LOOP);
			break;
		case 2:
			glBegin(GL_TRIANGLE_FAN);
			break;
		case 3:
			glBegin(GL_TRIANGLE_STRIP);
			break;
		case 4:
			glBegin(GL_QUADS);
			break;
		case 5:
			glBegin(GL_QUAD_STRIP);
			break;
		case 6:
			glPointSize(5.0f);
			glBegin(GL_POINTS);
			break;
		case 7:
			glBegin(GL_LINES);
			break;
	}
	
	// > Vertex 
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    
    if (Mode >= 2) {
    	glVertex2f(-0.2f, 0.8f);
    	glVertex2f(0.2f, 0.8f);
    }
    
    glEnd();
    glFlush();
	    
}

int main(int argc, char* argv[]) {
	// Kamus

	// Algoritma
    glutInit(&argc, argv);
    
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("List of Fungsi Gluts");
    
    glutDisplayFunc(fungsi);
    
    glutTimerFunc(1000, timer, 0);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    
    return 0;
}

