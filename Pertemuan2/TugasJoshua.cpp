// Nama        : Joshua Satria Kusuma
// NIM         : 24060124130113
// Kelas/lab   : E / E2

#include <GLUT/glut.h>
#include <math.h>

#define PI 3.14159265f

void drawCircle(float cx, float cy, float r, int seg) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < seg; i++) {
        float a = 2.0f * PI * i / seg;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

void drawBuilding(float x, float y, float w, float h,
                  float r, float g, float b) {
    glColor3f(r, g, b);
    glRectf(x, y, x + w, y + h);

    glColor3f(r * 0.5f, g * 0.5f, b * 0.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,     y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x,     y + h);
    glEnd();

    float winW = w * 0.22f, winH = 0.055f;
    float col1 = x + w * 0.10f, col2 = x + w * 0.55f;
    for (float wy = y + 0.06f; wy + winH < y + h - 0.04f; wy += 0.10f) {
        int litL = ((int)(wy * 13.f)) % 5 != 0;
        glColor3f(litL ? 1.0f : 0.15f, litL ? 0.95f : 0.15f, litL ? 0.5f : 0.15f);
        glRectf(col1, wy, col1 + winW, wy + winH);

        int litR = ((int)(wy * 17.f)) % 4 != 0;
        glColor3f(litR ? 1.0f : 0.15f, litR ? 0.95f : 0.15f, litR ? 0.5f : 0.15f);
        glRectf(col2, wy, col2 + winW, wy + winH);
    }
}

void road() {
    glColor3f(0.18f, 0.18f, 0.18f);
    glRectf(-1.0f, -1.0f, 1.0f, -0.20f);

    glColor3f(0.55f, 0.55f, 0.55f);
    glRectf(-1.0f, -0.22f, 1.0f, -0.20f);
    glRectf(-1.0f, -1.00f, 1.0f, -0.97f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, -0.60f);
    glVertex2f( 1.0f, -0.60f);
    glEnd();

    for (int i = 0; i < 10; i++) {
        float xd = -1.0f + i * 0.22f;
        glColor3f(1.0f, 0.85f, 0.0f);
        glRectf(xd, -0.405f, xd + 0.12f, -0.385f);
    }

    for (int i = 0; i < 10; i++) {
        float xd = -1.0f + i * 0.22f;
        glColor3f(1.0f, 0.85f, 0.0f);
        glRectf(xd, -0.805f, xd + 0.12f, -0.785f);
    }
}

void drawCar(float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25f, -0.07f);
    glVertex2f( 0.25f, -0.07f);
    glVertex2f( 0.25f,  0.05f);
    glVertex2f(-0.25f,  0.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.14f,  0.05f);
    glVertex2f( 0.14f,  0.05f);
    glVertex2f( 0.11f,  0.14f);
    glVertex2f(-0.11f,  0.14f);
    glEnd();

    glColor3f(0.55f, 0.82f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f( 0.04f, 0.055f);
    glVertex2f( 0.13f, 0.055f);
    glVertex2f( 0.11f, 0.130f);
    glVertex2f( 0.05f, 0.130f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.13f, 0.055f);
    glVertex2f(-0.04f, 0.055f);
    glVertex2f(-0.05f, 0.130f);
    glVertex2f(-0.11f, 0.130f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.5f);
    glRectf(0.21f, -0.04f, 0.26f, 0.02f);

    glColor3f(0.9f, 0.1f, 0.1f);
    glRectf(-0.26f, -0.04f, -0.21f, 0.02f);

    glColor3f(0.3f, 0.3f, 0.3f);
    glRectf( 0.25f, -0.07f,  0.28f, 0.00f);
    glRectf(-0.28f, -0.07f, -0.25f, 0.00f);

    glColor3f(0.1f, 0.1f, 0.1f);
    drawCircle( 0.13f, -0.07f, 0.058f, 20);
    drawCircle(-0.13f, -0.07f, 0.058f, 20);

    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle( 0.13f, -0.07f, 0.028f, 20);
    drawCircle(-0.13f, -0.07f, 0.028f, 20);
}

void drawTrafficLight(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glColor3f(0.3f, 0.3f, 0.3f);
    glRectf(-0.013f, 0.0f, 0.013f, 0.24f);

    glColor3f(0.08f, 0.08f, 0.08f);
    glRectf(-0.035f, 0.24f, 0.035f, 0.40f);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.375f, 0.014f, 18);

    glColor3f(0.25f, 0.20f, 0.0f);
    drawCircle(0.0f, 0.320f, 0.014f, 18);

    glColor3f(0.0f, 0.25f, 0.0f);
    drawCircle(0.0f, 0.265f, 0.014f, 18);

    glPopMatrix();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);
    glColor3f(0.15f, 0.35f, 0.80f);
    glVertex2f(-1.0f,  1.0f);
    glVertex2f( 1.0f,  1.0f);
    glColor3f(0.55f, 0.75f, 1.0f);
    glVertex2f( 1.0f, -0.20f);
    glVertex2f(-1.0f, -0.20f);
    glEnd();


    drawBuilding(-1.00f, -0.20f, 0.28f, 1.15f, 0.38f, 0.40f, 0.58f); 
    drawBuilding(-0.68f, -0.20f, 0.25f, 0.90f, 0.50f, 0.42f, 0.38f);
    drawBuilding( 0.43f, -0.20f, 0.28f, 1.05f, 0.40f, 0.40f, 0.56f);
    drawBuilding( 0.74f, -0.20f, 0.26f, 0.88f, 0.36f, 0.52f, 0.42f);

    road();

    drawTrafficLight(-0.05f, -0.22f);


    glPushMatrix();
      glTranslatef(-0.60f, -0.40f, 0.0f);
      glScalef(0.52f, 0.52f, 1.0f);
      drawCar(0.10f, 0.20f, 0.92f); 
    glPopMatrix();

    glPushMatrix();
      glTranslatef( 0.10f, -0.40f, 0.0f);
      glScalef(0.52f, 0.52f, 1.0f);
      drawCar(0.92f, 0.10f, 0.10f); 
    glPopMatrix();

    glPushMatrix();
      glTranslatef( 0.65f, -0.40f, 0.0f);
      glScalef(0.48f, 0.48f, 1.0f);
      drawCar(0.92f, 0.92f, 0.92f);
    glPopMatrix();

    glPushMatrix();
      glTranslatef( 0.55f, -0.80f, 0.0f);
      glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
      glScalef(0.52f, 0.52f, 1.0f);
      drawCar(0.10f, 0.75f, 0.20f); 
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-0.20f, -0.80f, 0.0f);
      glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
      glScalef(0.50f, 0.50f, 1.0f);
      drawCar(0.96f, 0.80f, 0.05f); 
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(0.55f, 0.75f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 80);
    glutCreateWindow("Tugas Menggambar Mobil");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}