// Nama		: Harits Permana
// NIM		: 24060124140131
// LAB		: E2


// Nama		: Harits Permana
// NIM		: 24060124140131
// LAB		: E2


#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846f;

int modeTampil = 1;      // 1 = lingkaran, 2 = mobil
float carPosX = 0.0f;    // translasi mobil
float rotAngle = 0.0f;   // rotasi ornamen/kipas

void drawCircle(float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * i / segments;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawWheel() {
    // Ban luar
    glColor3f(0.1f, 0.1f, 0.1f);
    drawCircle(0.12f, 50);

    // Velg
    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(0.06f, 40);

    // Jari-jari roda
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
        glVertex2f(-0.06f, 0.0f); glVertex2f(0.06f, 0.0f);
        glVertex2f(0.0f, -0.06f); glVertex2f(0.0f, 0.06f);
        glVertex2f(-0.042f, -0.042f); glVertex2f(0.042f, 0.042f);
        glVertex2f(-0.042f, 0.042f); glVertex2f(0.042f, -0.042f);
    glEnd();
}

void drawFan() {
    // pusat
    glColor3f(0.9f, 0.2f, 0.2f);
    drawCircle(0.03f, 30);

    // baling-baling (rotasi)
    glPushMatrix(); // stack digunakan
    glRotatef(rotAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 0.8f, 0.0f);
    for (int i = 0; i < 4; i++) {
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.18f, 0.03f);
            glVertex2f(0.18f, -0.03f);
        glEnd();
    }

    glPopMatrix(); // stack digunakan
}

void drawCar() {
    glPushMatrix();               // stack utama mobil
    glTranslatef(carPosX, 0.0f, 0.0f); // translasi mobil

    // badan bawah mobil
    glColor3f(0.1f, 0.4f, 0.9f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, -0.1f);
        glVertex2f( 0.7f, -0.1f);
        glVertex2f( 0.6f,  0.2f);
        glVertex2f(-0.6f,  0.2f);
    glEnd();

    // atap mobil
    glColor3f(0.0f, 0.3f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35f, 0.2f);
        glVertex2f( 0.25f, 0.2f);
        glVertex2f( 0.05f, 0.45f);
        glVertex2f(-0.2f, 0.45f);
    glEnd();

    // kaca
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.28f, 0.22f);
        glVertex2f(-0.05f, 0.22f);
        glVertex2f(-0.12f, 0.4f);
        glVertex2f(-0.22f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.22f);
        glVertex2f(0.2f, 0.22f);
        glVertex2f(0.03f, 0.4f);
        glVertex2f(-0.07f, 0.4f);
    glEnd();

    // lampu depan
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.65f, 0.02f);
        glVertex2f(0.72f, 0.02f);
        glVertex2f(0.72f, 0.12f);
        glVertex2f(0.65f, 0.12f);
    glEnd();

    // lampu belakang
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.72f, 0.02f);
        glVertex2f(-0.65f, 0.02f);
        glVertex2f(-0.65f, 0.12f);
        glVertex2f(-0.72f, 0.12f);
    glEnd();

    // roda kiri
    glPushMatrix();
    glTranslatef(-0.45f, -0.12f, 0.0f);
    drawWheel();
    glPopMatrix();

    // roda kanan
    glPushMatrix();
    glTranslatef(0.45f, -0.12f, 0.0f);
    drawWheel();
    glPopMatrix();

    // tiang ornamen
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.45f);
        glVertex2f(0.0f, 0.62f);
    glEnd();

    // kipas/ornamen berotasi di atas mobil
    glPushMatrix();
    glTranslatef(0.0f, 0.62f, 0.0f);
    drawFan();
    glPopMatrix();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (modeTampil == 1) {
        // Tugas 1: Lingkaran
        glPushMatrix();
        glColor3f(1.0f, 0.4f, 0.4f);
        drawCircle(0.4f, 100);
        glPopMatrix();
    } else {
        // Tugas 2: Mobil 2D
        drawCar();
    }

    glutSwapBuffers();
}

void update() {
    carPosX += 0.001f;
    rotAngle += 5.0f;

    if (carPosX > 1.2f) { 
        rotAngle = -1.2f;
		carPosX = -1.2f;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            modeTampil = 1;
            break;
        case '2':
            modeTampil = 2;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lingkaran (1) dan Mobil 2D (2)");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}