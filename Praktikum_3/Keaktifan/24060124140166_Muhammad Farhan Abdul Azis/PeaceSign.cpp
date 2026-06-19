// Nama : Muhammad Farhan Abdul Azis
// NIM  : 24060124140166
// Deskripsi : Emoji berbentuk peace sign dengan susunan kode yang lebih ringkas

#include <GL/glut.h>

namespace {

const int kMaxRuas = 3;

struct BentukRuas {
    float panjang;
    float tebalY;
    float tebalZ;
};

struct DataJari {
    float posisiX;
    float posisiY;
    float rotasiAwal;
    int jumlahRuas;
    int* sudut;
    BentukRuas ruas[kMaxRuas];
};

int shoulder = 0;
int elbow = 45;
int wrist = 0;

int thumb[] = {240, 10, 0};
int indexFinger[] = {0, 0, 0};
int middleFinger[] = {0, 0, 0};
int ringFinger[] = {70, 70, 70};
int littleFinger[] = {80, 80, 80};

void gambarBalok(float panjang, float tebalY, float tebalZ) {
    glPushMatrix();
    glTranslatef(panjang * 0.5f, 0.0f, 0.0f);
    glScalef(panjang, tebalY, tebalZ);
    glutWireCube(1.0);
    glPopMatrix();
}

void gambarJari(const DataJari& jari) {
    glPushMatrix();
    glTranslatef(jari.posisiX, jari.posisiY, 0.0f);

    for (int i = 0; i < jari.jumlahRuas; ++i) {
        const float rotasi = (i == 0) ? jari.rotasiAwal + jari.sudut[i] : jari.sudut[i];
        glRotatef(rotasi, 0.0f, 0.0f, 1.0f);
        gambarBalok(jari.ruas[i].panjang, jari.ruas[i].tebalY, jari.ruas[i].tebalZ);
        glTranslatef(jari.ruas[i].panjang, 0.0f, 0.0f);
    }

    glPopMatrix();
}

void gambarLengan() {
    glPushMatrix();
    glTranslatef(-2.5f, 0.0f, 0.0f);
    glRotatef(static_cast<GLfloat>(shoulder), 0.0f, 0.0f, 1.0f);
    gambarBalok(2.0f, 0.4f, 0.4f);

    glTranslatef(2.0f, 0.0f, 0.0f);
    glRotatef(static_cast<GLfloat>(elbow), 0.0f, 0.0f, 1.0f);
    gambarBalok(2.0f, 0.4f, 0.35f);

    glTranslatef(2.0f, 0.0f, 0.0f);
    glRotatef(static_cast<GLfloat>(wrist), 0.0f, 0.0f, 1.0f);

    glPushMatrix();
    glTranslatef(0.3f, 0.0f, 0.0f);
    glScalef(0.6f, 0.8f, 0.3f);
    glutWireCube(1.0);
    glPopMatrix();

    const DataJari daftarJari[] = {
        {0.15f, 0.45f, 0.0f, 2, thumb, {{0.3f, 0.2f, 0.2f}, {0.3f, 0.18f, 0.18f}, {0.0f, 0.0f, 0.0f}}},
        {0.6f, 0.25f, 10.0f, 3, indexFinger, {{0.4f, 0.18f, 0.18f}, {0.36f, 0.16f, 0.16f}, {0.3f, 0.15f, 0.15f}}},
        {0.6f, 0.05f, -10.0f, 3, middleFinger, {{0.45f, 0.18f, 0.18f}, {0.36f, 0.16f, 0.16f}, {0.3f, 0.15f, 0.15f}}},
        {0.6f, -0.15f, 0.0f, 3, ringFinger, {{0.4f, 0.18f, 0.18f}, {0.36f, 0.16f, 0.16f}, {0.3f, 0.15f, 0.15f}}},
        {0.6f, -0.35f, 0.0f, 3, littleFinger, {{0.3f, 0.18f, 0.18f}, {0.28f, 0.16f, 0.16f}, {0.24f, 0.14f, 0.14f}}},
    };

    for (const DataJari& jari : daftarJari) {
        gambarJari(jari);
    }

    glPopMatrix();
}

}  // namespace

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    gambarLengan();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, static_cast<GLfloat>(w) / static_cast<GLfloat>(h), 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Emoji Peace Sign");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
