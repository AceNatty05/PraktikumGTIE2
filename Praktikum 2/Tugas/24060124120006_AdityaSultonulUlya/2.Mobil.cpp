#include <GL/glut.h>
#include <math.h>

float posisiMobil = -1.2;
float rotasiRoda = 0;
float posisiAwan1 = -1.2;
float posisiAwan2 = 0.0;
float posisiAwan3 = 0.8;

void ban()
{
    // Ban luar
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        for(int i=0;i<=100;i++)
        {
            float angle = 2*3.1416*i/100;
            glVertex2f(cos(angle)*0.08, sin(angle)*0.08);
        }
    glEnd();
    
    // Velg
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.8, 0.8, 0.8);
        glVertex2f(0.0, 0.0);
        for(int i=0;i<=100;i++)
        {
            float angle = 2*3.1416*i/100;
            glVertex2f(cos(angle)*0.05, sin(angle)*0.05);
        }
    glEnd();
    
    // ruji velg
    glColor3f(0.3, 0.3, 0.3);
    glLineWidth(2.0);
    glBegin(GL_LINES);
        for(int i=0; i<8; i++)
        {
            float angle = i * 45.0 * 3.1416 / 180.0;
            float x = cos(angle) * 0.05;
            float y = sin(angle) * 0.05;
            glVertex2f(0.0, 0.0);
            glVertex2f(x, y);
        }
    glEnd();
    
    // Lingkaran tengah velg
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        for(int i=0;i<=100;i++)
        {
            float angle = 2*3.1416*i/100;
            glVertex2f(cos(angle)*0.015, sin(angle)*0.015);
        }
    glEnd();
    
    glLineWidth(1.0); 
}

void mobil()
{
    // body mobil 
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.3, 0.0);
        glVertex2f(0.3, 0.0);
        glVertex2f(0.3, 0.15);
        glVertex2f(-0.3, 0.15);
    glEnd();

	// garis biru
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.3, 0.05);
        glVertex2f(0.3, 0.05);
        glVertex2f(0.3, 0.08);
        glVertex2f(-0.3, 0.08);
    glEnd();
    
    glBegin(GL_QUADS);
        glVertex2f(-0.3, 0.11);
        glVertex2f(0.3, 0.11);
        glVertex2f(0.3, 0.14);
        glVertex2f(-0.3, 0.14);
    glEnd();

	 // atap mobil
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        glVertex2f(-0.15, 0.15);
        glVertex2f(0.15, 0.15);
        glVertex2f(0.08, 0.28);
        glVertex2f(-0.08, 0.28);
    glEnd();

	// jendela
    glColor3f(0.6, 0.8, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.12, 0.16);
        glVertex2f(0.12, 0.16);
        glVertex2f(0.06, 0.25);
        glVertex2f(-0.06, 0.25);
    glEnd();

	 // lampu polisi
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.02, 0.3);
        for(int i=0;i<=360;i+=30)
        {
            float angle = i * 3.1416 / 180;
            glVertex2f(cos(angle)*0.015 - 0.02, sin(angle)*0.015 + 0.3);
        }
    glEnd();
    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.02, 0.3);
        for(int i=0;i<=360;i+=30)
        {
            float angle = i * 3.1416 / 180;
            glVertex2f(cos(angle)*0.015 + 0.02, sin(angle)*0.015 + 0.3);
        }
    glEnd();

	// roda
    glPushMatrix();
        glTranslatef(-0.18, 0.0, 0);
        glRotatef(rotasiRoda, 0, 0, 1);
        ban();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.18, 0.0, 0);
        glRotatef(rotasiRoda, 0, 0, 1);
        ban();
    glPopMatrix();
}

void awan(float x, float y, float size)
{
    // Awan
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
        glTranslatef(x - size*0.3, y, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.0, 0.0);
            for(int i=0;i<=360;i+=20)
            {
                float angle = i * 3.1416 / 180;
                glVertex2f(cos(angle)*size*0.5, sin(angle)*size*0.4);
            }
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(x, y + size*0.1, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.0, 0.0);
            for(int i=0;i<=360;i+=20)
            {
                float angle = i * 3.1416 / 180;
                glVertex2f(cos(angle)*size*0.6, sin(angle)*size*0.5);
            }
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(x + size*0.3, y, 0);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.0, 0.0);
            for(int i=0;i<=360;i+=20)
            {
                float angle = i * 3.1416 / 180;
                glVertex2f(cos(angle)*size*0.5, sin(angle)*size*0.4);
            }
        glEnd();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Awan Gerak
    awan(posisiAwan1, 0.7, 0.25);
    awan(posisiAwan2, 0.8, 0.3);
    awan(posisiAwan3, 0.6, 0.2);
    
    // Jalan
    glColor3f(0.3,0.3,0.3);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.2);
        glVertex2f(1,-0.2);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();

    // garis jalan
    glColor3f(1,1,1);
    for(float i=-1;i<1;i+=0.4)
    {
        glBegin(GL_QUADS);
            glVertex2f(i,-0.55);
            glVertex2f(i+0.2,-0.55);
            glVertex2f(i+0.2,-0.5);
            glVertex2f(i,-0.5);
        glEnd();
    }

    // mobil
    glPushMatrix();
        glTranslatef(posisiMobil,-0.2,0);
        mobil();
    glPopMatrix();

    glFlush();
}

void update(int value)
{
    // Mobil Gerak
    posisiMobil += 0.01;
    rotasiRoda -= 5;
    
    // Awan Gerak
    posisiAwan1 -= 0.002;  
    posisiAwan2 -= 0.003;  
    posisiAwan3 -= 0.0015; 
    
    if(posisiAwan1 < -1.5) posisiAwan1 = 1.5; 
    if(posisiAwan2 < -1.5) posisiAwan2 = 1.5;
    if(posisiAwan3 < -1.5) posisiAwan3 = 1.5;
    
    if(posisiMobil > 1.2) posisiMobil = -1.2;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(800,600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Mobil Polisi");

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glClearColor(0.5, 0.8, 1.0, 1.0);

    glutMainLoop();
    return 0;
}
