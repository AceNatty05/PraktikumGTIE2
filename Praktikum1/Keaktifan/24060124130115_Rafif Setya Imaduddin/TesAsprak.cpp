/* Nama File : perempuanUngu.cpp
 * Deskripsi : Mengenerate gambar dengan bangun dasar primitif dari fungsi openGL Glut
 * Pembuat   : Rafif Setya Imaduddin (24060124130115)
 * Tanggal   : 2 Maret 2026
 */

#include <GL/glut.h>

void head(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // == Wajah ==
    	// Krem
    glColor3f(1.0f, 0.9f, 0.8f);
    glRectf(-0.5, -0.6, 0.6, 0.6);
    glFlush();
    
    // == Mata 1 ==
		// Putih
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.18, 0.18, 0.18, -0.18);
    glFlush();
    
    	// Ijo
    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(0.0, -0.2, 0.2, 0.2);
    glFlush();
    
    // == Mata 2 ==
    	// Putih
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(0.4, 0.18, 0.68, -0.18);
    glFlush();
    
    	// Ijo
   	glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(0.5, -0.2, 0.7, 0.2);
    glFlush();
    
    // == Rambut ==
		// Ungu Main
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(-0.6, 0.3, 0.7, 0.7);
	glFlush();
	
		// Ungu Top
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(-0.4, 0.7, 0.5, 0.8);
	glFlush();
	
		// Ungu Bang 1
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(0.7, 0.6, 0.8, -0.4);
	glFlush();
	
		// Ungu Side Bang 1
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(0.6, 0.4, 0.8, 0.2);
	glFlush();
	
		// Ungu Bang 2
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(-0.3, 0.6, -0.2, -0.4);
	glFlush();
	
		// Ungu Side Bang 2
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(-0.2, 0.4, 0.0, 0.2);
	glFlush();
	
		// Ungu Front Bang
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(0.3, 0.6, 0.4, 0.0);
	glFlush();
	
		// Ungu Front Bang 2
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(0.25, 0.1, 0.35, -0.2);
	glFlush();
	
		// Ungu Front Bang 3
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(0.2, -0.2, 0.3, -0.5);
	glFlush();
	
		// Ungu Back
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(-0.7, 0.4, -0.3, -0.7);
	glFlush();
	
		// Ungu Bun
	glColor3f(0.5f, 0.0f, 1.0f);
	glRectf(-0.9, 0.2, -0.7, -0.2);
	glFlush();
	    
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Cewe Ungu");
    glutDisplayFunc(head);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}


