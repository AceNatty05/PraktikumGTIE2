/*Nama : Quinta Aurabiansyah 
  NIM : 24060124120016*/

#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265358979323846


float carX      = -500.0f;   
float wheelRot  = 0.0f;      
float cloudX    = 200.0f;   


void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

// Lingkaran(outline)
void drawCircleOutline(float cx, float cy, float r, int segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

void drawRect(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
    glVertex2f(x,     y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x,     y + h);
    glEnd();
}

void drawTriangle(float x1,float y1, float x2,float y2, float x3,float y3){
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// roda
void drawWheel(float radius) {
    // ban
    glColor3f(0.15f, 0.15f, 0.15f);
    drawCircle(0, 0, radius, 40);

    // pelek
    glColor3f(0.75f, 0.75f, 0.75f);
    drawCircle(0, 0, radius * 0.75f, 40);

    // jari roda
    glColor3f(0.55f, 0.55f, 0.55f);
    glLineWidth(3.0f);
    for (int i = 0; i < 4; i++) {
        float a = PI / 4.0f + i * (PI / 2.0f);   
        glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f((radius * 0.7f) * cos(a), (radius * 0.7f) * sin(a));
        glEnd();
    }

    // Hub tengah
    glColor3f(0.3f, 0.3f, 0.3f);
    drawCircle(0, 0, radius * 0.18f, 20);

    // ban
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    drawCircleOutline(0, 0, radius, 40);
}

//mobil
void drawCar() {
    float bodyW  = 220.0f;
    float bodyH  =  60.0f;
    float roofW  = 140.0f;
    float roofH  =  55.0f;
    float wheelR =  32.0f;

    // stack 1 : body 
    glPushMatrix();

        // bodi bawah 
        glColor3f(0.85f, 0.15f, 0.15f);   
        drawRect(-bodyW/2, 0, bodyW, bodyH);

        // kap mesin 
        glColor3f(0.75f, 0.12f, 0.12f);
        glBegin(GL_QUADS);
            glVertex2f(bodyW/2 - 50, bodyH);
            glVertex2f(bodyW/2,      bodyH);
            glVertex2f(bodyW/2,      bodyH + 18);
            glVertex2f(bodyW/2 - 60, bodyH + 18);
        glEnd();

        // stack2 : atap
        glPushMatrix();
        glTranslatef(-roofW/2 + 20, bodyH, 0);   

            // atap
            glColor3f(0.80f, 0.12f, 0.12f);
            drawRect(0, 0, roofW, roofH);

            // jendela depan
            glColor3f(0.6f, 0.85f, 1.0f);
            glBegin(GL_QUADS);
                glVertex2f(roofW - 45, 5);
                glVertex2f(roofW - 5,  5);
                glVertex2f(roofW - 5,  roofH - 5);
                glVertex2f(roofW - 50, roofH - 5);
            glEnd();

            // kaca belakang
            glColor3f(0.6f, 0.85f, 1.0f);
            glBegin(GL_QUADS);
                glVertex2f(5,  5);
                glVertex2f(50, 5);
                glVertex2f(45, roofH - 5);
                glVertex2f(5,  roofH - 5);
            glEnd();

            //outline atap 
            glColor3f(0.5f, 0.08f, 0.08f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
                glVertex2f(0,     0);
                glVertex2f(roofW, 0);
                glVertex2f(roofW, roofH);
                glVertex2f(0,     roofH);
            glEnd();

        glPopMatrix();

        //lampu depan
        glPushMatrix();
        glTranslatef(bodyW/2, 15, 0);
            // Llingkaran kuning buat lampu
            glColor3f(1.0f, 0.95f, 0.4f);
            drawCircle(0, 0, 13, 30);
        glPopMatrix();

        //lampu belakang
        glPushMatrix();
        glTranslatef(-bodyW/2, 15, 0);
            glColor3f(1.0f, 0.2f, 0.2f);
            drawCircle(0, 0, 10, 30);
        glPopMatrix();

        //pintu
        glColor3f(0.65f, 0.10f, 0.10f);
        glLineWidth(1.5f);
        glBegin(GL_LINES);
            glVertex2f(10,  2);  glVertex2f(10,  bodyH - 2);  
            glVertex2f(-40, 2);  glVertex2f(-40, bodyH - 2);
        glEnd();

        //ggang pintu 
        glColor3f(0.9f, 0.9f, 0.9f);
        drawRect(20, bodyH/2 - 4, 20, 8);
        drawRect(-55, bodyH/2 - 4, 20, 8);

        //roda depan
        glPushMatrix();
        glTranslatef(70, 0, 0);            
            drawWheel(wheelR);
        glPopMatrix();

        // roda belkang
        glPushMatrix();
        glTranslatef(-70, 0, 0);          // posisi roda belakang
                    drawWheel(wheelR);
        glPopMatrix();

        //outline bodi utama
        glColor3f(0.5f, 0.08f, 0.08f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(-bodyW/2, 0);
            glVertex2f( bodyW/2, 0);
            glVertex2f( bodyW/2, bodyH);
            glVertex2f(-bodyW/2, bodyH);
        glEnd();

    glPopMatrix();
}

//pohon
void drawTree(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

        //Batang
        glColor3f(0.45f, 0.28f, 0.10f);
        drawRect(-8, 0, 16, 50);

        //Daun 
        glColor3f(0.15f, 0.65f, 0.20f);
        drawTriangle(-35, 40,  35, 40,  0, 90);

        glColor3f(0.10f, 0.75f, 0.25f);
        drawTriangle(-28, 60,  28, 60,  0, 105);

        glColor3f(0.05f, 0.80f, 0.20f);
        drawTriangle(-20, 78,  20, 78,  0, 118);

    glPopMatrix();
}

// awan
void drawCloud(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(0,   0,  28, 30);
        drawCircle(30,  8,  22, 30);
        drawCircle(-30, 5,  20, 30);
        drawCircle(15, -5,  20, 30);
        drawCircle(-15,-5,  20, 30);
    glPopMatrix();
}

// background
void drawBackground() {
    //langit
    glColor3f(0.53f, 0.81f, 0.98f);
    drawRect(-600, -50, 1200, 450);

    //matahari
    glPushMatrix();
    glTranslatef(480, 320, 0);
        glColor3f(1.0f, 0.9f, 0.0f);
        drawCircle(0, 0, 45, 40);
        //sinar matahari
        glColor3f(1.0f, 0.85f, 0.0f);
        glLineWidth(2.5f);
        for (int i = 0; i < 8; i++) {
            float a = i * PI / 4.0f;
            glBegin(GL_LINES);
            glVertex2f(50 * cos(a), 50 * sin(a));
            glVertex2f(65 * cos(a), 65 * sin(a));
            glEnd();
        }
    glPopMatrix();

    //gerak awan
    drawCloud(cloudX, 280);
    drawCloud(cloudX - 250, 310);
    drawCloud(cloudX + 150, 260);

    // tanah rumput
    glColor3f(0.30f, 0.65f, 0.25f);
    drawRect(-600, -50, 1200, 70);

    // jalan
    glColor3f(0.35f, 0.35f, 0.35f);
    drawRect(-600, -50, 1200, 50);

    //marka jalan
    glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = -6; i <= 6; i++) {
        float mx = i * 100.0f;
        drawRect(mx - 30, -28, 60, 6);
    }

    //pohon-pohon
    drawTree(-420, 20);
    drawTree(-200, 20);
    drawTree(50,   20);
    drawTree(300,  20);
    drawTree(520,  20);

    //pembatas jalan 
    glColor3f(0.7f, 0.7f, 0.7f);
    for (int i = -5; i <= 5; i++) {
        float px = i * 110.0f + 30;
        drawRect(px - 3, 20, 6, 30);
        // penghubung horizontal
        glColor3f(0.6f, 0.6f, 0.6f);
        drawRect(px - 3, 43, 116, 5);
        glColor3f(0.7f, 0.7f, 0.7f);
    }
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawBackground();

  
    glPushMatrix();
        //translasi mobil sesuai posisi animasi
        glTranslatef(carX, 0, 0);
        // gambar mobil di atas jalan 
        glTranslatef(0, 18, 0);
        drawCar();
    glPopMatrix();

    glutSwapBuffers();
}


void timer(int value) {
    //gerakkan mobil ke kanan
    carX += 2.5f;
    //gerakkan awan ke kiri 
    cloudX -= 0.4f;
    if (cloudX < -700) cloudX = 700;
    //reset mobil 
    if (carX > 700) carX = -600;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);   
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Koordinat world
    gluOrtho2D(-600, 600, -50, 400);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



//  MAIN
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Translasi & Rotasi Mobil 2D");

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
