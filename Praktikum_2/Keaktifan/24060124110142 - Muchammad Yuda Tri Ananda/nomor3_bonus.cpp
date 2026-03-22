// Muchammad Yuda Tri Ananda - 24060124110142
// Minggu 3 - Bonus: Jaring Laba-Laba

#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846

void draw_titikTebel(float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void drawLurus(float length) {
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, length);
    glEnd();
}

void drawBengkok(float radius, float angleStep) {
    float angle = angleStep * PI / 180.0f;

    glBegin(GL_LINES);
        glVertex2f(0.0f, radius);
        glVertex2f(radius * sin(angle), radius * cos(angle));
    glEnd();
}

void display() {
    const int sisi = 8;
    const int lapisan = 5;
    const float panjangSpoke = 0.75f;
    const float jarakLapisan = 0.13f;
    const float sudutStep = 360.0f / sisi;

    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);

    glColor3f(0.95f, 0.95f, 0.95f);
    for (int i = 0; i < sisi; i++) {
        glPushMatrix();
            glRotatef(i * sudutStep, 0.0f, 0.0f, 1.0f);
            drawLurus(panjangSpoke);
        glPopMatrix();
    }

    glColor3f(0.55f, 0.85f, 1.0f);
    for (int ring = 1; ring <= lapisan; ring++) {
        float radius = ring * jarakLapisan;


        for (int i = 0; i < sisi; i++) {
            glPushMatrix();
                glRotatef(i * sudutStep, 0.0f, 0.0f, 1.0f);
                drawBengkok(radius, sudutStep);
            glPopMatrix();
        }
    }

    glColor3f(1.0f, 0.85f, 0.25f);
    draw_titikTebel(0.02f, 30);

    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Nomor 3 Bonus - Jaring Laba-Laba");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
