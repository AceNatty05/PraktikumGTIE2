#include <GL/glut.h>   
static int shoulder = 0, elbow = 0, wrist = 0;
static int f1=0;
   
 void init(void) {   
    glClearColor (0.0, 0.0, 0.0, 0.0);        
	glShadeModel (GL_FLAT);   
 }   
   
 void display(void) {   
    glClear (GL_COLOR_BUFFER_BIT);        
	glPushMatrix();   
    glTranslatef (-1.0, 0.0, 0.0);   
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);            
	glTranslatef (1.0, 0.0, 0.0);      
	      
	/* -- UPPER ARM -- */
	glPushMatrix();             
	glScalef (2.0, 0.4, 0.4);                
	glutWireCube (1.0);            
	glPopMatrix();   
	
    glTranslatef (1.0, 0.0, 0.0);   
	glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);            
	glTranslatef (1.0, 0.0, 0.0);       
	     
	/* -- LOWER ARM -- */
	glPushMatrix();   
    glScalef (2.0, 0.4, 0.4);                
	glutWireCube (1.0);            
	glPopMatrix();
 
 	glTranslatef (1.0, 0.0, 0.0);
	glRotatef ((GLfloat) wrist, 0.0, 0.0, 1.0);
	
	/* -- HAND (telapak) -- */
	glTranslatef (0.4, 0.0, 0.0);
	
	glPushMatrix();
	glScalef (0.7, 0.6, 0.4);
	glutWireCube (1.0);
	glPopMatrix();
	
	glTranslatef (-0.05,0.0,0.0);
	
	
	/* -- JARI 1 (atas) -- */
	glPushMatrix();
	glTranslatef (0.4,  0.25, 0.0);
//	glRotatef (-(GLfloat) f1, 0.0, 0.0, 1.0);
	glTranslatef (0.1, 0.0, 0.0);
	glPushMatrix(); glScalef (0.2, 0.1, 0.1); glutWireCube (1.0); glPopMatrix();
	glRotatef (-(GLfloat) f1, 0.0, 0.0, 1.0);
	glTranslatef (0.2, 0.0, 0.0);
	glPushMatrix(); glScalef (0.18, 0.09, 0.09); glutWireCube (1.0); glPopMatrix();
	glPopMatrix();
 
	/* -- JARI 2 -- */
	glPushMatrix();
	glTranslatef (0.4,  0.09	, 0.0);
	glTranslatef (0.1, 0.0, 0.0);
	glPushMatrix(); glScalef (0.2, 0.1, 0.1); glutWireCube (1.0); glPopMatrix();
	glRotatef (-(GLfloat) f1, 0.0, 0.0, 1.0);
	glTranslatef (0.2, 0.0, 0.0);
	glPushMatrix(); glScalef (0.18, 0.09, 0.09); glutWireCube (1.0); glPopMatrix();
	glPopMatrix();
 
	/* -- JARI 3 -- */
	glPushMatrix();
	glTranslatef (0.4, -0.09, 0.0);
	glTranslatef (0.1, 0.0, 0.0);
	glPushMatrix(); glScalef (0.2, 0.1, 0.1); glutWireCube (1.0); glPopMatrix();
	glRotatef (-(GLfloat) f1, 0.0, 0.0, 1.0);
	glTranslatef (0.2, 0.0, 0.0);
	glPushMatrix(); glScalef (0.18, 0.09, 0.09); glutWireCube (1.0); glPopMatrix();
	glPopMatrix();
 
	/* -- JARI 4 (bawah) -- */
	glPushMatrix();
	glTranslatef (0.4, -0.25, 0.0);
	glTranslatef (0.1, 0.0, 0.0);
	glPushMatrix(); glScalef (0.2, 0.1, 0.1); glutWireCube (1.0); glPopMatrix();
	glRotatef (-(GLfloat) f1, 0.0, 0.0, 1.0);
	glTranslatef (0.2, 0.0, 0.0);
	glPushMatrix(); glScalef (0.18, 0.09, 0.09); glutWireCube (1.0); glPopMatrix();
	glPopMatrix();
 
	/* -- IBU JARI (thumb) -- */
	glPushMatrix();
	glTranslatef (0.0, -0.35, 0.0);
	glRotatef (-50.0, 0.0, 0.0, 1.0);
	glTranslatef (0.1, 0.0, 0.0);
	glPushMatrix(); glScalef (0.2, 0.12, 0.12); glutWireCube (1.0); glPopMatrix();
	glRotatef (-(GLfloat) f1, 0.0, 0.0, 1.0);
	glTranslatef (0.2, 0.0, 0.0);
	glPushMatrix(); glScalef (0.16, 0.11, 0.11); glutWireCube (1.0); glPopMatrix();
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
	case 's': shoulder = (shoulder + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'S': shoulder = (shoulder - 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'e': elbow = (elbow + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'E': elbow = (elbow - 5) % 360;                    
	glutPostRedisplay();                    
	break;               
	
	case 'w': wrist = (wrist + 5) % 360;
	glutPostRedisplay();                    
	break;      
	
	case 'W': wrist = (wrist - 5) % 360;
	glutPostRedisplay();                    
	break;
	
	case '1': if(f1==0){
		f1=180;
	}
	else{
		f1=0;
	}
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
