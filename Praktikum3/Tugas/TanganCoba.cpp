/*
 * ============================================================
 *  TELAPAK TANGAN 3D - OpenGL/GLUT
 *  Kontrol:
 *    Drag mouse    -> Rotasi kamera
 *    Scroll        -> Zoom in/out
 *    W/A/S/D       -> Geser tangan
 *    1/2/3/4/5     -> Toggle tekuk jari
 *    R             -> Reset
 *    ESC           -> Keluar
 * ============================================================
 */

#include <GL/glut.h>
#include <cmath>

float camYaw   =  20.0f;
float camPitch = -25.0f;
float camDist  =   5.5f;
int   lastMouseX, lastMouseY;
bool  mouseDown = false;

float handX = 0.0f, handY = 0.0f;
float bend[5] = {0, 0, 0, 0, 0};

// -------------------------------------------------------
// HUD text
// -------------------------------------------------------
void drawText(float x, float y, const char* s) {
    glRasterPos2f(x, y);
    for (const char* c = s; *c; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
}

// -------------------------------------------------------
// Material
// -------------------------------------------------------
void setSkinMaterial() {
    GLfloat amb[]  = {0.50f, 0.35f, 0.25f, 1.0f};
    GLfloat diff[] = {0.90f, 0.70f, 0.52f, 1.0f};
    GLfloat spec[] = {0.30f, 0.20f, 0.15f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT,   amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  spec);
    glMaterialf (GL_FRONT, GL_SHININESS, 12.0f);
}

void setNailMaterial() {
    GLfloat amb[]  = {0.60f, 0.50f, 0.48f, 1.0f};
    GLfloat diff[] = {0.90f, 0.82f, 0.80f, 1.0f};
    GLfloat spec[] = {0.80f, 0.75f, 0.75f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT,   amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  spec);
    glMaterialf (GL_FRONT, GL_SHININESS, 60.0f);
}

// -------------------------------------------------------
// Helper: silinder solid
// -------------------------------------------------------
void drawCylinder(float r, float h, int sl) {
    GLUquadric* q = gluNewQuadric();
    gluQuadricNormals(q, GLU_SMOOTH);

    glPushMatrix();
        glRotatef(180, 1, 0, 0);
        gluDisk(q, 0, r, sl, 1);
    glPopMatrix();

    gluCylinder(q, r, r, h, sl, 1);

    glPushMatrix();
        glTranslatef(0, 0, h);
        gluDisk(q, 0, r, sl, 1);
    glPopMatrix();

    gluDeleteQuadric(q);
}

// -------------------------------------------------------
// Satu ruas jari
// -------------------------------------------------------
void drawPhalanx(float radius, float length, float bendAngle) {
    setSkinMaterial();

    glutSolidSphere(radius * 1.1, 16, 16);

    glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        drawCylinder(radius, length, 18);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, length, 0);
        glutSolidSphere(radius * 1.05, 16, 16);
    glPopMatrix();

    glTranslatef(0, length, 0);
    glRotatef(bendAngle, 1, 0, 0);
}

// -------------------------------------------------------
// Satu jari lengkap (3 ruas + kuku)
// -------------------------------------------------------
void drawFinger(float posX, float posZ,
                float baseAngle,
                float r1, float l1,
                float r2, float l2,
                float r3, float l3,
                float b) {
    glPushMatrix();
        glTranslatef(posX, 0, posZ);
        glRotatef(baseAngle, 0, 1, 0);
        glRotatef(-b * 15.0f, 1, 0, 0);

        drawPhalanx(r1, l1, b * 70.0f);
        drawPhalanx(r2, l2, b * 60.0f);

        setSkinMaterial();
        glutSolidSphere(r3 * 1.05, 16, 16);
        glPushMatrix();
            glRotatef(-90, 1, 0, 0);
            drawCylinder(r3, l3, 16);
        glPopMatrix();

        setNailMaterial();
        glPushMatrix();
            glTranslatef(0, l3 * 0.4f, -r3 * 0.6f);
            glRotatef(10, 1, 0, 0);
            glScalef(r3 * 1.4f, l3 * 0.6f, r3 * 0.25f);
            glutSolidCube(1.0f);
        glPopMatrix();

    glPopMatrix();
}

// -------------------------------------------------------
// Ibu jari
// -------------------------------------------------------
void drawThumb(float b) {
    glPushMatrix();
        glTranslatef(-0.52f, 0.0f, 0.15f);
        glRotatef(-60, 0, 1, 0);
        glRotatef( 20, 1, 0, 0);
        glRotatef(-b * 35.0f, 0, 1, 0);

        drawPhalanx(0.085f, 0.28f, b * 55.0f);

        setSkinMaterial();
        glutSolidSphere(0.082f, 16, 16);
        glPushMatrix();
            glRotatef(-90, 1, 0, 0);
            drawCylinder(0.075f, 0.22f, 16);
        glPopMatrix();

        setNailMaterial();
        glPushMatrix();
            glTranslatef(0, 0.22f * 0.4f, -0.075f * 0.6f);
            glRotatef(10, 1, 0, 0);
            glScalef(0.10f, 0.13f, 0.02f);
            glutSolidCube(1.0f);
        glPopMatrix();

    glPopMatrix();
}

// -------------------------------------------------------
// Telapak tangan
// -------------------------------------------------------
void drawHand() {
    glPushMatrix();
        glTranslatef(handX, handY, 0);

        setSkinMaterial();
        glPushMatrix();
            glScalef(1.0f, 0.28f, 0.9f);
            glutSolidSphere(0.6f, 24, 24);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0.13f, -0.25f);
            glScalef(0.9f, 0.12f, 0.35f);
            glutSolidSphere(0.6f, 16, 16);
        glPopMatrix();

        drawFinger(-0.36f, -0.42f,  8.0f,
                   0.060f, 0.20f, 0.055f, 0.15f, 0.050f, 0.12f, bend[0]);

        drawFinger(-0.12f, -0.48f,  3.0f,
                   0.072f, 0.25f, 0.065f, 0.19f, 0.058f, 0.14f, bend[1]);

        drawFinger( 0.12f, -0.50f,  0.0f,
                   0.078f, 0.28f, 0.070f, 0.21f, 0.062f, 0.15f, bend[2]);

        drawFinger( 0.36f, -0.46f, -4.0f,
                   0.072f, 0.25f, 0.065f, 0.19f, 0.058f, 0.14f, bend[3]);

        drawThumb(bend[4]);

    glPopMatrix();
}

// -------------------------------------------------------
// Pencahayaan
// -------------------------------------------------------
void setupLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    GLfloat l0pos[]  = { 3.0f,  5.0f,  4.0f, 1.0f};
    GLfloat l0diff[] = { 1.0f,  0.95f, 0.85f, 1.0f};
    GLfloat l0spec[] = { 1.0f,  1.0f,  1.0f,  1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, l0pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  l0diff);
    glLightfv(GL_LIGHT0, GL_SPECULAR, l0spec);

    GLfloat l1pos[]  = {-3.0f, 2.0f, -2.0f, 1.0f};
    GLfloat l1diff[] = { 0.3f, 0.30f, 0.40f, 1.0f};
    glLightfv(GL_LIGHT1, GL_POSITION, l1pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  l1diff);

    GLfloat ambient[] = {0.25f, 0.20f, 0.18f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
}

// -------------------------------------------------------
// Display
// -------------------------------------------------------
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -camDist);
    glRotatef(camPitch, 1, 0, 0);
    glRotatef(camYaw,   0, 1, 0);

    setupLighting();
    drawHand();

    // HUD
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 700, 0, 600);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glColor3f(0.9f, 0.9f, 0.9f);
        drawText(10, 80, "Drag mouse: rotasi kamera  |  Scroll: zoom");
        drawText(10, 60, "WASD: geser tangan  |  R: reset");
        drawText(10, 40, "1: kelingking  2: jari manis  3: jari tengah");
        drawText(10, 20, "4: telunjuk  5: ibu jari  |  ESC: keluar");

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();
}

// -------------------------------------------------------
// Mouse
// -------------------------------------------------------
void mouseButton(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON) {
        mouseDown = (state == GLUT_DOWN);
        lastMouseX = x;
        lastMouseY = y;
    }
    if (btn == 3) { camDist -= 0.2f; if (camDist < 1.5f) camDist = 1.5f; glutPostRedisplay(); }
    if (btn == 4) { camDist += 0.2f; if (camDist > 12.0f) camDist = 12.0f; glutPostRedisplay(); }
}

void mouseMotion(int x, int y) {
    if (!mouseDown) return;
    camYaw   += (x - lastMouseX) * 0.5f;
    camPitch += (y - lastMouseY) * 0.5f;
    if (camPitch >  89) camPitch =  89;
    if (camPitch < -89) camPitch = -89;
    lastMouseX = x;
    lastMouseY = y;
    glutPostRedisplay();
}

// -------------------------------------------------------
// Keyboard
// -------------------------------------------------------
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': case 'W': handY += 0.1f; break;
        case 's': case 'S': handY -= 0.1f; break;
        case 'a': case 'A': handX -= 0.1f; break;
        case 'd': case 'D': handX += 0.1f; break;
        case 'r': case 'R':
            handX = 0; handY = 0;
            camYaw = 20; camPitch = -25; camDist = 5.5f;
            bend[0] = bend[1] = bend[2] = bend[3] = bend[4] = 0;
            break;
        case '1': bend[0] = (bend[0] > 0.5f) ? 0.0f : 1.0f; break;
        case '2': bend[1] = (bend[1] > 0.5f) ? 0.0f : 1.0f; break;
        case '3': bend[2] = (bend[2] > 0.5f) ? 0.0f : 1.0f; break;
        case '4': bend[3] = (bend[3] > 0.5f) ? 0.0f : 1.0f; break;
        case '5': bend[4] = (bend[4] > 0.5f) ? 0.0f : 1.0f; break;
        case 27: exit(0);
    }
    glutPostRedisplay();
}

// -------------------------------------------------------
// Reshape
// -------------------------------------------------------
void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// -------------------------------------------------------
// Main
// -------------------------------------------------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Telapak Tangan 3D");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.15f, 0.15f, 0.18f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
    return 0;
}
