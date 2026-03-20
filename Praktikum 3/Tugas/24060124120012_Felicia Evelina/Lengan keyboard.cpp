#include <GL/glut.h>   

// bahu = F, f
// siku = E, e
// telapak = L,l
// jempol = I, i, S, s, C,c
// telunjuk = A, a, N, n, T, t
// tengah = K, k, B, b, G, g
// manis = D, d, U, u, H, h
// kelingking = J, j, O, o, Y, y
static int shoulder = 0, elbow = 0, telapak = 0;
static int jempol1 = 0, jempol2 = 0, jempol3 = 0; 
static int telunjuk1 = 0, telunjuk2 = 0, telunjuk3 = 0;
static int tengah1 = 0, tengah2 = 0, tengah3 = 0;
static int manis1 = 0, manis2 = 0, manis3 = 0;   
static int kelingking1 = 0, kelingking2 = 0, kelingking3 = 0;  

void init(void) {   
   glClearColor (0.0, 0.0, 0.0, 0.0);        
	glShadeModel (GL_FLAT);   
}   
  
void display(void) {   
	// bahu
   glClear (GL_COLOR_BUFFER_BIT);        
	glPushMatrix();   
   glTranslatef (-1.0, 0.0, 0.0);   
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);            
	glTranslatef (1.0, 0.0, 0.0);      
	      
	glPushMatrix();             
	glScalef (2.0, 0.4, 1.0);                
	glutWireCube (1.0);            
	glPopMatrix();   
	// siku
   glTranslatef (1.0, 0.0, 0.0);   
	glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);            
	glTranslatef (1.0, 0.0, 0.0);       
	     
	glPushMatrix();   
   glScalef (2.0, 0.4, 1.0);                
	glutWireCube (1.0);            
	glPopMatrix();   
	// telapak
	glTranslatef (1.0, 0.0, 0.0);   
	glRotatef ((GLfloat) telapak, 0.0, 1.0, 0.0);            
	glTranslatef (0.5, 0.0, 0.0);       
	     
	glPushMatrix();   
   glScalef (0.8, 0.6, 0.2);                
	glutWireCube (1.0);            
	glPopMatrix();  
	// jempol
	glPushMatrix();
   glTranslatef(0.5, -0.2, 0.0); 
   glRotatef((GLfloat)kelingking1, 0.0, 1.0, 0.0);
   glTranslatef(0.1, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.2, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	
   glTranslatef(0.1, 0.0, 0.0);
   glRotatef((GLfloat)kelingking2, 0.0, 1.0, 0.0);
   glTranslatef(0.1, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.2, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
       
   glTranslatef(0.1, 0.0, 0.0);
   glRotatef((GLfloat)kelingking3, 0.0, 1.0, 0.0);
   glTranslatef(0.05, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.1, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	glPopMatrix();
  	// manis
	glPushMatrix();
   glTranslatef(0.5, -0.1, 0.0); 
   glRotatef((GLfloat)manis1, 0.0, 1.0, 0.0);
   glTranslatef(0.15, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.3, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)manis2, 0.0, 1.0, 0.0);
   glTranslatef(0.1, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.2, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
       
   glTranslatef(0.1, 0.0, 0.0);
   glRotatef((GLfloat)manis3, 0.0, 1.0, 0.0);
   glTranslatef(0.05, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.1, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	glPopMatrix();
	// tengah
	glPushMatrix();
   glTranslatef(0.5, 0.0, 0.0); 
   glRotatef((GLfloat)tengah1, 0.0, 1.0, 0.0);
   glTranslatef(0.2, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.4, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	
   glTranslatef(0.2, 0.0, 0.0);
   glRotatef((GLfloat)tengah2, 0.0, 1.0, 0.0);
   glTranslatef(0.15, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.3, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
       
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)tengah3, 0.0, 1.0, 0.0);
   glTranslatef(0.1, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.2, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	glPopMatrix();
	// telunjuk
	glPushMatrix();
   glTranslatef(0.5, 0.1, 0.0); 
   glRotatef((GLfloat)telunjuk1, 0.0, 1.0, 0.0);
   glTranslatef(0.2, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.4, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	
   glTranslatef(0.2, 0.0, 0.0);
   glRotatef((GLfloat)telunjuk2, 0.0, 1.0, 0.0);
   glTranslatef(0.15, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.25, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
       
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)telunjuk3, 0.0, 1.0, 0.0);
   glTranslatef(0.05, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.15, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	glPopMatrix();
	// jempol
	glPushMatrix();
   glTranslatef(0.5, 0.2, 0.0); 
   glRotatef((GLfloat)jempol1, 0.0, 1.0, 0.0);
   glTranslatef(0.05, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.1, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	
   glTranslatef(0.05, 0.0, 0.0);
   glRotatef((GLfloat)jempol2, 0.0, 1.0, 0.0);
   glTranslatef(0.05, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.1, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
       
   glTranslatef(0.1, 0.0, 0.0);
   glRotatef((GLfloat)jempol3, 0.0, 1.0, 0.0);
   glTranslatef(0.05, 0.0, 0.0);
   
   glPushMatrix(); 
	glScalef(0.1, 0.1, 0.1); 
	glutWireCube(1.0); 
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
	case 'f': shoulder = (shoulder + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'F': shoulder = (shoulder - 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'e': elbow = (elbow + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'E': elbow = (elbow - 5) % 360;                    
	glutPostRedisplay();                    
	break;               
	
	case 'l': telapak = (telapak + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'L': telapak = (telapak - 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'i': kelingking1 = (kelingking1 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'I': kelingking1 = (kelingking1 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 's': kelingking2 = (kelingking2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'S': kelingking2 = (kelingking2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'c': kelingking3 = (kelingking3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'C': kelingking3 = (kelingking3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'a': manis1 = (manis1 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'A': manis1 = (manis1 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'n': manis2 = (manis2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'N': manis2 = (manis2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 't': manis3 = (manis3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'T': manis3 = (manis3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'k': tengah1 = (tengah1 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'K': tengah1 = (tengah1 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'b': tengah2 = (tengah2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'B': tengah2 = (tengah2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'g': tengah3 = (tengah3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'G': tengah3 = (tengah3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'd': telunjuk1 = (telunjuk1 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'D': telunjuk1 = (telunjuk1 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'u': telunjuk2 = (telunjuk2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'U': telunjuk2 = (telunjuk2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'h': telunjuk3 = (telunjuk3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'H': telunjuk3 = (telunjuk3 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'j': jempol1 = (jempol1 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'J': jempol1 = (jempol1 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'o': jempol2 = (jempol2 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'O': jempol2 = (jempol2 - 5) % 90;                    
	glutPostRedisplay();                    
	break;
	
	case 'y': jempol3 = (jempol3 + 5) % 90;                    
	glutPostRedisplay();                    
	break;       
	
	case 'Y': jempol3 = (jempol3 - 5) % 90;                    
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
	glutInitWindowSize (1000, 600);        
	glutInitWindowPosition (100, 100);        
	glutCreateWindow (argv[0]);        
	init();   
	glutDisplayFunc(display);        
	glutReshapeFunc(reshape);        
	glutKeyboardFunc(keyboard);        
	glutMainLoop();        return 0;  
}
