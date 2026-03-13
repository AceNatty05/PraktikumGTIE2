#include <GL/glut.h>
#include <cmath>

float putarRoda = 0;

void roda() {
    float r = 0.12;

    // Ban
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++){
        float a = 2*3.1416*i/100;
        glVertex2f(r*cos(a), r*sin(a));
    }
    glEnd();

    // Velg
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++){
        float a = 2*3.1416*i/100;
        glVertex2f((r/2)*cos(a),(r/2)*sin(a));
    }
    glEnd();
}

void mobil() {

    // Badan mobil
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-0.4,-0.05);
        glVertex2f( 0.4,-0.05);
        glVertex2f( 0.4, 0.15);
        glVertex2f(-0.4, 0.15);
    glEnd();

    // Atap
    glColor3f(0.8,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-0.2,0.15);
        glVertex2f(0.2,0.15);
        glVertex2f(0.15,0.28);
        glVertex2f(-0.15,0.28);
    glEnd();

    // Kaca
    glColor3f(0.5,0.8,1);
    glBegin(GL_QUADS);
        glVertex2f(-0.15,0.17);
        glVertex2f(0.15,0.17);
        glVertex2f(0.10,0.25);
        glVertex2f(-0.10,0.25);
    glEnd();

    // Roda kiri
    glPushMatrix();
    glTranslatef(-0.25,-0.05,0);
    glRotatef(putarRoda,0,0,1);
    roda();
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
    glTranslatef(0.25,-0.05,0);
    glRotatef(putarRoda,0,0,1);
    roda();
    glPopMatrix();
}

void jalan() {

    // Jalan raya
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.5);
        glVertex2f(1,-0.5);
        glVertex2f(1,0.5);
        glVertex2f(-1,0.5);
    glEnd();

    // Garis tengah
    glColor3f(1,1,0);
    glLineWidth(5);

    for (float i = -1.0; i <= 1.0; i += 0.4) {
        glBegin(GL_LINES);
            glVertex2f(i,0);
            glVertex2f(i + 0.2, 0);
        glEnd();
    }
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    jalan();

    // Mobil 1 (lajur atas kiri)
    glPushMatrix();
    glTranslatef(-0.60,0.22,0);
    mobil();
    glPopMatrix();

    // Mobil 2 (lajur atas kanan)
    glPushMatrix();
    glTranslatef(0.55,0.22,0);
    mobil();
    glPopMatrix();

    // Mobil 3 (lajur bawah arah kiri)
    glPushMatrix();
    glTranslatef(0.1,-0.2,0);
    glScalef(-1,1,1);
    mobil();
    glPopMatrix();

    glFlush();
}

void idle(){
    putarRoda += 2;
    glutPostRedisplay();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutCreateWindow("Tugas 2 - Mobil");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
}
