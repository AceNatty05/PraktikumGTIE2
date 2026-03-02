#include <windows.h>
#include <GL/glut.h>

void drawCube(float x, float y, float size) {
    // Isi kotak
    glColor3f(0.3f, 0.6f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();

    // Garis tepi
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float size = 0.3f;
    float gapX = 0.05f;   // hanya jarak kiri-kanan
    float y = -0.5f;

    // Baris bawah (3 kubus)
    for(int i = -1; i <= 1; i++) {
        drawCube(i*(size+gapX), y, size);
    }

    // Baris atas (2 kubus) ? nempel vertikal
    y += size;  // TANPA gap
    for(int i = -1; i <= 0; i++) {
        drawCube(i*(size+gapX) + size/2, y, size);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Kubus Bertingkat");
    glutDisplayFunc(display);
    glClearColor(1.0,1.0,1.0,1.0);
    glutMainLoop();
    return 0;
}
