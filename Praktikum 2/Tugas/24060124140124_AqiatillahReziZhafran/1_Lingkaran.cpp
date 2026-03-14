/*Nama	: Aqiatillah Rezi Zhafran
 NIM	: 24060124140124
 LAB	: E2*/

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>
#define PI 3.14159265358979323846

void RenderScene(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glLineWidth(10.0f);
   glColor3f(1.0f, 1.0f, 1.0f);
   glBegin(GL_LINE_LOOP);
   GLint circle_points = 10000000;
   for (int i = 0; i < circle_points; i++) {
       float angle = 2.0 * PI * i / circle_points;
       glVertex2f(0.5 * cos(angle), 0.5 * sin(angle));
   }
   glEnd();
   glPopMatrix();
   glFlush();
}

int main(int argc, char* argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(640, 480);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutCreateWindow("Tugas 1 Lingkaran");
   glutDisplayFunc(RenderScene);
   glClearColor(0.800f, 0.407f, 0.858f, 0.94f);
   glutMainLoop();
   return 0;
