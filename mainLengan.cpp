/* Nama : Akmal Dzaki Rahmatullah
   NIM  : 24060124140151
   Lab  : E2
 
	Key : -> shoulder = s, S
		  -> elbow = e, E	
		  -> Jempol = q, Q, r, y
		  -> Telunjuk = u, U, i, I, o, O	
		  -> Tengah = b,B, p, P, a, A
		  -> Manis = d, D, f, F, h, H
		  -> Kelingking = h, H, j, J, k, K				  
*/
#include <GL/glut.h>   
static int shoulder = 0, elbow = 0, telapaktangan = 0,
jempol1 = 0, jempol2 = 0,
telunjuk1 = 0, telunjuk2 = 0, telunjuk3 = 0,
tengah1 = 0, tengah2 = 0, tengah3 = 0,
manis1 = 0, manis2 = 0, manis3 = 0,
kelingking1 = 0, kelingking2 = 0, kelingking3 = 0;
   
 void init(void) {   
    glClearColor (0.0, 0.0, 0.0, 0.0);        
	glShadeModel (GL_FLAT);   
 }   
   
 void display(void) {   
    glClear (GL_COLOR_BUFFER_BIT);        
	glPushMatrix();
	
	//Pundak   
    glTranslatef (-3.0, 0.0, 0.0);   
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);            
	glTranslatef (1.0, 0.0, 0.0);      
	      
	glPushMatrix();             
	glScalef (2.0, 0.4, -0.2);                
	glutWireCube (1.0);            
	glPopMatrix();   
	
	//sikut
    glTranslatef (1.0, 0.0, 0.0);   
	glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);            
	glTranslatef (1.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (2.0, 0.4, -0.2);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	//telapak tangan
	glTranslatef (0.25, 0.0, 0.0);   
	glRotatef ((GLfloat) telapaktangan, 0.0, 0.0, 1.0);            
	glTranslatef (1.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.5, 0.6, -0.02);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	//Jari Jempol1
	
	glPushMatrix();
	
	glTranslatef (0.00, 0.37, 0.0);   
	glRotatef ((GLfloat) jempol1, 0.0, 0.0, 1.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.17, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();        
	
	//Jari Jempol2
	
	glPushMatrix();
	
	glTranslatef (0.20, 0.0, 0.0);   
	glRotatef ((GLfloat) jempol2, 0.0, 0.0, 1.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.22, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	glPopMatrix();
	
	glPopMatrix();
	
	//telunjuk1
	
	glPushMatrix();
	
	glTranslatef (0.33, 0.22, 0.0);   
	glRotatef ((GLfloat) telunjuk1, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.15, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();  
	    
	//telunjuk2
	
	glPushMatrix();
	
	glTranslatef (0.18, 0.0, 0.0);   
	glRotatef ((GLfloat) telunjuk2, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();   
	
	//telunjuk3
	glTranslatef (0.20, 0.0, 0.0);   
	glRotatef ((GLfloat) telunjuk3, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);
	
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();  
	
	glPopMatrix();
	glPopMatrix();
	
	//tengah1
	
	glPushMatrix();
	
	glTranslatef (0.355, 0.07, 0.0);   
	glRotatef ((GLfloat) tengah1, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();        
	
	//tengah2
	
	glPushMatrix();
	
	glTranslatef (0.20, 0.0, 0.0);   
	glRotatef ((GLfloat) tengah2, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();       
	
	//tengah3
	glTranslatef (0.20, 0.0, 0.0);   
	glRotatef ((GLfloat) tengah3, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();     
	
	glPopMatrix(); 
	glPopMatrix();   
	     
	//manis1
	
	glPushMatrix();
	
	glTranslatef (0.33, -0.08, 0.0);   
	glRotatef ((GLfloat) manis1, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.15, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix(); 
	
	//manis2
	
	glPushMatrix();
	
	glTranslatef (0.18, 0.0, 0.0);   
	glRotatef ((GLfloat) manis2, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	//manis3
	glTranslatef (0.20, 0.0, 0.0);   
	glRotatef ((GLfloat) manis3, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);
	
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	glPopMatrix(); 
	glPopMatrix();
	
	//kelingking1
	
	glPushMatrix(); 
	
	glTranslatef (0.32, -0.23, 0.0);   
	glRotatef ((GLfloat) kelingking1, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.12, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix(); 
	
	//kelingking2
	
	glPushMatrix(); 
	
	glTranslatef (0.16, 0.0, 0.0);   
	glRotatef ((GLfloat) kelingking2, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	//kelingking3
	glTranslatef (0.20, 0.0, 0.0);   
	glRotatef ((GLfloat) kelingking3, 0.0, 1.0, 0.0);            
	glTranslatef (0.0, 0.0, 0.0);
	
	glPushMatrix();   
    glScalef (0.20, 0.15, -0.1);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	glPopMatrix();
	glPopMatrix();
	    
	glPopMatrix();        
	glutSwapBuffers(); 	  
 }   
   
 void reshape (int w, int h) {   
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);        
	glMatrixMode (GL_PROJECTION);       
	glLoadIdentity ();   
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);        
	glMatrixMode(GL_MODELVIEW);        
	glLoadIdentity();   
    glTranslatef (0.0, 0.0, -5.0);   
 }  
   
 void keyboard(unsigned char key, int x, int y) {        
	switch (key) {
	
	// Bahu   
	case 's': shoulder = (shoulder + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'S': shoulder = (shoulder - 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	// Sikut
	case 'e': elbow = (elbow + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'E': elbow = (elbow - 5) % 360;                    
	glutPostRedisplay();                    
	break; 
	
	// Jempol1 
	case 'q': jempol1 = (jempol1 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'Q': jempol1 = (jempol1 - 5) % 90;                    
	glutPostRedisplay();                    
	break; 
	
	// Jempol2
	case 't': jempol2 = (jempol2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'y': jempol2 = (jempol2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Telunjuk1
	case 'u': telunjuk1 = (telunjuk1 + 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	case 'U': telunjuk1 = (telunjuk1 - 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	// Telunjuk2
	case 'i': telunjuk2 = (telunjuk2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'I': telunjuk2 = (telunjuk2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Telunjuk3
	case 'o': telunjuk3 = (telunjuk3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'O': telunjuk3 = (telunjuk3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Tengah1
	case 'p': tengah1 = (tengah1 + 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	case 'P': tengah1 = (tengah1 - 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	// Tengah2
	case 'a': tengah2 = (tengah2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'A': tengah2 = (tengah2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Tengah3
	case 'b': tengah3 = (tengah3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'B': tengah3 = (tengah3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Manis1
	case 'd': manis1 = (manis1 + 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	case 'D': manis1 = (manis1 - 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	// Manis2
	case 'f': manis2 = (manis2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'F': manis2 = (manis2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Manis3
	case 'g': manis3 = (manis3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'G': manis3 = (manis3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Kelingking1
	case 'h': kelingking1 = (kelingking1 + 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	case 'H': kelingking1 = (kelingking1 - 5) % 180;                    
	glutPostRedisplay();                    
	break;
	
	// Kelingking2
	case 'j': kelingking2 = (kelingking2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'J': kelingking2 = (kelingking2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	// Kelingking3
	case 'k': kelingking3 = (kelingking3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'K': kelingking3 = (kelingking3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	 
	case 27: exit(0);                    
	break;               
	default: break;   
	}   
}   
int main(int argc, char** argv) {        
	glutInit(&argc, argv);   
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);        
	glutInitWindowSize (700, 600);        
	glutInitWindowPosition (100, 100);        
	glutCreateWindow (argv[0]);        
	init();   
	glutDisplayFunc(display);        
	glutReshapeFunc(reshape);        
	glutKeyboardFunc(keyboard);        
	glutMainLoop();        return 0;  
}
