// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Snowflake dengan semua lengan & cabang rotasi otomatis

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void Snowflake() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glColor3f(0.8f, 0.9f, 1.0f);

    int numArms = 6; // snowflake 6 lengan
    float mainLength = 0.5f; // panjang garis utama
    float branchLength = 0.12f; // panjang cabang kecil

    for (int i = 0; i < numArms; i++) {
        glPushMatrix();
        glRotatef(i * 60.0f, 0,0,1); // rotasi setiap lengan

        glBegin(GL_LINES);
        // garis utama
        glVertex2f(0,0); glVertex2f(0, mainLength);

        // diagonal kiri dan kanan sepanjang garis utama
        for(float p=0.2f; p<=mainLength; p+=0.15f) {
            glVertex2f(0, p); glVertex2f(-branchLength, p + branchLength);
            glVertex2f(0, p); glVertex2f(branchLength, p + branchLength);
        }

        // garis diagonal tambahan dari pusat
        glVertex2f(0,0); glVertex2f(0.35f,0.35f);
        glVertex2f(0,0); glVertex2f(-0.35f,0.35f);

        glEnd();
        glPopMatrix();
    }

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Beautiful Snowflake");
    glutDisplayFunc(Snowflake);

    glClearColor(0.0f, 0.0f, 0.1f, 1.0f); // latar biru gelap
    glutMainLoop();
    return 0;
}
