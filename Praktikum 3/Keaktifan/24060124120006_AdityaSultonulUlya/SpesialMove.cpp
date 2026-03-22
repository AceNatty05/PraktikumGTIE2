// Nama	: Aditya Sultonul Ulya
// NIM	: 24060124120006
/* Perintah Gerak :
	1. Shoulder	: b, B
	2. Elbow	: e, E
	3. Wrist	: w, W
	4. Jempol	: j, J, o, O
	5. Telunjuk	: t, T, d, D, k, K
	6. Tengah	: a, A, h, H, g, G
	7. Manis	: n, N, m, M, c, C
	8. Kelingking : i, I, p, P, q, Q
	
	Special Move :
	1. Gaya Spiderman	: 1
	2. Gaya Jempol		: 2
	3. Reset gerakan	: 0
*/

#include <GL/glut.h>   
#include <math.h>

// sendi-sendi
static int shoulder = 0, elbow = 0, wrist = 0;
// Jempol (2 ruas)
static int thumb1 = 0, thumb2 = 0;
// Telunjuk (3 ruas)
static int index1 = 0, index2 = 0, index3 = 0;
// Tengah (3 ruas)
static int middle1 = 0, middle2 = 0, middle3 = 0;
// Manis (3 ruas)
static int ring1 = 0, ring2 = 0, ring3 = 0;
// Kelingking (3 ruas)
static int pinky1 = 0, pinky2 = 0, pinky3 = 0;

void init(void) {   
    glClearColor (0.0, 0.0, 0.0, 0.0);        
    glShadeModel (GL_FLAT);   
}   

void drawFinger(float length, float width, int segments, int angles[]) {
    for(int i = 0; i < segments; i++) {
        glRotatef((GLfloat)angles[i], 0.0, 0.0, 1.0);

        glPushMatrix();
            glScalef(length, width, width);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(length, 0.0, 0.0);
    }
}

void drawHand() {
    // TELAPAK TANGAN
    glPushMatrix();
        glScalef(1.8, 1.5, 0.4);
        glutWireCube(1.0);
    glPopMatrix();
    
    float palmEnd = 0.9; 
    
    // JEMPOL (2 ruas)
    glPushMatrix();
        glTranslatef(palmEnd -1.5, 1.0, 0.2);
        glRotatef(0.0, 0.0, 0.0, 1.0);
        int thumbAngles[] = {thumb1, thumb2};
        drawFinger(0.6, 0.3, 2, thumbAngles);
    glPopMatrix();
    
    // TELUNJUK (3 ruas)
    glPushMatrix();
        glTranslatef(palmEnd, 0.5, 0.0);
        int indexAngles[] = {index1, index2, index3};
        drawFinger(0.7, 0.25, 3, indexAngles);
    glPopMatrix();
    
    // TENGAH (3 ruas)
    glPushMatrix();
        glTranslatef(palmEnd, 0.15, 0.0);
        int middleAngles[] = {middle1, middle2, middle3};
        drawFinger(0.8, 0.25, 3, middleAngles);
    glPopMatrix();
    
    // MANIS (3 ruas)
    glPushMatrix();
        glTranslatef(palmEnd, -0.2, 0.0);
        int ringAngles[] = {ring1, ring2, ring3};
        drawFinger(0.7, 0.25, 3, ringAngles);
    glPopMatrix();
    
    // KELINGKING (3 ruas)
    glPushMatrix();
        glTranslatef(palmEnd, -0.55, 0.0);
        int pinkyAngles[] = {pinky1, pinky2, pinky3};
        drawFinger(0.6, 0.2, 3, pinkyAngles);
    glPopMatrix();
}

void display(void) {   
    glClear (GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    
    // letak semua objek
    glTranslatef(-2.5, -3.0, 0.0);
    
    // LENGAN ATAS
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef (2.0, 0.5, 0.5);
        glutWireCube (1.0);
    glPopMatrix();
    
    // LENGAN BAWAH
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef (2.0, 0.5, 0.5);
        glutWireCube (1.0);
    glPopMatrix();
    
    // PERGELANGAN
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) wrist, 0.0, 0.0, 1.0);
    
    // TANGAN
    glTranslatef(0.9, 0.0, 0.0);
    drawHand();
    
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
    glTranslatef (0.0, 0.0, -8.0);
}

void setSpiderManPose() {
    // Mengatur posisi lengan dan tangan menghadap ke atas
    shoulder = 90;    
    elbow = 0;    
    wrist = 0;  
    
    // POSE JARI SPIDER-MAN
	// telunjuk   
    index1 = 10;   index2 = 0;   index3 = 0; 
	// tengah   
    middle1 = 180;  middle2 = 180;  middle3 = 0;
    // Jari manis
    ring1 = 180;    ring2 = 180;    ring3 = 0;
	// kelingking
    pinky1 = 350;   pinky2 = 0;   pinky3 = 0; 
    // Jempol
    thumb1 = 45;   thumb2 = 0;
}  

void setJempolPose() {
    // Mengatur posisi lengan dan tangan menghadap ke atas
    shoulder = 0;    
    elbow = 0;    
    wrist = 0;  
    
    // POSE JARI SPIDER-MAN
	// telunjuk   
    index1 = 180;   index2 = 180;   index3 = 0; 
	// tengah   
    middle1 = 180;  middle2 = 180;  middle3 = 0;
    // Jari manis
    ring1 = 180;    ring2 = 180;    ring3 = 0;
	// kelingking
    pinky1 = 180;   pinky2 = 180;   pinky3 = 0; 
    // Jempol
    thumb1 = 70;   thumb2 = 0;
}  

void resetPose() {
    // Reset semua sudut ke 0
    shoulder = 0; elbow = 0; wrist = 0;
    thumb1 = 0; thumb2 = 0;
    index1 = 0; index2 = 0; index3 = 0;
    middle1 = 0; middle2 = 0; middle3 = 0;
    ring1 = 0; ring2 = 0; ring3 = 0;
    pinky1 = 0; pinky2 = 0; pinky3 = 0;
}

void keyboard(unsigned char key, int x, int y) {        
    switch (key) {   
        // SHOULDER
        case 'b': shoulder = (shoulder + 5) % 360; break;   
        case 'B': shoulder = (shoulder - 5) % 360; break;   
        
        // ELBOW
        case 'e': elbow = (elbow + 5) % 360; break;   
        case 'E': elbow = (elbow - 5) % 360; break;
        
        // WRIST
        case 'w': wrist = (wrist + 5) % 360; break;   
        case 'W': wrist = (wrist - 5) % 360; break;   
        
        // JEMPOL
        case 'j': thumb1 = (thumb1 + 5) % 360; break;
        case 'J': thumb1 = (thumb1 - 5) % 360; break;
        case 'o': thumb2 = (thumb2 + 5) % 360; break;
        case 'O': thumb2 = (thumb2 - 5) % 360; break;
        
        // TELUNJUK
        case 't': index1 = (index1 + 5) % 360; break;
        case 'T': index1 = (index1 - 5) % 360; break;
        case 'd': index2 = (index2 + 5) % 360; break;
        case 'D': index2 = (index2 - 5) % 360; break;
        case 'k': index3 = (index3 + 5) % 360; break;
        case 'K': index3 = (index3 - 5) % 360; break;
        
        // TENGAH
        case 'a': middle1 = (middle1 + 5) % 360; break;
        case 'A': middle1 = (middle1 - 5) % 360; break;
        case 'h': middle2 = (middle2 + 5) % 360; break;
        case 'H': middle2 = (middle2 - 5) % 360; break;
        case 'g': middle3 = (middle3 + 5) % 360; break;
        case 'G': middle3 = (middle3 - 5) % 360; break;
        
        // MANIS
        case 'n': ring1 = (ring1 + 5) % 360; break;
        case 'N': ring1 = (ring1 - 5) % 360; break;
        case 'm': ring2 = (ring2 + 5) % 360; break;
        case 'M': ring2 = (ring2 - 5) % 360; break;
        case 'c': ring3 = (ring3 + 5) % 360; break;
        case 'C': ring3 = (ring3 - 5) % 360; break;
        
        // KELINGKING
        case 'i': pinky1 = (pinky1 + 5) % 360; break;
        case 'I': pinky1 = (pinky1 - 5) % 360; break;
        case 'p': pinky2 = (pinky2 + 5) % 360; break;
        case 'P': pinky2 = (pinky2 - 5) % 360; break;
        case 'q': pinky3 = (pinky3 + 5) % 360; break;
        case 'Q': pinky3 = (pinky3 - 5) % 360; break;
        
        // Pose Spider-Man
        case '1': setSpiderManPose(); break;
 
        // Pose Jempol
        case '2': setJempolPose(); break; 
        
        // Reset ke posisi normal
        case '0': resetPose(); break;
        
        case 27: exit(0); break;
        default: break;   
    }   
    glutPostRedisplay();
}   

int main(int argc, char** argv) {        
    glutInit(&argc, argv);   
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);        
    glutInitWindowSize (700, 600);        
    glutInitWindowPosition (100, 100);        
    glutCreateWindow("Robot Arm with Hand and Fingers");        
    init();   
    glutDisplayFunc(display);        
    glutReshapeFunc(reshape);        
    glutKeyboardFunc(keyboard);        
    glutMainLoop();        
    return 0;  
}
