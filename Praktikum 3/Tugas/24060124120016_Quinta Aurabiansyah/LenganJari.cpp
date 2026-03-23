// Nama: Quinta Aurabiansyah
// NIM : 24060124120016

#include <GL/glut.h>
#include <cstdlib>
#include <cstdio>

static int shoulder = 0, elbow = 0, wrist = 0;
static int fingerCurl[4] = {0, 0, 0, 0};
static int thumbCurl      = 0;

static const char* namaPose = "Manual";

struct Pose {
    const char* nama;
    int jari[4];  
    int ibu;
};

static const Pose daftarPose[] = {
    { "Open / Hi",   {  0,   0,   0,   0 },   0 }, 
    { "Peace / V",   {  0,   0,  85,  90 },   0 }, 
    { "Thumb Up",    { 90,  90,  90,  90 },   0 }, 
    { "Metal / Rock",{  0,  85,  85,   0 },   0 }, 
    { "Pointing",    {  0,  85,  85,  85 },   0 }, 
    { "Pinky Up",    { 85,  85,  85,   0 },  0 }, 
    { "Gun",         {  0,  85,  85,  85 },   0 }, 
};

static const int kJumlahPose = sizeof(daftarPose) / sizeof(daftarPose[0]);
void terapkanPose(int idx) {
    if (idx < 0 || idx >= kJumlahPose) return;
    for (int i = 0; i < 4; i++)
        fingerCurl[i] = daftarPose[idx].jari[i];
    thumbCurl = daftarPose[idx].ibu;
    namaPose  = daftarPose[idx].nama;
    char judul[64];
    sprintf(judul, "Hand Sign: %s", namaPose);
    glutSetWindowTitle(judul);
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}


void drawFinger(float length1, float length2, float width,
                int curl, float rotasiAwal) {
    glPushMatrix();
    glRotatef(rotasiAwal, 0.0f, 0.0f, 1.0f);

    // Ruas pertama
    glRotatef((GLfloat)curl, 0.0f, 0.0f, 1.0f);
    glTranslatef(length1 / 2.0f, 0.0f, 0.0f);
    glPushMatrix();
        glScalef(length1, width, width);
        glutWireCube(1.0);
    glPopMatrix();

    // Ruas kedua 
    glTranslatef(length1 / 2.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)(curl * 0.8f), 0.0f, 0.0f, 1.0f);
    glTranslatef(length2 / 2.0f, 0.0f, 0.0f);
    glPushMatrix();
        glScalef(length2, width * 0.85f, width * 0.85f);
        glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    // Bahu
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)shoulder, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);
    glPushMatrix();
        glScalef(2.0f, 0.4f, 0.4f);
        glutWireCube(1.0);
    glPopMatrix();

    //Siku
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)elbow, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);
    glPushMatrix();
        glScalef(2.0f, 0.4f, 0.35f);
        glutWireCube(1.0);
    glPopMatrix();

    //Pergelangan
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)wrist, 0.0f, 0.0f, 1.0f);

    // Telapak 
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.0f);
        glScalef(0.6f, 0.8f, 0.3f);
        glutWireCube(1.0);
    glPopMatrix();

    // Pangkal jari 
    glTranslatef(0.6f, 0.0f, 0.0f);

    //4 Jari 
    float fingerOffsets[4]  = {  0.25f,  0.05f, -0.15f, -0.35f };
    float fingerLengths[4]  = {  0.40f,  0.45f,  0.40f,  0.30f };
    float rotasiAwal[4]     = { 10.0f,   0.0f,   0.0f,   0.0f  };

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
            glTranslatef(0.0f, fingerOffsets[i], 0.0f);
            drawFinger(fingerLengths[i],
                       fingerLengths[i] * 0.75f,
                       0.18f,           
                       fingerCurl[i],
                       rotasiAwal[i]);
        glPopMatrix();
    }

    //ibu Jari 
    glPushMatrix();
        glTranslatef(-0.45f, 0.45f, 0.0f); 
        glRotatef(60.0f,  0.0f, 0.0f, 1.0f);
        glRotatef((GLfloat)thumbCurl, 0.0f, 0.0f, 1.0f);

        //Ruas 1 ibu jari
        glTranslatef(0.15f, 0.0f, 0.0f);
        glPushMatrix();
            glScalef(0.30f, 0.20f, 0.20f);
            glutWireCube(1.0);
        glPopMatrix();

        // Ruas 2 ibu jari
        glTranslatef(0.30f, 0.0f, 0.0f);
        glRotatef((GLfloat)(thumbCurl * 0.5f), 0.0f, 0.0f, 1.0f);
        glTranslatef(0.15f, 0.0f, 0.0f);
        glPushMatrix();
            glScalef(0.30f, 0.18f, 0.18f);
            glutWireCube(1.0);
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
    glTranslatef(0.0f, 0.0f, -5.0f);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5 + 360) % 360; break;
        case 'e': elbow    = (elbow    + 5) % 360; break;
        case 'E': elbow    = (elbow    - 5 + 360) % 360; break;
        case 'w': wrist    = (wrist    + 5) % 360; break;
        case 'W': wrist    = (wrist    - 5 + 360) % 360; break;
        case 'f':
            for (int i = 0; i < 4; i++)
                fingerCurl[i] = (fingerCurl[i] + 5 > 120) ? 120 : fingerCurl[i] + 5;
            namaPose = "Manual";
            break;
        case 'F':
            for (int i = 0; i < 4; i++)
                fingerCurl[i] = (fingerCurl[i] - 5 < 0) ? 0 : fingerCurl[i] - 5;
            namaPose = "Manual";
            break;

        case 't': thumbCurl = (thumbCurl + 5 > 90) ? 90 : thumbCurl + 5; namaPose = "Manual"; break;
        case 'T': thumbCurl = (thumbCurl - 5 < 0)  ?  0 : thumbCurl - 5; namaPose = "Manual"; break;

        case '1': terapkanPose(0); break;
        case '2': terapkanPose(1); break;
        case '3': terapkanPose(2); break;
        case '4': terapkanPose(3); break;
        case '5': terapkanPose(4); break;
        case '6': terapkanPose(5); break;
        case '7': terapkanPose(6); break;
        case '8': terapkanPose(7); break;
        case '9': terapkanPose(8); break;
        case '0': terapkanPose(9); break;

        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hand Sign: Manual");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
