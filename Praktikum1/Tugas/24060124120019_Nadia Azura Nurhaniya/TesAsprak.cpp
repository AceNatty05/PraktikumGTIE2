// Nama : Nadia Azura Nurhaniya
// NIM  : 24060124120019
// Deskripsi : Membuat elemen Bintang dengan memanfaatkan GL_LINE_LOOP

#include <GL/glut.h>

void Bintang() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 0.0f); 

    glVertex2f(0.0f, 0.5f);    
    glVertex2f(0.15f, 0.15f);
    glVertex2f(0.5f, 0.15f);   
    glVertex2f(0.25f, -0.1f);
    glVertex2f(0.35f, -0.45f); 
    glVertex2f(0.0f, -0.2f);   
    glVertex2f(-0.35f, -0.45f);
    glVertex2f(-0.25f, -0.1f);
    glVertex2f(-0.5f, 0.15f);  
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glFlush();
}

void Sparkle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); 

    // garis vertikal
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.0f, -0.4f);

    // garis horizontal
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.4f, 0.0f);

    // garis diagonal 1
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(0.3f, -0.3f);

    // garis diagonal 2
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, 0.3f);
    glEnd();
    glFlush();
}

void Gunung() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.2f, 0.8f, 0.2f); 

    glVertex2f(-0.9f, -0.3f); 
    glVertex2f(-0.6f, 0.2f);  
    glVertex2f(-0.3f, -0.3f); 
    glVertex2f(0.0f, 0.3f);   
    glVertex2f(0.3f, -0.3f);  
    glVertex2f(0.6f, 0.2f);   
    glVertex2f(0.9f, -0.3f);  
    glEnd();
    glFlush();
}

void SmileFace() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0f);
    glBegin(GL_POINTS);

    glColor3f(1.0f, 1.0f, 0.0f);

	// lingkaran untuk kepalanya
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.2f, 0.35f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.3f, 0.0f);

	// mata
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.12f, 0.1f);
    glVertex2f(0.12f, 0.1f);

	// mulutnya
    glVertex2f(-0.15f, -0.05f);
    glVertex2f(-0.05f, -0.12f);
    glVertex2f(0.05f, -0.12f);
    glVertex2f(0.15f, -0.05f);
    glEnd();
    glFlush();
}

void jendela() {
    glClear(GL_COLOR_BUFFER_BIT);
    // frame jendela 
    glColor3f(0.4f, 0.2f, 0.1f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.6f);
        glVertex2f(0.6f, 0.6f);
        glVertex2f(0.6f, -0.6f);
        glVertex2f(-0.6f, -0.6f);
    glEnd();

    // kaca kiri atas
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(-0.05f, 0.5f);
        glVertex2f(-0.05f, 0.05f);
        glVertex2f(-0.5f, 0.05f);
    glEnd();
    // kaca kiri bawah
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.05f);
        glVertex2f(-0.05f, -0.05f);
        glVertex2f(-0.05f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
    glEnd();

    // kaca kanan atas
    glBegin(GL_QUADS);
        glVertex2f(0.05f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, 0.05f);
        glVertex2f(0.05f, 0.05f);
    glEnd();
    // kaca kanan bawah
    glBegin(GL_QUADS);
        glVertex2f(0.05f, -0.05f);
        glVertex2f(0.5f, -0.05f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.05f, -0.5f);
    glEnd();
    glFlush();
}

void Gelombang() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.6f, 1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.8f, 0.3f); 
    glVertex2f(-0.8f, -0.3f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.8f, -0.3f);
    glEnd();
    glFlush();
}

void Diamond() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(-0.6f, 0.3f);
    glVertex2f(-0.4f, 0.5f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(-0.6f, 0.3f);
    glEnd();
    glFlush();
}

void TriangleStrip() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1f, 0.2f, 0.3f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.6f, 0.3f);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Bintang - GL_LINE_LOOP");
    glutDisplayFunc(TriangleStrip);
    glClearColor(0.3f, 0.3f, 0.9f, 0.0f);
    glutMainLoop();
}


