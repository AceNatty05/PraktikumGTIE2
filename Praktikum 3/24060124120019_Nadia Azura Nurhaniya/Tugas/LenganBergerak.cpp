// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Menambahkan jari dan kontrol untuk menggerakkannya menggunakan keyboard

#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0;

static int thumb1 = 0, thumb2 = 0;
static int index1 = 0, index2 = 0, index3 = 0;
static int middle1 = 0, middle2 = 0, middle3 = 0;
static int ring1 = 0, ring2 = 0, ring3 = 0;
static int little1 = 0, little2 = 0, little3 = 0;

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // shoulder
    glTranslatef(-2.5,0.0,0.0);
    glRotatef((GLfloat)shoulder,0.0,0.0,1.0);

    // upper arm
    glPushMatrix();
        glTranslatef(1.0,0.0,0.0);
        glScalef(2.0,0.4,0.4);
        glutWireCube(1.0);
    glPopMatrix();

    // elbow
    glTranslatef(2.0,0.0,0.0);
    glRotatef((GLfloat)elbow,0.0,0.0,1.0);

    // forearm
    glPushMatrix();
        glTranslatef(1.0,0.0,0.0);
        glScalef(2.0,0.4,0.35);
        glutWireCube(1.0);
    glPopMatrix();

    // wrist
    glTranslatef(2.0,0.0,0.0);
    glRotatef((GLfloat)wrist,0.0,0.0,1.0);

    // palm
    glPushMatrix();
        glTranslatef(0.3,0.0,0.0);
        glScalef(0.6,0.8,0.3);
        glutWireCube(1.0);
    glPopMatrix();


    // Thumb Finger (Jari Jempol)
    glPushMatrix();
        glTranslatef(0.15,0.45,0.0);

        glRotatef((GLfloat)thumb1,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.15,0.0,0.0);
            glScalef(0.3,0.2,0.2);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.3,0.0,0.0);
        glRotatef((GLfloat)thumb2,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.15,0.0,0.0);
            glScalef(0.3,0.18,0.18);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();


    // Index Finger (Jari Telunjuk)
    glPushMatrix();
        glTranslatef(0.6,0.25,0.0);

        glRotatef((GLfloat)index1,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.2,0.0,0.0);
            glScalef(0.4,0.18,0.18);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.4,0.0,0.0);
        glRotatef((GLfloat)index2,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.18,0.0,0.0);
            glScalef(0.36,0.16,0.16);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.36,0.0,0.0);
        glRotatef((GLfloat)index3,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.15,0.0,0.0);
            glScalef(0.3,0.15,0.15);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();


    // Middle Finger (Jari tengah)
    glPushMatrix();
        glTranslatef(0.6,0.05,0.0);

        glRotatef((GLfloat)middle1,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.22,0.0,0.0);
            glScalef(0.45,0.18,0.18);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.45,0.0,0.0);
        glRotatef((GLfloat)middle2,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.18,0.0,0.0);
            glScalef(0.36,0.16,0.16);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.36,0.0,0.0);
        glRotatef((GLfloat)middle3,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.15,0.0,0.0);
            glScalef(0.3,0.15,0.15);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();


    // Ring Finger (Jari Manis)
    glPushMatrix();
        glTranslatef(0.6,-0.15,0.0);

        glRotatef((GLfloat)ring1,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.2,0.0,0.0);
            glScalef(0.4,0.18,0.18);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.4,0.0,0.0);
        glRotatef((GLfloat)ring2,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.18,0.0,0.0);
            glScalef(0.36,0.16,0.16);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.36,0.0,0.0);
        glRotatef((GLfloat)ring3,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.15,0.0,0.0);
            glScalef(0.3,0.15,0.15);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();


    // Little Finger (Jari Kelingking)
    glPushMatrix();
        glTranslatef(0.6,-0.35,0.0);

        glRotatef((GLfloat)little1,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.15,0.0,0.0);
            glScalef(0.3,0.18,0.18);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.3,0.0,0.0);
        glRotatef((GLfloat)little2,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.14,0.0,0.0);
            glScalef(0.28,0.16,0.16);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(0.28,0.0,0.0);
        glRotatef((GLfloat)little3,0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(0.12,0.0,0.0);
            glScalef(0.24,0.14,0.14);
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

	case 's': 
		shoulder = (shoulder + 5) % 360;                    
		glutPostRedisplay();                    
		break;   

	case 'S': 
		shoulder = (shoulder - 5) % 360;                    
		glutPostRedisplay();                    
		break;   

	case 'e': 
		elbow = (elbow + 5) % 360;                    
		glutPostRedisplay();                    
		break;   

	case 'E': 
		elbow = (elbow - 5) % 360;                    
		glutPostRedisplay();                    
		break;  

	case 'w': 
		wrist = (wrist + 5) % 15;                    
		glutPostRedisplay();                    
		break;   

	case 'W': 
		wrist = (wrist - 5) % 15;                    
		glutPostRedisplay();                    
		break; 

	// thumb (jari jempol) 
	// untuk ruas 1
	case 't':
		if(thumb1 < 90) thumb1 += 5;
		glutPostRedisplay();
		break;

	case 'T':
		if(thumb1 > 0) thumb1 -= 5;
		glutPostRedisplay();
		break;

	// untuk ruas 2
	case 'u':
		if(thumb2 < 90) thumb2 += 5;
		glutPostRedisplay();
		break;

	case 'U':
		if(thumb2 > 0) thumb2 -= 5;
		glutPostRedisplay();
		break;


	// index finger (jari telunjuk)
	// untuk ruas 1
	case 'i':
		if(index1 < 90) index1 += 5;
		glutPostRedisplay();
		break;

	case 'I':
		if(index1 > 0) index1 -= 5;
		glutPostRedisplay();
		break;

	// untuk ruas 2
	case 'o':
		if(index2 < 90) index2 += 5;
		glutPostRedisplay();
		break;

	case 'O':
		if(index2 > 0) index2 -= 5;
		glutPostRedisplay();
		break;

	// untuk ruas 3
	case 'p':
		if(index3 < 90) index3 += 5;
		glutPostRedisplay();
		break;

	case 'P':
		if(index3 > 0) index3 -= 5;
		glutPostRedisplay();
		break;


	// middle finger
	// untuk ruas 1
	case 'j':
		if(middle1 < 90) middle1 += 5;
		glutPostRedisplay();
		break;

	case 'J':
		if(middle1 > 0) middle1 -= 5;
		glutPostRedisplay();
		break;
		
	// untuk ruas 2
	case 'k':
		if(middle2 < 90) middle2 += 5;
		glutPostRedisplay();
		break;

	case 'K':
		if(middle2 > 0) middle2 -= 5;
		glutPostRedisplay();
		break;

	// untuk ruas 3
	case 'l':
		if(middle3 < 90) middle3 += 5;
		glutPostRedisplay();
		break;

	case 'L':
		if(middle3 > 0) middle3 -= 5;
		glutPostRedisplay();
		break;


	// ring finger (jari manis)
	// untuk ruas 1
	case 'b':
		if(ring1 < 90) ring1 += 5;
		glutPostRedisplay();
		break;

	case 'B':
		if(ring1 > 0) ring1 -= 5;
		glutPostRedisplay();
		break;

	// untuk ruas 2
	case 'n':
		if(ring2 < 90) ring2 += 5;
		glutPostRedisplay();
		break;

	case 'N':
		if(ring2 > 0) ring2 -= 5;
		glutPostRedisplay();
		break;

	// untuk ruas 3
	case 'm':
		if(ring3 < 90) ring3 += 5;
		glutPostRedisplay();
		break;

	case 'M':
		if(ring3 > 0) ring3 -= 5;
		glutPostRedisplay();
		break;


	// little finger (jari kelingking)
	// untuk ruas 1
	case 'z':
		if(little1 < 90) little1 += 5;
		glutPostRedisplay();
		break;

	case 'Z':
		if(little1 > 0) little1 -= 5;
		glutPostRedisplay();
		break;
	
	// untuk ruas 2
	case 'x':
		if(little2 < 90) little2 += 5;
		glutPostRedisplay();
		break;

	case 'X':
		if(little2 > 0) little2 -= 5;
		glutPostRedisplay();
		break;
		
	// untuk ruas 3
	case 'c':
		if(little3 < 90) little3 += 5;
		glutPostRedisplay();
		break;

	case 'C':
		if(little3 > 0) little3 -= 5;
		glutPostRedisplay();
		break;


	case 27:
		exit(0);
		break;

	default:
		break;
	}
}

int main(int argc, char** argv) {        
    glutInit(&argc, argv);   
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);        
    glutInitWindowSize (700, 600);        
    glutInitWindowPosition (100, 100);        
    glutCreateWindow ("Lengan Bergerak");        
    init();   
    glutDisplayFunc(display);        
    glutReshapeFunc(reshape);        
    glutKeyboardFunc(keyboard);        
    glutMainLoop();        
    return 0;  
}


