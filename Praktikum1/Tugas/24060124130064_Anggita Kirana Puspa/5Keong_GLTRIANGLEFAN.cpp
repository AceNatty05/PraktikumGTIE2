 #include <GL/glut.h>
   //Nama: Anggita Kirana Puspa
   //NIM: 24060124130064
   //Lab: E2
 
 void keong() {
 	glClear(GL_COLOR_BUFFER_BIT);
 
 	glBegin(GL_TRIANGLE_FAN);
 	glColor3f(0.373f, 0.231f, 0.063f);
 	
 	//pusat
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	
 	glVertex3f(0.0f, -0.75f, 0.0f);
 	glVertex3f(0.5f, -0.75f, 0.0f);
 	glVertex3f(0.75f, -0.5f, 0.0f);
 	glVertex3f(0.875f, -0.125f, 0.0f);
 	glVertex3f(0.75f, 0.25f, 0.0f);
 	glVertex3f(0.5f, 0.5f, 0.0f);
 	glVertex3f(0.0f, 0.625f, 0.0f);
 	glVertex3f(-0.5f, 0.5f, 0.0f);
 	glVertex3f(-0.75f, 0.25f, 0.0f);
 	
 	glEnd();
 	
 	//buat garis pemisah antar segitiga
 	glColor3f(0.0f, 0.0f, 0.0f); 
 	glLineWidth(2);
 	glBegin(GL_LINES);
 	
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(0.0f, -0.75f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(0.5f, -0.75f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(0.75f, -0.5f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(0.875f, -0.125f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(0.75f, 0.25f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(0.5f, 0.5f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(0.0f, 0.625f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(-0.5f, 0.5f, 0.0f);
 
 	glVertex3f(0.0f, 0.0f, 0.0f);
 	glVertex3f(-0.75f, 0.25f, 0.0f);
 	
 	glEnd();
 	glFlush();
 }
 
 void display(){
 	keong();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (640,480);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Keong");
 	glutDisplayFunc (display);
 	glClearColor(0.173f, 0.118f, 0.039f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }
