// Muchammad Yuda Tri Ananda - 24060124110142
// Minggu 1 - Nomor 1: Lingkaran

#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846

void gambarLingkaran(float jariJari, int jumlahSegmen) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < jumlahSegmen; i++) {
        float sudut = 2.0f * PI * i / jumlahSegmen;
        glVertex2f(jariJari * cos(sudut), jariJari * sin(sudut));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.45f, 100);
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
    glutCreateWindow("Nomor 1 - Lingkaran");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
