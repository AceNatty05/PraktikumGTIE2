 #include <GL/glut.h>
   //Nama: Anggita Kirana Puspa
   //NIM: 24060124130064
   //Lab: E2
 
 void erlenmeyer() {
 	glClear(GL_COLOR_BUFFER_BIT);
 
 	//buat erlenmeyer
 	glColor3f(0.2f, 0.5f, 0.9f);
 	glBegin(GL_QUAD_STRIP);
 	
 	glVertex3f(-0.2f, 0.4f, 0.0f);
 	glVertex3f(0.2f, 0.4f, 0.0f);
 	glVertex3f(-0.2f, 0.2f, 0.0f);
 	glVertex3f(0.2f, 0.2f, 0.0f);
 	glVertex3f(-0.6f, -0.4f, 0.0f);
 	glVertex3f(0.6f, -0.4f, 0.0f);
 	
 	glEnd();
 	glFlush();
 }
 
 void display(){
 	erlenmeyer();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (640,480);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Erlenmeyer");
 	glutDisplayFunc (display);
 	glClearColor(0.57f, 0.91f, 0.98f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }
