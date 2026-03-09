 #include <GL/glut.h>
   //Nama: Anggita Kirana Puspa
   //NIM: 24060124130064
   //Lab: E2
 
 void kapal() {
 	glClear(GL_COLOR_BUFFER_BIT);
 
 	//buat laut
 	glColor3f(0.2f, 0.5f, 0.9f);
 	glBegin(GL_QUADS);
 	
 	glVertex3f(-1.0f, -0.4f, 0.0f);
 	glVertex3f(-1.0f, -1.0f, 0.0f);
 	glVertex3f(1.0f, -1.0f, 0.0f);
 	glVertex3f(1.0f, -0.4f, 0.0f);
 	glEnd();
 	
 	//buat badan kapal
 	glColor3f(0.5f, 0.25f, 0.1f);
 	glBegin(GL_QUADS);
 	
 	glVertex3f(-0.6f, 0.0f, 0.0f);
 	glVertex3f(-0.4f, -0.4f, 0.0f);
 	glVertex3f(0.4f, -0.4f, 0.0f);
 	glVertex3f(0.6f, 0.0f, 0.0f);
 	glEnd();
 	
 	//buat tiang
 	glColor3f(0.3f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-0.02f, 0.0f, 0.0f);
    glVertex3f( 0.02f, 0.0f, 0.0f);
    glVertex3f( 0.02f, 0.6f, 0.0f);
    glVertex3f(-0.02f, 0.6f, 0.0f);
    glEnd();
     
    //buat bendera
    glColor3f(0.859f, 0.157f, 0.157f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.02f, 0.6f, 0.0f);
    glVertex3f(0.4f, 0.4f, 0.0f);
    glVertex3f(0.02f, 0.4f, 0.0f);
    glEnd();
 	glFlush();
 }
 
 void display(){
 	kapal();
 }
 
 int main(int argc, char* argv[]) { 
 	glClear (GL_COLOR_BUFFER_BIT);
 	glutInit(&argc, argv);
 	glutInitWindowSize (640,480);
 	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
 	glutCreateWindow("Kapal");
 	glutDisplayFunc (display);
 	glClearColor(0.57f, 0.91f, 0.98f, 1.0f); 
 	glutMainLoop();
 	return 0;
 }
