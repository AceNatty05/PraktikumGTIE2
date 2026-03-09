/* Nama : Aqiatillah Rezi Zhafran
   NIM  : 24060124140124
   Lab : E2 */
#include <GL/glut.h>

void Makecabang()
{
    glLineWidth(8);
    glBegin(GL_LINES);
    // batang 
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.5);
    // cabang kiri
    glVertex2f(0.0, 0.35);
    glVertex2f(-0.15, 0.45);
    // cabang kanan
    glVertex2f(0.0, 0.35);
    glVertex2f(0.15, 0.45);
    // cabang kecil kiri
    glVertex2f(0.0, 0.2);
    glVertex2f(-0.12, 0.28);
    // cabang kecil kanan
    glVertex2f(0.0, 0.2);
    glVertex2f(0.12, 0.28);
    glEnd();
}
void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.6, 0.8, 1.0);
    int sisi = 6;
    float sudut = 360.0 / sisi;
    for(int i=0;i<sisi;i++)
    {
        glPushMatrix();
        glRotatef(i*sudut,0,0,1);
        Makecabang();
        glPopMatrix();
    }
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Snowflake");
    glutDisplayFunc(RenderScene);
    glClearColor(1,1,1,1);
    glutMainLoop();
}
