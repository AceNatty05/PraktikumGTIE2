// Nama : Nadia Azura Nurhaniya
// NIM : 24060124120019
// Deskripsi : Membuat mobil dengan memanfaatkan rotasi dan translasi

#include <GL/glut.h>
#include <cmath>

float posisiMobil = -1.2;

void drawCircle(float x, float y, float radius, float r, float g, float b){
    int num_segments = 100;
    glColor3f(r,g,b);

    glBegin(GL_POLYGON);
    for(int i=0;i<num_segments;i++){
        float theta = 2.0f * 3.1415926f * i / num_segments;
        float dx = radius * cos(theta);
        float dy = radius * sin(theta);
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}

void drawWheel(float x, float y, float radius){

    drawCircle(x,y,radius,0.1,0.1,0.1);
    drawCircle(x,y,radius*0.6,0.8,0.8,0.8);
    drawCircle(x,y,radius*0.2,0.5,0.5,0.5);

    glColor3f(0.9,0.7,0.7);
    glLineWidth(2);

    glBegin(GL_LINES);
    for(int i=0;i<6;i++){
        float angle = 2 * 3.1415926 * i / 6;
        float dx = radius*0.6*cos(angle);
        float dy = radius*0.6*sin(angle);

        glVertex2f(x,y);
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}

void drawBuildings(){

    // GEDUNG 1
    glColor3f(0.9,0.3,0.2); 
    glBegin(GL_QUADS);
    glVertex2f(-0.9,-0.3);
    glVertex2f(-0.7,-0.3);
    glVertex2f(-0.7,0.2);
    glVertex2f(-0.9,0.2);
    glEnd();

    // JENDELA
    glColor3f(1,1,0.6);
    glBegin(GL_QUADS);
    glVertex2f(-0.88,0.15);
    glVertex2f(-0.82,0.15);
    glVertex2f(-0.82,0.1);
    glVertex2f(-0.88,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.78,0.15);
    glVertex2f(-0.72,0.15);
    glVertex2f(-0.72,0.1);
    glVertex2f(-0.78,0.1);
    glEnd();


    // GEDUNG 2
    glColor3f(0.9,0.8,0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-0.35,-0.3);
    glVertex2f(-0.35,0.35);
    glVertex2f(-0.6,0.35);
    glEnd();

    // JENDELA 
    glColor3f(1,1,0.6);
    glBegin(GL_QUADS);
    glVertex2f(-0.55,0.25);
    glVertex2f(-0.48,0.25);
    glVertex2f(-0.48,0.18);
    glVertex2f(-0.55,0.18);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.45,0.25);
    glVertex2f(-0.38,0.25);
    glVertex2f(-0.38,0.18);
    glVertex2f(-0.45,0.18);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.55,0.1);
    glVertex2f(-0.48,0.1);
    glVertex2f(-0.48,0.03);
    glVertex2f(-0.55,0.03);
    glEnd();

    // GEDUNG 3
    glColor3f(0.2,0.78,0.85);
    glBegin(GL_QUADS);
    glVertex2f(0.4,-0.3);
    glVertex2f(0.65,-0.3);
    glVertex2f(0.65,0.25);
    glVertex2f(0.4,0.25);
    glEnd();

    // JENDELA 
    glColor3f(1,1,0.6);
    glBegin(GL_QUADS);
    glVertex2f(0.45,0.18);
    glVertex2f(0.52,0.18);
    glVertex2f(0.52,0.1);
    glVertex2f(0.45,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.55,0.18);
    glVertex2f(0.62,0.18);
    glVertex2f(0.62,0.1);
    glVertex2f(0.55,0.1);
    glEnd();

}
void drawBackground(){

    // LANGIT
    glColor3f(0.02,0.05,0.30);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.3);
    glVertex2f(1,-0.3);
    glVertex2f(1,1);
    glVertex2f(-1,1);
    glEnd();

    // BULAN
    drawCircle(0.7,0.75,0.08,1,1,0.8);

    // BINTANG
    glPointSize(3);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2f(-0.9,0.9);
    glVertex2f(-0.8,0.8);
    glVertex2f(-0.7,0.95);
    glVertex2f(-0.6,0.85);
    glVertex2f(-0.5,0.7);
    glVertex2f(-0.4,0.9);
    glVertex2f(-0.3,0.8);
    glVertex2f(-0.2,0.95);
    glVertex2f(-0.1,0.75);
    glVertex2f(0.0,0.9);
    glVertex2f(0.1,0.8);
    glVertex2f(0.2,0.95);
    glVertex2f(0.3,0.7);
    glVertex2f(0.4,0.9);
    glVertex2f(0.5,0.85);
    glVertex2f(0.6,0.95);
    glVertex2f(0.7,0.8);
    glVertex2f(0.8,0.9);
    glVertex2f(0.9,0.75);
    glEnd();

    // GEDUNG
    drawBuildings();

    // JALAN
    glColor3f(0.15,0.15,0.15);
    glBegin(GL_QUADS);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.3);
    glVertex2f(-1,-0.3);
    glEnd();

    // GARIS JALAN
    glColor3f(1,1,1);
    glLineWidth(4);

    glBegin(GL_LINES);
    for(float i=-0.9;i<1;i+=0.4){
        glVertex2f(i,-0.65);
        glVertex2f(i+0.2,-0.65);
    }
    glEnd();
}

void drawCar(){

    // BODY
    glBegin(GL_QUADS);
    glColor3f(0.9,0.9,0.9);
    glVertex2f(-0.6,-0.1);
    glVertex2f(0.6,-0.1);

    glColor3f(0.7,0.8,0.9);
    glVertex2f(0.6,0.1);
    glVertex2f(-0.6,0.1);
    glEnd();

    // ATAP
    glBegin(GL_QUADS);
    glColor3f(0.95,0.95,0.95);
    glVertex2f(-0.35,0.1);
    glVertex2f(0.25,0.1);
    glVertex2f(0.2,0.3);
    glVertex2f(-0.25,0.3);
    glEnd();

    // KACA DEPAN
    glColor3f(0.8,0.9,1);
    glBegin(GL_QUADS);
    glVertex2f(0.25,0.1);
    glVertex2f(0.2,0.3);
    glVertex2f(0.05,0.3);
    glVertex2f(0.05,0.1);
    glEnd();

    // KACA BELAKANG
    glBegin(GL_QUADS);
    glVertex2f(-0.05,0.1);
    glVertex2f(-0.05,0.3);
    glVertex2f(-0.25,0.3);
    glVertex2f(-0.35,0.1);
    glEnd();

    // LAMPU
    drawCircle(0.55,0.02,0.03,1,1,0.6);
    drawCircle(-0.55,0.02,0.03,1,0.2,0.2);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();
    glPushMatrix();
    glTranslatef(posisiMobil,-0.6,0);
    drawCar();
    glPushMatrix();
    glTranslatef(-0.4,-0.1,0);
    drawWheel(0,0,0.08);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.4,-0.1,0);
    drawWheel(0,0,0.08);
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void update(int value){
    posisiMobil += 0.01;
    if(posisiMobil > 1.3)
        posisiMobil = -1.3;
    glutPostRedisplay();
    glutTimerFunc(16,update,0);
}

void init(){
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Translasi dan Rotasi dalam Mobil");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,update,0);
    glutMainLoop();
    return 0;
}
