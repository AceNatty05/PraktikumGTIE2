#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

void Lingkaran(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);
float PI = 3.1415921;
glPushMatrix();
glBegin(GL_LINE_LOOP);
GLint circle_points = 100;
for (int i = 0; i < circle_points; i++) {
float angle = 2 * PI * i / circle_points;
glVertex2f(cos(angle), sin(angle));
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
    glutCreateWindow("Lingkaran");
    glutDisplayFunc(Lingkaran);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
