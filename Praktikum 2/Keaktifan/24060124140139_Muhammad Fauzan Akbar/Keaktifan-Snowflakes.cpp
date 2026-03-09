/* 
Nama: Muhammad Fauzan Akbar
NIM: 24060124140139
Keaktifan 2 - Snowflakes/Spider Webs
*/
#include <GL/glut.h>
void GambarLengan() {
    glLineWidth(3.0);
    glBegin(GL_LINES);
        // Batang utama
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.7);
        // cabang hiasan
        // (bawah)
        glVertex2f(0.0, 0.3);
        glVertex2f(0.15, 0.45);
        glVertex2f(0.0, 0.3);
        glVertex2f(-0.15, 0.45);
        // (atas)
        glVertex2f(0.0, 0.5);
        glVertex2f(0.1, 0.6);
        glVertex2f(0.0, 0.5);
        glVertex2f(-0.1, 0.6);
    glEnd();
}
void gambar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4, 0.7, 1.0);
    int jumlahSisi = 8;
    float sudut = 360.0 / jumlahSisi;
    for (int i = 0; i < jumlahSisi; i++) {
        glPushMatrix();
            glRotatef(i * sudut, 0.0, 0.0, 1.0);
            GambarLengan();
        glPopMatrix();
    }
    glFlush();
}
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Keaktifan - Snowflake");
    init();
    glutDisplayFunc(gambar);
    glutMainLoop();
    return 0;
}
