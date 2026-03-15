// Nama	: Farhan Dwiyan Akbar
// NIM	: 24060124140137

#include <GL/glut.h>
#include <math.h>

void lingkaran(float r){
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++){
        float angle = 2 * 3.1416 * i / 100;
        glVertex2f(cos(angle)*r, sin(angle)*r);
    }
    glEnd();
}

void jalan(){

    glColor3f(0.2,0.2,0.2);

    glBegin(GL_QUADS);
    glVertex2f(-2,-0.3);
    glVertex2f(2,-0.3);
    glVertex2f(2,-1);
    glVertex2f(-2,-1);
    glEnd();

    glColor3f(1,1,1);

    for(float i=-2;i<2;i+=0.5){

        glBegin(GL_QUADS);
        glVertex2f(i,-0.65);
        glVertex2f(i+0.25,-0.65);
        glVertex2f(i+0.25,-0.7);
        glVertex2f(i,-0.7);
        glEnd();
    }
}

void awan(float x,float y){

    glPushMatrix();
    glTranslatef(x,y,0);

    glColor3f(1,1,1);

    lingkaran(0.1);

    glPushMatrix();
    glTranslatef(0.1,0.02,0);
    lingkaran(0.09);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1,0.02,0);
    lingkaran(0.09);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05,0.07,0);
    lingkaran(0.08);
    glPopMatrix();

    glPopMatrix();
}

void pohon(float x,float y){

    glPushMatrix();
    glTranslatef(x,y,0);

    // batang
    glColor3f(0.55,0.27,0.07);

    glBegin(GL_QUADS);
    glVertex2f(-0.04,-0.3);
    glVertex2f(0.04,-0.3);
    glVertex2f(0.04,0.1);
    glVertex2f(-0.04,0.1);
    glEnd();

    // daun
    glColor3f(0,0.6,0);

    glPushMatrix();
    glTranslatef(0,0.15,0);
    lingkaran(0.12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.08,0.12,0);
    lingkaran(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.08,0.12,0);
    lingkaran(0.1);
    glPopMatrix();

    glPopMatrix();
}

void matahari(){

    glPushMatrix();
    glTranslatef(1.4,0.8,0);

    glColor3f(1,0.9,0);

    lingkaran(0.12);

    glPopMatrix();
}

void mobil(){

    glPushMatrix();
    glTranslatef(0,-0.3,0);

    // body mobil
    glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glVertex2f(-0.4,0);
    glVertex2f(0.4,0);
    glVertex2f(0.4,0.15);
    glVertex2f(-0.4,0.15);
    glEnd();

    // atap mobil
    glBegin(GL_POLYGON);
    glVertex2f(-0.2,0.15);
    glVertex2f(0.2,0.15);
    glVertex2f(0.1,0.3);
    glVertex2f(-0.1,0.3);
    glEnd();

    // kaca mobil
    glColor3f(0.6,0.8,1);

    glBegin(GL_QUADS);
    glVertex2f(-0.17,0.18);
    glVertex2f(-0.02,0.18);
    glVertex2f(-0.02,0.28);
    glVertex2f(-0.17,0.28);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.02,0.18);
    glVertex2f(0.17,0.18);
    glVertex2f(0.17,0.28);
    glVertex2f(0.02,0.28);
    glEnd();

    // bumper
    glColor3f(0.3,0.3,0.3);

    glBegin(GL_QUADS);
    glVertex2f(-0.42,0.02);
    glVertex2f(-0.4,0.02);
    glVertex2f(-0.4,0.08);
    glVertex2f(-0.42,0.08);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.4,0.02);
    glVertex2f(0.42,0.02);
    glVertex2f(0.42,0.08);
    glVertex2f(0.4,0.08);
    glEnd();

    // roda kiri
    glPushMatrix();
    glTranslatef(-0.25,-0.02,0);

    glColor3f(0,0,0);
    lingkaran(0.1);

    glColor3f(0.7,0.7,0.7);
    lingkaran(0.05);

    glPopMatrix();

    // roda kanan
    glPushMatrix();
    glTranslatef(0.25,-0.02,0);

    glColor3f(0,0,0);
    lingkaran(0.1);

    glColor3f(0.7,0.7,0.7);
    lingkaran(0.05);

    glPopMatrix();

    glPopMatrix();
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    // langit
    glColor3f(0.53,0.81,0.98);

    glBegin(GL_QUADS);
    glVertex2f(-2,1);
    glVertex2f(2,1);
    glVertex2f(2,-0.3);
    glVertex2f(-2,-0.3);
    glEnd();

    matahari();

    awan(-0.7,0.7);
    awan(0.5,0.6);
    awan(-0.2,0.4);
    awan(1.0,0.4);
    awan(-1.3,0.4);

    pohon(-1.5,-0.2);
    pohon(-1,-0.2);
    pohon(1,-0.2);
    pohon(1.5,-0.2);

    jalan();
	
	glPushMatrix();
    glTranslatef(-1.0,-0.2,0);
		mobil();
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(1.0,-0.5,0);
		mobil();
	glPopMatrix();
	

    glFlush();
}

void init(){

    glClearColor(0.53,0.81,0.98,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2,2,-1,1);
}

int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,600);
    glutCreateWindow("Mobil");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
