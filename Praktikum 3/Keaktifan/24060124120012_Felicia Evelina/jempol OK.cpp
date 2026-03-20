#include <GL/glut.h>   

// jempol = O
// balik ke awal = K
static int shoulder = 0, elbow = 0, telapak = 0;
static int jempol1 = 0, jempol2 = 0, jempol3 = 0; 
static int telunjuk1 = 0, telunjuk2 = 0, telunjuk3 = 0;
static int tengah1 = 0, tengah2 = 0, tengah3 = 0;
static int manis1 = 0, manis2 = 0, manis3 = 0;   
static int kelingking1 = 0, kelingking2 = 0, kelingking3 = 0;  
float geserjempol = 0.5; 
float kecilintlapak = 0.6;

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
	glRotatef ((GLfloat) telapak, 0.0, 0.0, 1.0);            
	glTranslatef (0.5, 0.0, 0.0);       
	     
	glPushMatrix();   
    glScalef (0.8, kecilintlapak, 0.2);                
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
    glTranslatef(geserjempol, 0.2, 0.0); 
    glRotatef((GLfloat)jempol1, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    
    glPushMatrix(); 
	glScalef(0.1, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
	
    glTranslatef(0.05, 0.0, 0.0);
    glRotatef((GLfloat)jempol2, 0.0, 0.0, 1.0);
    glTranslatef(0.05, 0.0, 0.0);
    
    glPushMatrix(); 
	glScalef(0.1, 0.1, 0.1); 
	glutWireCube(1.0); 
	glPopMatrix();
        
    glTranslatef(0.1, 0.0, 0.0);
    glRotatef((GLfloat)jempol3, 0.0, 0.0, 1.0);
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
// hehe ini jempol..maksudnya..
void keyboard(unsigned char key, int x, int y) {        
	switch (key) {   
	case 'O': jempol1= 90; 
	geserjempol = -0.3;
	kecilintlapak = 0.4;
	elbow = 45;
	telapak = -40;	
	telunjuk1 = 90; telunjuk2 = 90; telunjuk3 = 90;    
	tengah1 = 90; tengah2 = 90; tengah3 = 90; 
	manis1 = 90; manis2 = 90; manis3 = 90;
    kelingking1 = 90; kelingking2 = 90; kelingking3 = 90;               
	glutPostRedisplay();                    
	break;   
	
	case 'K': jempol1= 0; 
	geserjempol = 0.5;
	kecilintlapak = 0.6;
	elbow = 0;
	telapak = 0;	
	telunjuk1 = 0; telunjuk2 = 0; telunjuk3 = 0;    
	tengah1 = 0; tengah2 = 0; tengah3 = 0; 
	manis1 = 0; manis2 = 0; manis3 = 0;
    kelingking1 = 0; kelingking2 = 0; kelingking3 = 0;                 
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
