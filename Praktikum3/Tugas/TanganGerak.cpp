#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0;

// Setiap jari punya 2 sendi: knuckle (MCP) dan middle (PIP)
static int finger[4][2] = {
    {0, 0},  // telunjuk
    {0, 0},  // tengah
    {0, 0},  // manis
    {0, 0}   // kelingking
};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

/* Menggambar satu ruas jari:*/
void drawFinger(float length, float width) {
    glPushMatrix();
    glScalef(length, width, 0.3f);
    glutWireCube(1.0);
    glPopMatrix();
}

/* Menggambar satu jari lengkap */
void drawOneFinger(float offsetY, int knuckle, int pip) {
    glPushMatrix();
    // Posisikan jari 
    glTranslatef(0.0f, offsetY, 0.0f);

    glRotatef((GLfloat)knuckle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.35f, 0.0f, 0.0f);  
    drawFinger(0.7f, 0.15f);

    glTranslatef(0.35f, 0.0f, 0.0f);  
    glRotatef((GLfloat)pip, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.25f, 0.0f, 0.0f);
    drawFinger(0.5f, 0.12f);

    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)shoulder, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glScalef(2.0f, 0.4f, 1.0f);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)elbow, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glScalef(2.0f, 0.4f, 1.0f);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)wrist, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.5f, 0.0f, 0.0f);

    glPushMatrix();
    glScalef(1.0f, 0.8f, 0.4f);
    glutWireCube(1.0);
    glPopMatrix();


    glTranslatef(0.5f, 0.0f, 0.0f);

    drawOneFinger( 0.30f, finger[0][0], finger[0][1]); // telunjuk
    drawOneFinger( 0.10f, finger[1][0], finger[1][1]); // tengah
    drawOneFinger(-0.10f, finger[2][0], finger[2][1]); // manis
    drawOneFinger(-0.30f, finger[3][0], finger[3][1]); // kelingking

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
    glTranslatef(0.0f, 0.0f, -5.0f);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // --- Shoulder ---
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5 + 360) % 360; break;

        // --- Elbow ---
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5 + 360) % 360; break;

        // --- Wrist ---
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5 + 360) % 360; break;

        // --- Jari Telunjuk ---
        case '1': finger[0][0] = (finger[0][0] + 10) % 90;
                  finger[0][1] = (finger[0][1] + 10) % 90; break;
        case '!': finger[0][0] = (finger[0][0] - 10 + 90) % 90;
                  finger[0][1] = (finger[0][1] - 10 + 90) % 90; break;

        // --- Jari Tengah ---
        case '2': finger[1][0] = (finger[1][0] + 10) % 90;
                  finger[1][1] = (finger[1][1] + 10) % 90; break;
        case '@': finger[1][0] = (finger[1][0] - 10 + 90) % 90;
                  finger[1][1] = (finger[1][1] - 10 + 90) % 90; break;

        // --- Jari Manis ---
        case '3': finger[2][0] = (finger[2][0] + 10) % 90;
                  finger[2][1] = (finger[2][1] + 10) % 90; break;
        case '#': finger[2][0] = (finger[2][0] - 10 + 90) % 90;
                  finger[2][1] = (finger[2][1] - 10 + 90) % 90; break;

        // --- Jari Kelingking  ---
        case '4': finger[3][0] = (finger[3][0] + 10) % 90;
                  finger[3][1] = (finger[3][1] + 10) % 90; break;
        case '$': finger[3][0] = (finger[3][0] - 10 + 90) % 90;
                  finger[3][1] = (finger[3][1] - 10 + 90) % 90; break;

        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
