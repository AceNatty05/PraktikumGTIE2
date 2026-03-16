/*Nama	: Muhammad Fauzan Akbar
  NIM	: 24060124140139
  LAB	: GTI E2
*/
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846

void gambarLingkaranIsi(float r, int seg) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < seg; i++) {
        float s = 2.0f * PI * i / seg;
        glVertex2f(r * cos(s), r * sin(s));
    }
    glEnd();
}

void gambarRoda() {
    glColor3f(0.15f, 0.15f, 0.15f);
    gambarLingkaranIsi(0.14f, 40);

    glColor3f(0.4f, 0.4f, 0.4f);
    gambarLingkaranIsi(0.09f, 40);

    glColor3f(0.8f, 0.8f, 0.8f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        for (int i = 0; i < 8; i++) {
            float sudut = i * 45.0f * PI / 180.0f;
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.09f * cos(sudut), 0.09f * sin(sudut));
        }
    glEnd();
}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Body mobil
    glPushMatrix();
        glColor3f(0.1f, 0.3f, 0.7f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.75f, -0.25f);
            glVertex2f( 0.75f, -0.25f);
            glVertex2f( 0.72f,  0.05f);
            glVertex2f( 0.35f,  0.10f);
            glVertex2f(-0.65f,  0.10f);
            glVertex2f(-0.72f,  0.00f);
        glEnd();
    glPopMatrix();

    // Kabin atas
    glPushMatrix();
        glColor3f(0.1f, 0.3f, 0.7f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.40f, 0.10f);
            glVertex2f( 0.25f, 0.10f);
            glVertex2f( 0.05f, 0.38f);
            glVertex2f(-0.35f, 0.38f);
        glEnd();
    glPopMatrix();

    // Jendela depan
    glPushMatrix();
        glColor3f(0.8f, 0.95f, 1.0f);
        glBegin(GL_TRIANGLES);
            glVertex2f( 0.08f, 0.15f);
            glVertex2f( 0.20f, 0.15f);
            glVertex2f( 0.08f, 0.33f);
        glEnd();
    glPopMatrix();

    // Jendela belakang
    glPushMatrix();
        glColor3f(0.8f, 0.95f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.32f, 0.15f);
            glVertex2f( 0.02f, 0.15f);
            glVertex2f(-0.02f, 0.33f);
            glVertex2f(-0.30f, 0.33f);
        glEnd();
    glPopMatrix();

    // Lampu depan
    glPushMatrix();
        glColor3f(1.0f, 0.9f, 0.0f);
        glRectf(0.70f, -0.05f, 0.74f, 0.05f);
    glPopMatrix();

    // Lampu blkg
    glPushMatrix();
        glColor3f(0.8f, 0.0f, 0.0f);
        glRectf(-0.69f, -0.04f, -0.65f, 0.04f);
    glPopMatrix();

    // Roda kiri
    glPushMatrix();
        glTranslatef(-0.45f, -0.25f, 0.0f);
        gambarRoda();
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
        glTranslatef(0.45f, -0.25f, 0.0f);
        gambarRoda();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 400);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Mobil 2D");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}
