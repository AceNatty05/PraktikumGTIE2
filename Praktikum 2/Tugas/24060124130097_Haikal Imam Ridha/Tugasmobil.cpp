#include <GL/glut.h>
#include <math.h>

float mobilX    = -0.9f;   // posisi X mobil
float rodaAngle = 0.0f;    // sudut rotasi roda
float awanX1    =  0.4f;  
float awanX2    = -0.3f;  

//lingkaran
void drawCircle(float cx, float cy, float r, int seg)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= seg; i++) {
            float a = 2.0f * 3.14159f * i / seg;
            glVertex2f(cx + r * cos(a), cy + r * sin(a));
        }
    glEnd();
}

// Jalan
void drawJalan()
{
    //aspal
    glColor3f(0.25f, 0.25f, 0.25f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.65f);
        glVertex2f( 1.0f, -0.65f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    //marka
    glColor3f(1.0f, 1.0f, 1.0f);
    float startX = -1.0f;
    for (int i = 0; i < 10; i++) {
        glBegin(GL_QUADS);
            glVertex2f(startX + i*0.20f,        -0.77f);
            glVertex2f(startX + i*0.20f + 0.10f,-0.77f);
            glVertex2f(startX + i*0.20f + 0.10f,-0.80f);
            glVertex2f(startX + i*0.20f,        -0.80f);
        glEnd();
    }

    //trotoar
    glColor3f(0.70f, 0.68f, 0.65f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.60f);
        glVertex2f( 1.0f, -0.60f);
        glVertex2f( 1.0f, -0.65f);
        glVertex2f(-1.0f, -0.65f);
    glEnd();
}

//roda
void drawRoda(float cx, float cy, float r)
{
    glPushMatrix(); 
        glTranslatef(cx, cy, 0.0f);
        glRotatef(rodaAngle, 0, 0, 1);

        //banluar
        glColor3f(0.10f, 0.10f, 0.10f);
        drawCircle(0, 0, r, 36);

        //velg
        glColor3f(0.75f, 0.75f, 0.75f);
        drawCircle(0, 0, r * 0.55f, 36);

        //jarijari
        glColor3f(0.50f, 0.50f, 0.50f);
        for (int i = 0; i < 4; i++) {
            glPushMatrix();          
                glRotatef(i * 45.0f, 0, 0, 1);
                glBegin(GL_QUADS);
                    glVertex2f(-0.008f,  r*0.50f);
                    glVertex2f( 0.008f,  r*0.50f);
                    glVertex2f( 0.008f, -r*0.50f);
                    glVertex2f(-0.008f, -r*0.50f);
                glEnd();
            glPopMatrix(); 
        }

        //pusat velg
        glColor3f(0.30f, 0.30f, 0.30f);
        drawCircle(0, 0, r * 0.15f, 20);

    glPopMatrix();         
}

//mobil
void drawMobil()
{
    glPushMatrix();
        glTranslatef(mobilX, -0.1f, 0.0f);

        //bawah
        glColor3f(0.80f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.30f, -0.6f);
            glVertex2f( 0.30f, -0.6f);
            glVertex2f( 0.30f, -0.45f);
            glVertex2f(-0.30f, -0.45f);
        glEnd();


        //atas
        glColor3f(0.8f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.20f, -0.45f);
            glVertex2f( 0.20f, -0.45f);
            glVertex2f( 0.08f, -0.32f);
            glVertex2f(-0.13f, -0.32f);
        glEnd();

        //kaca depan
        glColor3f(0.70f, 0.88f, 0.98f);
        glBegin(GL_QUADS);
            glVertex2f( -0.01f, -0.44f);
            glVertex2f( 0.165f, -0.44f);
            glVertex2f( 0.07f, -0.34f);
            glVertex2f( -0.01f, -0.34f);
        glEnd();

        //kaca belakang
        glColor3f(0.70f, 0.88f, 0.98f);
        glBegin(GL_QUADS);
            glVertex2f(-0.17f, -0.44f);
            glVertex2f(-0.03f, -0.44f);
            glVertex2f(-0.03f, -0.34f);
            glVertex2f(-0.12f, -0.34f);
        glEnd();

        //lampu depan
        glColor3f(1.0f, 0.97f, 0.60f);
        glBegin(GL_QUADS);
            glVertex2f( 0.27f, -0.50f);
            glVertex2f( 0.30f, -0.50f);
            glVertex2f( 0.30f, -0.47f);
            glVertex2f( 0.27f, -0.47f);
        glEnd();
        
        //lampu belakang
        glColor3f(1.0f, 0.15f, 0.15f);
        glBegin(GL_QUADS);
            glVertex2f(-0.30f, -0.50f);
            glVertex2f(-0.27f, -0.50f);
            glVertex2f(-0.27f, -0.47f);
            glVertex2f(-0.30f, -0.47f);
        glEnd();


        //roda
        drawRoda(-0.16f, -0.60f, 0.065f); //belakang
        drawRoda( 0.16f, -0.60f, 0.065f); //depan

    glPopMatrix();              
}

//Pohon
void drawPohon(float px, float py)
{
    glPushMatrix();                            
        glTranslatef(px, py, 0.0f);

        //batang
        glColor3f(0.55f, 0.35f, 0.10f);
        glBegin(GL_QUADS);
            glVertex2f(-0.025f,  0.0f);
            glVertex2f( 0.025f,  0.0f);
            glVertex2f( 0.025f,  0.22f);
            glVertex2f(-0.025f,  0.22f);
        glEnd();

        //3daun
        glColor3f(0.18f, 0.62f, 0.22f);
        drawCircle(0.0f, 0.30f, 0.12f, 36);

       
        glColor3f(0.14f, 0.70f, 0.18f);
        drawCircle(0.0f, 0.40f, 0.09f, 36);

        
        glColor3f(0.10f, 0.78f, 0.14f);
        drawCircle(0.0f, 0.47f, 0.06f, 36);

    glPopMatrix();                          
}

//awan
void drawAwan(float ax, float ay)
{
    glPushMatrix();                  
        glTranslatef(ax, ay, 0.0f);

        glColor3f(0.95f, 0.95f, 0.95f);
        drawCircle( 0.00f,  0.00f, 0.07f, 30);
        drawCircle( 0.07f,  0.02f, 0.08f, 30);
        drawCircle( 0.14f,  0.00f, 0.06f, 30);
        drawCircle(-0.06f,  0.00f, 0.055f,30);
        drawCircle( 0.07f,  0.07f, 0.055f,30);

    glPopMatrix();     
}

//langit&matahari
void drawLatar()
{
    //langit
    glColor3f(0.53f, 0.81f, 0.98f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.60f);
        glVertex2f( 1.0f, -0.60f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f(-1.0f,  1.0f);
    glEnd();

    //matahari
    glPushMatrix(); 
        glTranslatef(-0.78f, 0.75f, 0.0f);
		
		//garismatahari
        glColor3f(1.0f, 0.92f, 0.30f);
        for (int i = 0; i < 8; i++) {
            glPushMatrix(); 
                glRotatef(i * 45.0f, 0, 0, 1);
                glBegin(GL_QUADS);
                    glVertex2f(-0.008f,  0.07f);
                    glVertex2f( 0.008f,  0.07f);
                    glVertex2f( 0.008f,  0.13f);
                    glVertex2f(-0.008f,  0.13f);
                glEnd();
            glPopMatrix();  
        }

        //bola
        glColor3f(1.0f, 0.88f, 0.0f);
        drawCircle(0, 0, 0.07f, 40);

    glPopMatrix();
}

//display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawLatar();
    drawJalan();

    //pohon
    drawPohon(-0.70f, -0.60f);
    drawPohon( 0.05f, -0.60f);
    drawPohon( 0.75f, -0.60f);

    //awan
    drawAwan(awanX1,  0.70f);
    drawAwan(awanX2,  0.40f);

    drawMobil();

    glutSwapBuffers();
}

//animasi
void update(int value)
{
    /* mobil bergerak ke kanan */
    mobilX += 0.005f;
    if (mobilX > 1.4f) mobilX = -1.4f;

    /* roda berputar searah jarum jam */
    rodaAngle -= 4.0f;
    if (rodaAngle < -360.0f) rodaAngle += 360.0f;

    //gerak awan
    awanX1 -= 0.002f;
    if (awanX1 < -1.3f) awanX1 = 1.3f;

    awanX2 -= 0.001f;
    if (awanX2 < -1.3f) awanX2 = 1.3f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 6);
}

//main
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil 2D");

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
