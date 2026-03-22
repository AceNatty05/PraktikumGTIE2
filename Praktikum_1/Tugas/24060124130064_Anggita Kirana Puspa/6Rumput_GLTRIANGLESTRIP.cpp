 #include <GL/glut.h>
   //Nama: Anggita Kirana Puspa
   //NIM: 24060124130064
   //Lab: E2
 
 void rumput() {
 	glClear(GL_COLOR_BUFFER_BIT);
 
 	glColor3f(0.11f, 0.45f, 0.27f);
 
 	glBegin(GL_TRIANGLE_STRIP);
 	
 	glVertex3f(-0.8f, -0.8f, 0.0f);
 	glVertex3f(-0.7f, -0.2f, 0.0f);
 	
 	glVertex3f(-0.2f, -0.8f, 0.0f);
 	glVertex3f(-0.1f, -0.25f, 0.0f);
 	
 	glVertex3f(0.1f, -0.8f, 0.0f);
 	glVertex3f(0.2f, -0.15f, 0.0f);
 	
 	glVertex3f(0.4f, -0.8f, 0.0f);
 	glVertex3f(0.5f, -0.2f, 0.0f);
 	
 	glVertex3f(0.7f, -0.8f, 0.0f);
 	glVertex3f(0.8f, -0.1f, 0.0f);
 		
 	glEnd();
 	glFlush();
 }
 
 void display(){
 	rumput();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (640,480);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Rumput");
 	glutDisplayFunc (display);
 	glClearColor(0.173f, 0.118f, 0.039f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }
