# nama  : Muchammad Yuda Tri Ananda
# nim   : 24060124110142
# kelas : E
#include <GL/glut.h>

void persegii(float cx, float cy, float s) {
    float h = s / 2.0f;
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // merah
        glVertex2f(cx - h, cy - h);

        glColor3f(1.0f, 1.0f, 0.0f); // kuning
        glVertex2f(cx + h, cy - h);

        glColor3f(0.0f, 1.0f, 0.0f); // hijau
        glVertex2f(cx + h, cy + h);

        glColor3f(0.0f, 0.0f, 1.0f); // biru
        glVertex2f(cx - h, cy + h);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // =========================
    // 1) GL_POINTS (titik)
    // =========================
    glPointSize(6.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // merah
    glBegin(GL_POINTS);
        glVertex2f(-0.85f, 0.85f);
        glVertex2f(-0.75f, 0.75f);
        glVertex2f(-0.65f, 0.85f);
    glEnd();

    // =========================
    // 2) GL_LINES (garis)
    // =========================
    glLineWidth(2.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // hijau
    glBegin(GL_LINES);
        glVertex2f(-0.95f, 0.60f);
        glVertex2f(-0.55f, 0.60f);
    glEnd();

    // =========================
    // 3) GL_LINE_STRIP (garis nyambung)
    // =========================
    glColor3f(0.2f, 0.6f, 1.0f); // biru muda
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.95f, 0.45f);
        glVertex2f(-0.80f, 0.35f);
        glVertex2f(-0.65f, 0.45f);
        glVertex2f(-0.55f, 0.30f);
    glEnd();

    // =========================
    // 4) GL_LINE_LOOP (loop)
    // =========================
    glColor3f(1.0f, 0.6f, 0.0f); // oranye
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.90f, 0.15f);
        glVertex2f(-0.60f, 0.15f);
        glVertex2f(-0.60f, -0.05f);
        glVertex2f(-0.90f, -0.05f);
    glEnd();

    // =========================
    // 5) GL_TRIANGLE_FAN
    // =========================
    glColor3f(0.7f, 0.1f, 0.9f); // ungu
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.70f, -0.35f);   // pusat
        glVertex2f(-0.85f, -0.25f);
        glVertex2f(-0.60f, -0.25f);
        glVertex2f(-0.55f, -0.45f);
        glVertex2f(-0.70f, -0.55f);
        glVertex2f(-0.85f, -0.45f);
        glVertex2f(-0.85f, -0.25f);   // tutup fan
    glEnd();

    // =========================
    // 6) GL_TRIANGLE_STRIP
    // =========================
    glColor3f(0.2f, 0.8f, 0.4f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.30f, 0.80f);
        glVertex2f(-0.10f, 0.70f);
        glVertex2f(-0.25f, 0.60f);
        glVertex2f(-0.05f, 0.50f);
        glVertex2f(-0.20f, 0.40f);
        glVertex2f( 0.00f, 0.30f);
    glEnd();

    // =========================
    // 7) GL_QUAD_STRIP
    // =========================
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.30f, 0.10f);
        glVertex2f(-0.10f, 0.10f);
        glVertex2f(-0.25f, -0.10f);
        glVertex2f(-0.05f, -0.10f);
        glVertex2f(-0.20f, -0.30f);
        glVertex2f( 0.00f, -0.30f);
    glEnd();

    // =========================
    // 8) Kubus bertingkat (min 5) pakai GL_QUADS
    // Contoh: 3 bawah + 2 atas
    // =========================
    float s = 0.18f; // ukuran 
    
    // warna warni (rainbow)
    glColor3f(1.0f, 0.0f, 0.0f); // merah
    persegii(0.35f, -0.15f, s);

    glColor3f(1.0f, 0.5f, 0.0f); // oranye
    persegii(0.75f, -0.15f, s);

    glColor3f(1.0f, 1.0f, 0.0f); // kuning
    persegii(0.55f, -0.35f, s);

    glColor3f(0.0f, 1.0f, 0.0f); // hijau
    persegii(0.40f, -0.55f, s);

    glColor3f(0.0f, 0.2f, 1.0f); // biru
    persegii(0.70f, -0.55f, s);


    glFlush(); 
}

void init() {

    glClearColor(0.97f, 0.95f, 0.86f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Koordinat 2D -1..1
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Project Praktikum GKV 1 - myudakk");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
