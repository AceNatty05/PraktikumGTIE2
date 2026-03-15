#include <GL/glut.h>
#include <math.h>

float PI = 3.1415926;

// lingkaran
void lingkaran(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);

    for(int i=0;i<100;i++)
    {
        float angle = 2 * PI * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);

        glVertex2f(cx + x, cy + y);
    }

    glEnd();
}

void scene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // lingkaran pusat
    glColor3f(1.0,0.7,0.0);
    lingkaran(0.0,0.0,0.2);

    // lingkaran luar
    int jumlah = 8;
    float radius = 0.32;

    for(int i=0;i<jumlah;i++)
    {
        float angle = 2*PI*i/jumlah;

        float x = radius*cos(angle);
        float y = radius*sin(angle);

        glColor3f(0.2,0.6,1.0);
        lingkaran(x,y,0.115);
    }

    // bubble di luar
    glColor3f(0.9,0.9,1.0);
    lingkaran(-0.7,0.6,0.08);
    lingkaran(-0.8,0.4,0.05);
    lingkaran(0.75,0.5,0.07);
    lingkaran(0.6,0.7,0.05);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Lingkaran");

    glutDisplayFunc(scene);

    glClearColor(0.1,0.1,0.2,1.0);

    glutMainLoop();
}
