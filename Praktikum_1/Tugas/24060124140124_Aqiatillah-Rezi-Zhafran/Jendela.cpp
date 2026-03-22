#include <gl/glut.h> 
void Jendela (void) {
	// Bersihiin layar & set dlam format warna
	glClear(GL_COLOR_BUFFER_BIT);
	// Memastikan seluruh perintah tereksekusi
	glFlush();
	
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize (640,480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("biru");
	glutDisplayFunc(Jendela);
	glClearColor(0.0f,0.0f,1.0f,1.0f);
	glutMainLoop();
	
	return 0;
}
