/* Nama File : Mobil.cpp
 * Deskripsi : Mengenerate gambar mobil dengan memanfaatkan teori lingkaran matematika dan fungsi glut lainnya
 * Pembuat   : Rafif Setya Imaduddin (24060124130115)
 * Tanggal   : 15 Maret 2026
 */

#include <gl/glut.h>
#include <gl/freeglut.h>
#include <gl/gl.h>
#include <math.h>
#include <string>

// Kamus Global
const float Pi = 3.14159265f;
const float wheelR = 0.15f;
const float Speed = 0.005f;
const float groundY = -0.35f;
float CarX;
float CarY;
float wheelAngle;

void drawText(const char* text, float x, float y) {
    // Kamus Lokal
    int i;

    // Algoritma
    glColor3f(0.0f, 0.0f, 0.5f);
    glRasterPos2f(x, y);

    for (i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void drawCircleOutline(float Radius) {
	// Kamus Lokal
	int Segments;
	int i;
	float Angle;
	
	// Algoritma
	//= Polygon Ban
	Segments = 60;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < Segments; i++) {
   	   Angle = 2.0f * Pi * i / Segments;
   	   glVertex2f(Radius * cos(Angle), Radius * sin(Angle));
    }
    glEnd();
}

void drawWheel() {
	// Kamus Lokal
    int Bars; 
    int i;
    float Angle;

	// Algoritma
	Bars = 12;
	
	//= Outer Ban
    glLineWidth(7.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircleOutline(wheelR);

	//= Bars
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    for (i = 0; i < Bars; i++) {
        Angle = 2.0f * Pi * i / Bars;
        glVertex2f(0, wheelR * 0.2f * sin(Angle));
        glVertex2f(wheelR * 0.98f * cos(Angle), wheelR * 0.98f * sin(Angle));
    }
    glEnd();
}

void drawCarFrame() {
    // Kamus Lokal
    float rearX = -0.22f;
    float rearY = 0.0f; 
    float frontX = 0.22f;
    float frontY = 0.0f;   
    float bbX = -0.05f;
    float bbY = 0.0f;
    float seatX = -0.10f;
    float seatY = 0.22f;
    float headX = 0.18f;
    float headY = 0.22f;

    // Algoritma
    rearX = -0.22f;
    rearY = 0.0f; 
    frontX = 0.22f;
    frontY = 0.0f;   
    bbX = -0.05f;
    bbY = 0.0f;
    seatX = -0.10f;
    seatY = 0.22f;
    headX = 0.18f;
    headY = 0.22f;
    glLineWidth(3.5f);

	//= Body
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.7f, 0.2f, 0.7f, 0.4f);
    glRectf(-0.17f, 0.2f, 0.17f, 0.0f);

    glColor3f(1.0f, 0.7f, 0.4f);
    glRectf(-0.7f, 0.2f, -0.6f, 0.4f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(0.7f, 0.2f, 0.65f, 0.3f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.37f, 0.2f);
        glVertex2f(0.17f, 0.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.17f, 0.2f);
        glVertex2f(-0.37f, 0.2f);
        glVertex2f(-0.17f, 0.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(0.7f, 0.2f);
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.7f, 0.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, 0.2f);
        glVertex2f(-0.5f, 0.2f);
        glVertex2f(-0.7f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, 0.2f);
        glVertex2f( 0.7f, 0.2f); 
        glVertex2f( 0.4f,  0.4f); 
        glVertex2f(-0.4f,  0.4f); 
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-0.35f, 0.4f);
        glVertex2f( 0.7f, 0.4f); 
        glVertex2f( 0.4f,  0.5f); 
        glVertex2f(-0.2f,  0.5f); 
    glEnd();
}

void drawGround() {
    // Kamus Lokal

    // Algoritma
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //= Garis tanah
    glLineWidth(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, groundY - 0.005f);
        glVertex2f(1.0f, groundY - 0.005f);
    glEnd();
}

void Display() {
	// Kamus Lokal
	
	// Algoritma
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawGround();

    glPushMatrix();
    	//= Translasi seluruh mobil
        glTranslatef(CarX, CarY, 0);

		//= Frame mobil
        glPushMatrix();
            glPushMatrix();
                glColor3f(1.0f, 1.0f, 1.0f);
                glLineWidth(2.0f);
            glPopMatrix();
            drawCarFrame();
            drawText("MBG Sawit", -0.2f, 0.2f);
        glPopMatrix();

		//= Roda belakang
        glPushMatrix();
            glTranslatef(-0.44f, 0.0f, 0);
            glRotatef(wheelAngle, 0, 0, 1);  
            drawWheel();
        glPopMatrix();

		//= Roda depan
        glPushMatrix();
            glTranslatef(0.44f, 0.0f, 0);
            glRotatef(wheelAngle, 0, 0, 1); 
            drawWheel();
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void Update(int Value) {
    // Kamus Lokal

    // Algoritma
    CarX += Speed;
    wheelAngle -= (Speed / wheelR) * (180.0f / Pi);  
    if (CarX > 1.7f) {
        CarX = -1.7f;	
    }

    glutPostRedisplay();
    glutTimerFunc(16, Update, 0);
}

int main(int argc, char** argv) {
	// Kamus
	
	// Algoritma
	CarX = -1.7f;
	CarY = groundY + wheelR;  
	wheelAngle = 0.0f;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Mobil Sawit MBG");
    glutDisplayFunc(Display);
    glutTimerFunc(16, Update, 0);
    glutMainLoop();
    return 0;
}
