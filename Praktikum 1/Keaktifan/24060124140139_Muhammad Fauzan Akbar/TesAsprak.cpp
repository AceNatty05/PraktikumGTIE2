/* 
Nama: Muhammad Fauzan Akbar
NIM: 24060124140139
*/

#include <gl/glut.h>

void gambarSatuKotak(float x, float y, float size) {
    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.07f);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.99f, 0.82f);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void gambarbilah(float x, float y, float size) {
    glBegin(GL_QUADS);
        glColor3f(0.75f, 0.75f, 0.75f);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.99f, 0.82f);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float s = 0.25f;

    // batang
    gambarSatuKotak( 0.100f,  -0.50f, s);
    gambarSatuKotak( -0.4f,  -0.50f, s);
    gambarSatuKotak(-0.150f, -0.50f, s); 
    gambarSatuKotak(-0.150f, -0.75f, s);
    
    // bilah
    gambarbilah( -0.150f, -0.25f, s);
    gambarbilah( -0.150f, 0.0f, s);
    gambarbilah( -0.150f, 0.25f, s);
    
    

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Kreasi min 5 Kotak");
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
