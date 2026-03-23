// Nama: Muhammad Fauzan Akbar
// NIM: 24060124140139
// LAB: PBO E2

#include <GL/glut.h>

void border() {
    glLineWidth(5.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.9f, -0.9f);
        glVertex2f( 0.9f, -0.9f);
        glVertex2f( 0.9f,  0.9f);
        glVertex2f(-0.9f,  0.9f);
    glEnd();
}

void langit() {
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.1f);
        glVertex2f(-0.9f,  0.9f);
        glVertex2f( 0.9f,  0.9f);
        glColor3f(1.0f, 0.8f, 0.4f);
        glVertex2f( 0.9f,  0.0f);
        glVertex2f(-0.9f,  0.0f);
    glEnd();
}

void matahari() {
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.9f, 0.2f);
        glVertex2f(0.0f, 0.05f);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.2f,  0.05f);
        glVertex2f(-0.14f, 0.22f);
        glVertex2f( 0.0f,  0.3f);
        glVertex2f( 0.14f, 0.22f);
        glVertex2f( 0.2f,  0.05f);
    glEnd();
}

void laut() {
    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 0.65f, 0.2f);
        glVertex2f(-0.9f,  0.0f);
        glVertex2f( 0.9f,  0.0f);

        glColor3f(0.2f, 0.4f, 0.7f);
        glVertex2f(-0.9f, -0.3f);
        glVertex2f( 0.9f, -0.3f);

        glColor3f(0.1f, 0.2f, 0.5f);
        glVertex2f(-0.9f, -0.9f);
        glVertex2f( 0.9f, -0.9f);
    glEnd();
}

void refleksi() {
    glLineWidth(2.0f);
    glColor3f(1.0f, 0.85f, 0.3f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.15f, -0.05f);
        glVertex2f(-0.05f, -0.08f);
        glVertex2f( 0.0f,  -0.06f);
        glVertex2f( 0.05f, -0.09f);
        glVertex2f( 0.15f, -0.05f);
    glEnd();
}

void kapal() {
    // Badan kapal
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.3f, 0.2f, 0.1f);
        glVertex2f(-0.4f, -0.25f);
        glVertex2f(-0.45f, -0.4f);
        glVertex2f( 0.0f, -0.25f);
        glVertex2f( 0.0f, -0.4f);
        glVertex2f( 0.4f, -0.25f);
        glVertex2f( 0.35f, -0.4f);
    glEnd();

    // Dek kapal
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.35f, 0.15f);
        glVertex2f(-0.42f, -0.25f);
        glVertex2f( 0.42f, -0.25f);
        glVertex2f( 0.42f, -0.2f);
        glVertex2f(-0.42f, -0.2f);
    glEnd();

    // Tiang layar
    glLineWidth(3.0f);
    glColor3f(0.25f, 0.15f, 0.05f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.0f, -0.2f);
        glVertex2f(0.0f,  0.15f);
    glEnd();

    // Layar
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.95f, 0.92f, 0.85f);
        glVertex2f(0.0f, -0.2f);
        glColor3f(0.85f, 0.8f, 0.7f);
        glVertex2f(0.0f,  0.12f);
        glVertex2f(0.3f, -0.1f);
        glVertex2f(0.3f, -0.2f);
    glEnd();

    // Jendela kapal
    glBegin(GL_QUADS);
        glColor3f(0.6f, 0.85f, 1.0f);
        glVertex2f(-0.2f, -0.37f);
        glVertex2f(-0.12f,-0.37f);
        glVertex2f(-0.12f,-0.28f);
        glVertex2f(-0.2f, -0.28f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    langit();
    matahari();
    laut();
    refleksi();
    kapal();
    border();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Ocean Sunset");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}

