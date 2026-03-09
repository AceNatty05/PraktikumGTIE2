// Muchammad Yuda Tri Ananda - 24060124110142
// Minggu 2 - Nomor 2: Mobil 2D


#include <GL/glut.h>
#include <cmath>

void gambarLingkaranIsi(float jariJari, int jumlahSegmen) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < jumlahSegmen; i++) {
        float sudut = 2.0f * 3.14159265358979323846f * i / jumlahSegmen;
        glVertex2f(jariJari * cos(sudut), jariJari * sin(sudut));
    }
    glEnd();
}

void gambarRoda() {
    glColor3f(0.1f, 0.1f, 0.1f);
    gambarLingkaranIsi(0.12f, 50);

    glColor3f(0.8f, 0.8f, 0.8f);
    gambarLingkaranIsi(0.05f, 50);

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.10f, 0.0f); glVertex2f(0.10f, 0.0f);
        glVertex2f(0.0f, -0.10f); glVertex2f(0.0f, 0.10f);
        glVertex2f(-0.07f, -0.07f); glVertex2f(0.07f, 0.07f);
        glVertex2f(-0.07f, 0.07f); glVertex2f(0.07f, -0.07f);
    glEnd();
}

void gambarBodiMobil() {
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.60f, -0.05f);
        glVertex2f( 0.60f, -0.05f);
        glVertex2f( 0.60f,  0.20f);
        glVertex2f(-0.60f,  0.20f);
    glEnd();

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.30f, 0.20f);
        glVertex2f( 0.20f, 0.20f);
        glVertex2f( 0.35f, 0.38f);
        glVertex2f(-0.15f, 0.38f);
    glEnd();

    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.10f, 0.23f);
        glVertex2f( 0.15f, 0.23f);
        glVertex2f( 0.27f, 0.35f);
        glVertex2f(-0.02f, 0.35f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.55f, 0.03f);
        glVertex2f(0.60f, 0.03f);
        glVertex2f(0.60f, 0.12f);
        glVertex2f(0.55f, 0.12f);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.60f, 0.03f);
        glVertex2f(-0.55f, 0.03f);
        glVertex2f(-0.55f, 0.12f);
        glVertex2f(-0.60f, 0.12f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(0.0f, -0.1f, 0.0f);

        gambarBodiMobil();

        glPushMatrix();
            glTranslatef(-0.35f, -0.05f, 0.0f);
            glRotatef(25.0f, 0.0f, 0.0f, 1.0f);
            gambarRoda();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.35f, -0.05f, 0.0f);
            glRotatef(25.0f, 0.0f, 0.0f, 1.0f);
            gambarRoda();
        glPopMatrix();
    glPopMatrix();

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
    glutCreateWindow("Nomor 2 - Mobil 2D");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
