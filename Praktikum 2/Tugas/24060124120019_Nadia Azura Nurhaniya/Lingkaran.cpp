// Nama : Nadia Azura Nurhaniya
// NIM : 24060124120019
// Deskripsi : Membuat lingkaran 

 #include <GL/glut.h>
 #include <math.h>

 void Lingkaran(){
 	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(0.0f, 0.0f, 0.8f);
 	glLineWidth(5.0f);
 	
 	glPushMatrix();
 	glBegin(GL_LINE_LOOP);
 		GLint circle_points = 100;
 		static double PI = 3.14159265;
 		for (int i = 0; i < circle_points; i++){
 			float angle = 2 * PI * i/ circle_points;
 			glVertex2f(cos(angle), sin(angle));
 		}
 		glEnd();
 	glPopMatrix();
 	
 	glFlush();
 }
 
 void display(){
 	Lingkaran();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (600,600);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Gambar Lingkaran");
 	glutDisplayFunc (display);
 	glClearColor(1.0f, 1.0f, 0.7f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }
