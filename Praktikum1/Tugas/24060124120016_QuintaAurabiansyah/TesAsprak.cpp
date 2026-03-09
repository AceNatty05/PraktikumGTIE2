// ============================================================
//  Nama : Quinta Aurabiansyah
//  NIM  : 24060124120016
//  Lab  : E2
//  Desc : Gambar Rumah, Pohon, Matahari dengan fungsi yang ada di modul
// ============================================================

#include <GL/glut.h>

void display() {
    // 1 GL_QUADS ? Tanah
    glColor3f(0.30f, 0.70f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.30f);
        glVertex2f(-1.0f, -0.30f);
    glEnd();

   // 2 GL_POINTS ? Matahari 
	glPointSize(40.0f);          
	glColor3f(1.0f, 1.0f, 0.0f); 
	
	glBegin(GL_POINTS);
	    glVertex2f(0.75f, 0.75f); // posisi matahari
	glEnd();

    // 3 GL_LINES ? sinar matahari
    glColor3f(1.0f, 0.80f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(0.75f,  0.93f); glVertex2f(0.75f,  1.00f); // atas
        glVertex2f(0.75f,  0.57f); glVertex2f(0.75f,  0.50f); // bawah
        glVertex2f(0.57f,  0.75f); glVertex2f(0.50f,  0.75f); // kiri
        glVertex2f(0.93f,  0.75f); glVertex2f(1.00f,  0.75f); // kanan
        glVertex2f(0.89f,  0.89f); glVertex2f(0.94f,  0.94f); // kanan atas
        glVertex2f(0.61f,  0.89f); glVertex2f(0.56f,  0.94f); // kiri atas
		glVertex2f(0.61f,  0.61f); glVertex2f(0.56f,  0.56f); // kiri bawah
        glVertex2f(0.89f,  0.61f); glVertex2f(0.94f,  0.56f); // kanan bawah
    glEnd();

    // 4 GL_TRIANGLE_STRIP ? Dinding rumah
    glColor3f(0.91f, 0.76f, 0.55f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.50f,  0.10f); // kiri atas
        glVertex2f( 0.20f,  0.10f); // kanan atas
        glVertex2f(-0.50f, -0.30f); // kiri bawah
        glVertex2f( 0.20f, -0.30f); // kanan bawah
    glEnd();

    // 5 GL_TRIANGLE_FAN ? Atap rumah 
    glColor3f(0.72f, 0.18f, 0.15f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.15f,  0.50f); // puncak atap
        glVertex2f(-0.55f,  0.10f); // kiri bawah atap
        glVertex2f( 0.25f,  0.10f); // kanan bawah atap
    glEnd();

    //6 GL_LINE_LOOP ? jendela rumah
    glColor3f(0.40f, 0.60f, 0.90f);
    glBegin(GL_QUADS); // isi jendela
        glVertex2f(-0.38f, -0.05f);
        glVertex2f(-0.15f, -0.05f);
        glVertex2f(-0.15f,  0.08f);
        glVertex2f(-0.38f,  0.08f);
    glEnd();
    glColor3f(0.20f, 0.20f, 0.40f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP); // bingkai jendela
        glVertex2f(-0.38f, -0.05f);
        glVertex2f(-0.15f, -0.05f);
        glVertex2f(-0.15f,  0.08f);
        glVertex2f(-0.38f,  0.08f);
    glEnd();

    //7 GL_QUADS ? Pintu rumah
    glColor3f(0.45f, 0.25f, 0.08f);
    glBegin(GL_QUADS);
        glVertex2f(-0.08f, -0.30f);
        glVertex2f( 0.10f, -0.30f);
        glVertex2f( 0.10f,  0.08f);
        glVertex2f(-0.08f,  0.08f);
    glEnd();

    // 8 GL_LINES ? Batang pohon
    glColor3f(0.40f, 0.22f, 0.08f);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glVertex2f(0.65f, -0.30f); // bawah
        glVertex2f(0.65f,  0.10f); // atas
    glEnd();

    // 9 GL_TRIANGLE_FAN ? Daun pohon
    glColor3f(0.10f, 0.60f, 0.15f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f( 0.65f,  0.55f); // puncak
        glVertex2f( 0.35f,  0.10f); // kiri bawah
        glVertex2f( 0.95f,  0.10f); // kanan bawah
    glEnd();

    // 10 GL_LINE_STRIP ? awan 
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.80f,  0.70f);
        glVertex2f(-0.70f,  0.80f);
        glVertex2f(-0.55f,  0.85f);
        glVertex2f(-0.40f,  0.80f);
        glVertex2f(-0.25f,  0.85f);
        glVertex2f(-0.10f,  0.80f);
        glVertex2f( 0.00f,  0.70f);
    glEnd();

    // 11 GL_POINTS ? burung kecil
    glColor3f(0.20f, 0.20f, 0.20f);
    glPointSize(4.0f);
    glBegin(GL_POINTS);
        glVertex2f(-0.60f,  0.60f);
        glVertex2f(-0.50f,  0.65f);
        glVertex2f(-0.30f,  0.55f);
    glEnd();

    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Gambar Rumah, Pohon, Matahari- Quinta Aurabiansyah");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

