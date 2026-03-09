 #include <GL/glut.h>
   //Nama: Anggita Kirana Puspa
   //NIM: 24060124130064
   //Lab: E2
 
 void ketupats() {
 	glClear(GL_COLOR_BUFFER_BIT);
 	glLineWidth(5.0f);
 	glBegin(GL_LINE_LOOP);
 	glColor3f(0.443f, 0.725f, 0.263f);
 	
 	//point A
 	glVertex3f(-0.40f, 0.20f, 0.0f);
 	//point B
 	glVertex3f(-0.20f, 0.40f, 0.0f);
 	//point C
 	glVertex3f(0.0f, 0.20f, 0.0f);
 	//point D 
 	glVertex3f(0.20f, 0.40f, 0.0f);
 	//point E
 	glVertex3f(0.40f, 0.20f, 0.0f);
 	//point G
 	glVertex3f(0.20f, 0.0f, 0.0f);
 	//point C lagi
 	glVertex3f(0.0f, 0.20f, 0.0f);
 	//point F
 	glVertex3f(-0.20f, 0.0f, 0.0f);
 	
 	glEnd();
 	glFlush();
 }
 
 void display(){
 	ketupats();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (640,480);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Ketupat");
 	glutDisplayFunc (display);
 	glClearColor(0.153f, 0.318f, 0.169f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }
