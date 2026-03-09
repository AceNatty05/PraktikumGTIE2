#include <gl/glut.h>

void drawCube(float x, float y, float size) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void TugasKubus(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4f, 0.6f, 0.9f);

    float s = 0.25f;
    float g = 0.01f;

    drawCube(-1.5 * s - g, -0.3, s);
    drawCube(-0.5 * s, -0.3, s);
    drawCube(0.5 * s + g, -0.3, s);

    drawCube(-s - (g / 2), -0.3 + s + g, s);
    drawCube(0 + (g / 2), -0.3 + s + g, s);

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas: Kubus Bertingkat");
    glutDisplayFunc(TugasKubus);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
