/*Nama	: Aqiatillah Rezi Zhafran
 NIM	: 24060124140124
 LAB	: E2*/
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, wirst = 0;
static int j1 = 0, j2 = 0;             
static int t1 = 0, t2 = 0, t3 = 0;     
static int h1 = 0, h2 = 0, h3 = 0;     
static int m1 = 0, m2 = 0, m3 = 0;     
static int k1 = 0, k2 = 0, k3 = 0;
/* shoulder = s,S
	elbow = e,E,w,W
	jempol = j,J,k,K
	telunjuk = t,T,y,Y,u,U
	tengah = h,H,n,N,m,M
	manis = a,A,z,Z,x,X
	kelingking= l,L,o,O,p,P
*/
     
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    // Shoulder
    glTranslatef(-3.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    // elbow
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    // wirst
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wirst, 0.0, 0.0, 1.0);
    glTranslatef(0.4, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.8, 0.9, 0.3);
        glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix(); 

        // Jempol
        glPushMatrix();
            glTranslatef(-0.1, 0.55, 0.0); 
            glRotatef((GLfloat)j1, 0.0, 1.0, 0.0);
            glTranslatef(0.125, 0.0, 0.0);
            glPushMatrix(); glScalef(0.25, 0.2, 0.2); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.125, 0.0, 0.0);
            glRotatef((GLfloat)j2, 0.0, 1.0, 0.0);
            glTranslatef(0.125, 0.0, 0.0);
            glPushMatrix(); glScalef(0.25, 0.2, 0.2); glutWireCube(1.0); glPopMatrix();
        glPopMatrix();

        // Telunjuk
        glPushMatrix();
            glTranslatef(0.4, 0.3, 0.0); 
            glRotatef((GLfloat)t1, 0.0, 1.0, 0.0);
            glTranslatef(0.175, 0.0, 0.0);
            glPushMatrix(); glScalef(0.35, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.175, 0.0, 0.0);
            glRotatef((GLfloat)t2, 0.0, 1.0, 0.0);
            glTranslatef(0.175, 0.0, 0.0);
            glPushMatrix(); glScalef(0.35, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.175, 0.0, 0.0);
            glRotatef((GLfloat)t3, 0.0, 1.0, 0.0);
            glTranslatef(0.175, 0.0, 0.0);
            glPushMatrix(); glScalef(0.35, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
        glPopMatrix();

        // Tengah
        glPushMatrix();
            glTranslatef(0.4, 0.1, 0.0); 
            glRotatef((GLfloat)h1, 0.0, 1.0, 0.0);
            glTranslatef(0.2, 0.0, 0.0);
            glPushMatrix(); glScalef(0.4, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.2, 0.0, 0.0);
            glRotatef((GLfloat)h2, 0.0, 1.0, 0.0);
            glTranslatef(0.2, 0.0, 0.0);
            glPushMatrix(); glScalef(0.4, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.2, 0.0, 0.0);
            glRotatef((GLfloat)h3, 0.0, 1.0, 0.0);
            glTranslatef(0.2, 0.0, 0.0);
            glPushMatrix(); glScalef(0.4, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
        glPopMatrix();

        // Manis
        glPushMatrix();
            glTranslatef(0.4, -0.1, 0.0); 
            glRotatef((GLfloat)m1, 0.0, 1.0, 0.0);
            glTranslatef(0.175, 0.0, 0.0);
            glPushMatrix(); glScalef(0.35, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.175, 0.0, 0.0);
            glRotatef((GLfloat)m2, 0.0, 1.0, 0.0);
            glTranslatef(0.175, 0.0, 0.0);
            glPushMatrix(); glScalef(0.35, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.175, 0.0, 0.0);
            glRotatef((GLfloat)m3, 0.0, 1.0, 0.0);
            glTranslatef(0.175, 0.0, 0.0);
            glPushMatrix(); glScalef(0.35, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
        glPopMatrix();

        // Kelingking
        glPushMatrix();
            glTranslatef(0.4, -0.3, 0.0); 
            glRotatef((GLfloat)k1, 0.0, 1.0, 0.0);
            glTranslatef(0.125, 0.0, 0.0);
            glPushMatrix(); glScalef(0.25, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.125, 0.0, 0.0);
            glRotatef((GLfloat)k2, 0.0, 1.0, 0.0);
            glTranslatef(0.125, 0.0, 0.0);
            glPushMatrix(); glScalef(0.25, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
            
            glTranslatef(0.125, 0.0, 0.0);
            glRotatef((GLfloat)k3, 0.0, 1.0, 0.0);
            glTranslatef(0.125, 0.0, 0.0);
            glPushMatrix(); glScalef(0.25, 0.15, 0.15); glutWireCube(1.0); glPopMatrix();
        glPopMatrix();

    glPopMatrix(); 
    glPopMatrix(); 
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's': shoulder = (shoulder + 5) % 360;
        glutPostRedisplay(); 
    break;
    case 'S': shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();  
    break;
    case 'e': elbow = (elbow + 5) % 160;
        glutPostRedisplay(); 
    break;
    case 'E': elbow = (elbow - 5) % 160;
        glutPostRedisplay(); 
    break;
    case 'w': wirst = (wirst + 5) % 45;
        glutPostRedisplay(); 
    break;
    case 'W': wirst = (wirst - 5) % 45; 
        glutPostRedisplay(); 
    break;

    // Jempol
    case 'j': j1 = (j1 + 5) % 90;
        glutPostRedisplay(); 
    break;
    case 'J': j1 = (j1 - 5) % 90;
        glutPostRedisplay();  
    break;
    case 'k': j2 = (j2 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'K': j2 = (j2 - 5) % 90;
        glutPostRedisplay();  
    break;

    // Telunjuk
    case 't': t1 = (t1 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'T': t1 = (t1 - 5) % 90;
        glutPostRedisplay();  
    break;
    case 'y': t2 = (t2 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'Y': t2 = (t2 - 5) % 90;
        glutPostRedisplay();  
    break;
    case 'u': t3 = (t3 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'U': t3 = (t3 - 5) % 90;
        glutPostRedisplay();  
    break;

    // Tengah
    case 'h': h1 = (h1 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'H': h1 = (h1 - 5) % 90;
        glutPostRedisplay(); 
    break;
    case 'n': h2 = (h2 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'N': h2 = (h2 - 5) % 90;
        glutPostRedisplay();  
    break;
    case 'm': h3 = (h3 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'M': h3 = (h3 - 5) % 90;
        glutPostRedisplay();  
    break;

    // Manis
    case 'a': m1 = (m1 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'A': m1 = (m1 - 5) % 90;
        glutPostRedisplay();  
    break;
    case 'z': m2 = (m2 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'Z': m2 = (m2 - 5) % 90; 
        glutPostRedisplay(); 
    break;
    case 'x': m3 = (m3 + 5) % 90; 
        glutPostRedisplay(); 
    break;
    case 'X': m3 = (m3 - 5) % 90;
        glutPostRedisplay();  
    break;

    // Kelingking
    case 'l': k1 = (k1 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'L': k1 = (k1 - 5) % 90; 
        glutPostRedisplay(); 
    break;
    case 'o': k2 = (k2 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'O': k2 = (k2 - 5) % 90; 
        glutPostRedisplay(); 
    break;
    case 'p': k3 = (k3 + 5) % 90;
        glutPostRedisplay();  
    break;
    case 'P': k3 = (k3 - 5) % 90;
        glutPostRedisplay();  
    break;

    case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan lengkap");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
