 #include <GL/glut.h>
 #include <math.h>

// Nama: Anggita Kirana Puspa
// NIM: 24060124130064
// Lab: E2

 void satuLingkaran(){
 	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(0.267f, 0.722f, 0.874f);
 	glLineWidth(6.0f);
 	
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
 	satuLingkaran();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (600,600);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Satu Lingkaran");
 	glutDisplayFunc (display);
 	glClearColor(0.404f, 0.227f, 0.792f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }

