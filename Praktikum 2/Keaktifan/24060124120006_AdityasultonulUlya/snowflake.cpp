#include <GL/glut.h>
#include <math.h>

void snowflake() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    
    // ===== LINGKARAN PUSAT =====
    int segments = 30;
    float radius = 0.09;
    glBegin(GL_POLYGON);
        for(int i = 0; i < segments; i++) {
            float angle = 2.0 * 3.14159 * i / segments;
            glVertex2f(radius * cos(angle), radius * sin(angle));
        }
    glEnd();
    
    // ===== LENGAN DENGAN DUA TANDA PANAH =====
    glLineWidth(8.0);
    
    int sides = 8;
    float angle_rotate = 360.0 / sides;
    
    glPushMatrix();
    
    for(int i = 0; i < sides; i++) {
        // GAMBAR LENGAN UTAMA
        glBegin(GL_LINES);
            glVertex2f(0.0, 0.0);
            glVertex2f(0.0, 0.75);  // lengan lebih panjang
        glEnd();
        
        // === TANDA PANAH 1 (BAWAH) ===
        // Di posisi y = 0.25 dari pusat
        glBegin(GL_LINES);
            // cabang kanan bawah
            glVertex2f(0.0, 0.25);
            glVertex2f(0.1, 0.35);
            
            // cabang kiri bawah
            glVertex2f(0.0, 0.25);
            glVertex2f(-0.1, 0.35);
        glEnd();
        
        // === TANDA PANAH 2 (ATAS) ===
        // Di posisi y = 0.5 dari pusat
        glBegin(GL_LINES);
            // cabang kanan atas
            glVertex2f(0.0, 0.5);
            glVertex2f(0.12, 0.62);  // sedikit lebih panjang/lebar
            
            // cabang kiri atas
            glVertex2f(0.0, 0.5);
            glVertex2f(-0.12, 0.62);
        glEnd();
        
        // === TAMBAHAN: ORNAMEN DI UJUNG (opsional) ===
        // Bisa ditambah segitiga kecil di ujung
        glBegin(GL_TRIANGLES);
            glVertex2f(0.0, 0.75);
            glVertex2f(0.07, 0.68);
            glVertex2f(-0.07, 0.68);
        glEnd();
        
        glRotatef(angle_rotate, 0.0, 0.0, 1.0);
    }
    
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Snowflake Rotation");

    glutDisplayFunc(snowflake);

    glClearColor(0.0,0.0,0.0,1.0);

    glutMainLoop();
}
