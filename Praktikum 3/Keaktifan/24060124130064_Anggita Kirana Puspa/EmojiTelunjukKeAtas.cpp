/* Nama: Anggita Kirana Puspa
   NIM: 24060124130064
   Lab: E2
   Keyboard:
   > shoulder : s, S
   > elbow : e, E
   > wrist : w, W
   > thumb : t, T, g, G, v, V
   > index : i, I, u, U, y, Y
   > middle : m, M, n, N, b, B
   > ring : r, R, d, D, x, X
   > little : l, L, k, K, h, H */
/* Bentuk jari menyesuaikan ukuran jari saya*/

#include <GL/glut.h>   
static int shoulder = 0, elbow1 = 90, elbow2 = 0, wrist = 0,
thumb1 = 270, thumb2 = 0, thumb3 = 0,
index1 = 0, index2 = 0, index3 = 0,
middle1 = 180, middle2 = 180, middle3 = 180,
ring1 = 180, ring2 = 180, ring3 = 180,
little1 = 180, little2 = 180, little3 = 180;   
   
 void init(void) {   
    glClearColor (0.0, 0.0, 0.0, 0.0);        
	glShadeModel (GL_FLAT);   
 }   

 void display(void) {   
    glClear (GL_COLOR_BUFFER_BIT);        
	glPushMatrix();   
	
	// Shoulder (Posisi pivot utk satu lengan)
    glTranslatef (-1.5, -0.6, 0.0);   
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);                 
	
	// Upper Arm 
	glPushMatrix();
	glTranslatef (1.0, 0.0, 0.0);           
	glScalef (2.0, 0.4, 0.45);                
	glutWireCube (1.0);            
	glPopMatrix();   
	
	// Elbow Joint (Ubah posisi pivot utk ForeArm)
	glTranslatef (2.0, 0.0, 0.0);
	glRotatef ((GLfloat) elbow1, 0.0, 0.0, 1.0);  
	                 
	// ForeArm
	glPushMatrix();
	glTranslatef (1.0, 0.0, 0.0);  
    glScalef (2.0, 0.4, 0.40);                
    glutWireCube (1.0);            
    glPopMatrix();   

	// Wrist Join (Ubah posisi pivot utk palm)  
	glTranslatef (2.0, 0.0, 0.0);
	glRotatef ((GLfloat) wrist, 0.0, 0.0, 1.0);            
	
	// Palm
	glPushMatrix();
	glTranslatef (0.3, 0.0, 0.0);
    glScalef (0.6, 0.8, 0.32);                
	glutWireCube (1.0);            
	glPopMatrix();
	
	// ============== THUMB =======================
	// Thumb segment1 join
	glPushMatrix();
	
	glTranslatef(0.17, 0.53, 0.0); //sesuaiin sama posisi palm
	glRotatef((GLfloat)thumb1, 0.0, 0.0, 1.0);
	
	// Thumb segment1
	glPushMatrix();
	glTranslatef(0.16, 0.0, 0.0); // cube pindah dri pusat ke pivot (tengah)
	glScalef(0.32, 0.25, 0.20);
	glutWireCube (1.0);
	glPopMatrix();
	
	// Thumb segment2 join
	glTranslatef(0.32, 0.0, 0.0); //sesuaiin sama posisi thumb segment1
	glRotatef((GLfloat)thumb2, 0.0, 0.0, 1.0);
	
	glRotatef((GLfloat)thumb3, 0.0, 0.0, 1.0);
	// Thumb segment2
	glPushMatrix();
	glTranslatef(0.15, 0.0, 0.0);
	glScalef(0.30, 0.25, 0.18);
	glutWireCube (1.0);
	glPopMatrix();
	
	glPopMatrix();
	
	// ============== INDEX =======================
	// Index segment1 join
	glPushMatrix();
	
	glTranslatef(0.6, 0.3, 0.0);
	glRotatef((GLfloat)index1, 0.0, 0.0, 1.0);
	
	// Index segment1
	glPushMatrix();
	glTranslatef(0.18, 0.0, 0.0);
	glScalef(0.36, 0.20, 0.18);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Index segment2 join
	glTranslatef(0.36, 0.0, 0.0); //sesuaiin x segment1
	glRotatef((GLfloat)index2, 0.0, 0.0, 1.0); 
	
	// Index segment2
	glPushMatrix();
	glTranslatef(0.14, 0.0, 0.0);
	glScalef(0.28, 0.20, 0.16);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Index segment3 join
	glTranslatef(0.28, 0.0, 0.0);
	glRotatef((GLfloat)index3, 0.0, 0.0, 1.0);
	
	// Index segment3
	glPushMatrix();
	glTranslatef(0.13, 0.0, 0.0);
	glScalef(0.26, 0.20, 0.14);
	glutWireCube(1.0);
	glPopMatrix();
	
	glPopMatrix();
	
	// ============== MIDDLE =======================
	// Middle segment1 join
	glPushMatrix();
	glTranslatef(0.6, 0.1, 0.0);
	glRotatef((GLfloat)middle1, 0.0, 0.0, 1.0);
	
	// Middle segment1
	glPushMatrix();
	glTranslatef(0.19, 0.0, 0.0);
	glScalef(0.38, 0.20, 0.18);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Middle segment2 join
	glTranslatef(0.40, 0.0, 0.0);
	glRotatef((GLfloat)middle2, 0.0, 0.0, 1.0);
	
	// Middle segment2
	glPushMatrix();
	glTranslatef(0.225, 0.0, 0.0);
	glScalef(0.45, 0.20, 0.16);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Middle segment3 join
	glTranslatef(0.45, 0.0, 0.0);
	glRotatef((GLfloat)middle3, 0.0, 0.0, 1.0);
	
	// Middle segment3
	glPushMatrix();
	glTranslatef(0.12, 0.0, 0.0);
	glScalef(0.24, 0.20, 0.14);
	glutWireCube(1.0);
	glPopMatrix();
	
	glPopMatrix();
	
	// ============== RING =======================
	// Ring segment1 join
	glPushMatrix();
	glTranslatef(0.63, -0.1, 0.0);
	glRotatef((GLfloat)ring1, 0.0, 0.0, 1.0);
	
	// Ring segment1
	glPushMatrix();
	glTranslatef(0.19, 0.0, 0.0);
	glScalef(0.38, 0.20, 0.17);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Ring segment2 join
	glTranslatef(0.38, 0.0, 0.0);
	glRotatef((GLfloat)ring2, 0.0, 0.0, 1.0);
	
	// Ring segment2
	glPushMatrix();
	glTranslatef(0.20, 0.0, 0.0);
	glScalef(0.40, 0.20, 0.15);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Ring segment3 join
	glTranslatef(0.40, 0.0, 0.0);
	glRotatef((GLfloat)ring3, 0.0, 0.0, 1.0);
	
	// Ring segment3
	glPushMatrix();
	glTranslatef(0.10, 0.0, 0.0);
	glScalef(0.20, 0.20, 0.15);
	glutWireCube(1.0);
	glPopMatrix();
	
	glPopMatrix();
	
	// ============== LITTLE =======================
	// little segment1 join
	glPushMatrix();
	glTranslatef(0.55, -0.30, 0.0);
	glRotatef((GLfloat)little1, 0.0, 0.0, 1.0);
	
	// Little segment1
	glPushMatrix();
	glTranslatef(0.10, 0.0, 0.0);
	glScalef(0.20, 0.20, 0.15);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Little segment2 join
	glTranslatef(0.20, 0.0, 0.0);
	glRotatef((GLfloat)little2, 0.0, 0.0, 1.0);
	
	// Little segment2
	glPushMatrix();
	glTranslatef(0.15, 0.0, 0.0);
	glScalef(0.30, 0.20, 0.15);
	glutWireCube(1.0);
	glPopMatrix();
	
	// Little segment2 join
	glTranslatef(0.30, 0.0, 0.0);
	glRotatef((GLfloat)little3, 0.0, 0.0, 1.0);
	
	// Little segment3
	glPushMatrix();
	glTranslatef(0.13, 0.0, 0.0);
	glScalef(0.26, 0.20, 0.15);
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
	// shoulder
	case 's': shoulder = (shoulder + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'S': shoulder = (shoulder - 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	// elbow
	case 'e': elbow1 = (elbow1 + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	
	case 'E': elbow1 = (elbow1 - 5) % 360;                    
	glutPostRedisplay();                    
	break;  
	
	// wrist
	case 'w': wrist = (wrist + 5) % 20;                    
	glutPostRedisplay();                    
	break;   
	
	case 'W': wrist = (wrist - 5) % 20;                    
	glutPostRedisplay();                    
	break; 
	
	// ============== THUMB =======================
	// thumb1 
	case 't': thumb1 = (thumb1 + 5) % 180;
	glutPostRedisplay();
	break;
	
	case 'T': thumb1 = (thumb1 - 5) % 180;
	glutPostRedisplay();
	break;
	
	// thumb2
	case 'g': thumb2 = (thumb2 + 5) % 100;
	glutPostRedisplay();
	break;
	
	case 'G': thumb2 = (thumb2 - 5) % 100;
	glutPostRedisplay();
	break;
	
	// thumb3
	case 'v': thumb3 = (thumb3 + 2) % 100;
	glutPostRedisplay();
	break;
	
	case 'V': thumb3 = (thumb3 - 2) % 100;
	glutPostRedisplay();
	break;
	
	// ============== INDEX =======================
	// index1
	case 'i': index1 = (index1 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'I': index1 = (index1 - 5) % 90;
	glutPostRedisplay();
	break;
	
	//index2
	case 'u': index2 = (index2 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'U': index2 = (index2 - 5) % 90;
	glutPostRedisplay();
	break;
	
	//index3
	case 'y': index3 = (index3 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'Y': index3 = (index3 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// ============== MIDDLE =======================
	// middle1
	case 'm': middle1 = (middle1 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'M': middle1 = (middle1 - 5) % 90; //90
	glutPostRedisplay();
	break;
	
	// middle2
	case 'n': middle2 = (middle2 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'N': middle2 = (middle2 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// middle3
	case 'b': middle3 = (middle3 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'B': middle3 = (middle3 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// ============== RING =======================
	// ring1
	case 'r': ring1 = (ring1 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'R': ring1 = (ring1 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// ring2
	case 'd': ring2 = (ring2 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'D': ring2 = (ring2 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// ring3
	case 'x': ring3 = (ring3 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'X': ring3 = (ring3 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// ============== LITTLE =======================
	// little1
	case 'l': little1 = (little1 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'L': little1 = (little1 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// little2
	case 'k': little2 = (little2 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'K': little2 = (little2 - 5) % 90;
	glutPostRedisplay();
	break;
	
	// little3
	case 'h': little3 = (little3 + 5) % 90;
	glutPostRedisplay();
	break;
	
	case 'H': little3 = (little3 - 5) % 90;
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
	glutCreateWindow ("Emoji Telunjuk Ke Atas");        
	init();   
	glutDisplayFunc(display);        
	glutReshapeFunc(reshape);        
	glutKeyboardFunc(keyboard);        
	glutMainLoop();        
	return 0;  
}
