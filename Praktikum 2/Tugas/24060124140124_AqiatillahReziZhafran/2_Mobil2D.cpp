/*Nama	: Aqiatillah Rezi Zhafran
  NIM	: 24060124140124
  LAB	: E2*/
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846

void gambarLingkaranIsi(float jariJari, int jumlahSegmen) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < jumlahSegmen; i++) {
        float sudut = 2.0f * PI * i / jumlahSegmen;
        glVertex2f(jariJari * cos(sudut), jariJari * sin(sudut));
    }
    glEnd();
}

void gambarRoda() {
    // Ban luar
    glColor3f(0.1f, 0.1f, 0.1f);
    gambarLingkaranIsi(0.2f, 50);
    // Velg 
    glColor3f(0.8f, 0.8f, 0.8f);
    gambarLingkaranIsi(0.08f, 50);
    // jari-jari putih
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f); 
    glBegin(GL_LINES);
        glVertex2f(-0.15f, 0.0f); glVertex2f(0.15f, 0.0f);
        glVertex2f(0.0f, -0.15f); glVertex2f(0.0f, 0.15f);
        glVertex2f(-0.11f, -0.11f); glVertex2f(0.11f, 0.11f);
        glVertex2f(-0.11f, 0.11f); glVertex2f(0.11f, -0.11f);
    glEnd();
}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT); 
    //Rangka Mobil
    glPushMatrix(); 
        glColor3f(0.23f, 0.70f, 1.0f); 
        // Bak 
        glRectf(-0.8f, -0.2f, 0.2f, 0.2f); 
        // Bagian Depan 
        glBegin(GL_POLYGON);
            glVertex2f(0.2f, -0.2f);
            glVertex2f(0.8f, -0.2f);
            glVertex2f(0.8f, 0.3f);
            glVertex2f(0.5f, 0.8f);
            glVertex2f(0.2f, 0.8f);
        glEnd();
        // Kaca samping
        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_POLYGON);
            glVertex2f(0.25f, 0.35f);
            glVertex2f(0.65f, 0.35f);
            glVertex2f(0.45f, 0.7f);
            glVertex2f(0.25f, 0.7f);
        glEnd();
        
        glColor3f(0.6f, 0.6f, 0.6f);
        glRectf(-0.8f, 0.2f, 0.2f, 0.23f);
    glPopMatrix(); 

    //lampu depan dan belakang
    glPushMatrix();
        // Belakang
        glColor3f(1.0f, 1.0f, 0.0f);
		glRectf(-0.8f, 0.12f, -0.73f, 0.18f);
        glColor3f(1.0f, 0.0f, 0.0f); 
		glRectf(-0.8f, 0.04f, -0.73f, 0.12f);
        glColor3f(1.0f, 1.0f, 1.0f);
		glRectf(-0.8f, -0.04f, -0.73f, 0.04f);

        // Depan
        glColor3f(1.0f, 1.0f, 0.0f); 
		glRectf(0.73f, 0.15f, 0.8f, 0.25f);
        glColor3f(1.0f, 0.7f, 0.3f); 
		glRectf(0.73f, 0.05f, 0.8f, 0.15f);
        glColor3f(1.0f, 1.0f, 1.0f); 
		glRectf(0.73f, -0.05f, 0.8f, 0.05f);
    glPopMatrix();

    // Roda belakang
    glPushMatrix();
        glTranslatef(-0.45f, -0.2f, 0.0f); 
        glRotated(20.0, 0.0, 0.0, 1.0); 
        gambarRoda();
    glPopMatrix();
    
	//Roda belakang
    glPushMatrix();
        glTranslatef(0.45f, -0.2f, 0.0f); 
        glRotated(20.0, 0.0, 0.0, 1.0); 
        gambarRoda();
    glPopMatrix();
    glFlush(); 
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); 
    glutInitWindowSize(800, 400); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutCreateWindow("Mobil Pickup 2D"); 
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glutDisplayFunc(RenderScene); 
    glutMainLoop(); 
    return 0;
}
