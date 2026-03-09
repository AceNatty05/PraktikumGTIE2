// ============================================================
//  Nama : Quinta Aurabiansyah
//  NIM  : 24060124120016
//  Lab  : E2
//  Desc : Gambar jaring laba-laba/snowflake
// ============================================================
#include <GL/glut.h>

void jaring() {

    glColor3f(1.0,1.0,1.0);

    // 8 garis pusat
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(45,0,0,1);
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(90,0,0,1);
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(135,0,0,1);
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(180,0,0,1);
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(225,0,0,1);
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(270,0,0,1);
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(315,0,0,1);
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(0.35,0);
        glEnd();
    glPopMatrix();


    // lingkaran pertama
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.15,0);
        glVertex2f(0.10,0.10);
        glVertex2f(0,0.15);
        glVertex2f(-0.10,0.10);
        glVertex2f(-0.15,0);
        glVertex2f(-0.10,-0.10);
        glVertex2f(0,-0.15);
        glVertex2f(0.10,-0.10);
    glEnd();

    // lingkaran kedua
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.25,0);
        glVertex2f(0.18,0.18);
        glVertex2f(0,0.25);
        glVertex2f(-0.18,0.18);
        glVertex2f(-0.25,0);
        glVertex2f(-0.18,-0.18);
        glVertex2f(0,-0.25);
        glVertex2f(0.18,-0.18);
    glEnd();

    // lingkaran ke3
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.35,0);
        glVertex2f(0.25,0.25);
        glVertex2f(0,0.35);
        glVertex2f(-0.25,0.25);
        glVertex2f(-0.35,0);
        glVertex2f(-0.25,-0.25);
        glVertex2f(0,-0.35);
        glVertex2f(0.25,-0.25);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    jaring();
    glFlush();
}

void init() {
    glClearColor(0.1,0.1,0.4,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Jaring Laba-laba snowflake");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
