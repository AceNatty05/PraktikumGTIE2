#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ===============================
    // 1. GL_LINE_STRIP
    // ===============================
    glColor3f(1.0, 0.0, 0.0); // Merah
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9, 0.7);
        glVertex2f(-0.7, 0.9);
        glVertex2f(-0.5, 0.7);
        glVertex2f(-0.3, 0.9);
    glEnd();

    // ===============================
    // 2. GL_LINE_LOOP
    // ===============================
    glColor3f(0.0, 1.0, 0.0); // Hijau
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.2, 0.7);
        glVertex2f(0.4, 0.9);
        glVertex2f(0.6, 0.7);
        glVertex2f(0.4, 0.5);
    glEnd();

    // ===============================
    // 3. GL_TRIANGLE_FAN
    // ===============================
    glColor3f(0.0, 0.0, 1.0); // Biru
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.7, 0.0); // titik pusat
        glVertex2f(-0.9, -0.2);
        glVertex2f(-0.7, -0.4);
        glVertex2f(-0.5, -0.2);
        glVertex2f(-0.7, 0.0);
    glEnd();

    // ===============================
    // 4. GL_TRIANGLE_STRIP
    // ===============================
    glColor3f(1.0, 1.0, 0.0); // Kuning
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.2, 0.0);
        glVertex2f(0.0, -0.4);
        glVertex2f(0.2, 0.0);
        glVertex2f(0.4, -0.4);
    glEnd();

    // ===============================
    // 5. GL_QUADS
    // ===============================
    glColor3f(1.0, 0.0, 1.0); // Ungu
    glBegin(GL_QUADS);
        glVertex2f(0.5, 0.0);
        glVertex2f(0.8, 0.0);
        glVertex2f(0.8, -0.3);
        glVertex2f(0.5, -0.3);
    glEnd();

    // ===============================
    // 6. GL_QUAD_STRIP
    // ===============================
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.9, -0.7);
        glVertex2f(-0.9, -0.9);
        glVertex2f(-0.6, -0.7);
        glVertex2f(-0.6, -0.9);
        glVertex2f(-0.3, -0.7);
        glVertex2f(-0.3, -0.9);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Background putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Contoh Primitive OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
