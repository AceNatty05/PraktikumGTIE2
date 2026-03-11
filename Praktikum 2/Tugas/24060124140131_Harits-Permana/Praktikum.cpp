#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

//void SegiEmpat(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glTranslatef(0.50, 0.50, 0.0);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glRectf(-0.18, 0.18, 0.18, -0.18);
//    glFlush();
//}

//void Segitiga(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glRotated(90.0, 0.0, 0.0, 1.0);
//    glBegin(GL_TRIANGLES);
//        glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);
//        glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, 0.0, 0.00);
//        glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0, 0.15, 0.00);
//    glEnd();
//    glFlush();
//}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

//     Bagian 1: Menggambar Garis
    glPushMatrix(); 
        glLineWidth(2.0f); 
        glBegin(GL_LINES); 
            glColor3f(1.0f, 1.0f, 1.0f); 
            glVertex3f(0.00, 0.20, 0.0); 
            glVertex3f(0.00, -0.20, 0.0); 
        glEnd(); 
    glPopMatrix(); 

//	 Bagian 2: Menggambar Titik dengan Translasi
    glPushMatrix(); 
        glPointSize(5.0f); 
        glTranslatef(0.35, 0.35, 0.0); 
        glBegin(GL_POINTS); 
            glColor3f(1.0f, 1.0f, 1.0f); 
            glVertex3f(0.25, 0.25, 0.0); 
        glEnd(); 
    glPopMatrix(); 
    
//     3. Menggambar Persegi Panjang (Triangle Strip) berwarna-warni
    glPushMatrix();
        glTranslatef(0.50, 0.50, 0.00);
        glBegin(GL_TRIANGLE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.05, -0.05, 0.00);
            glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, -0.05, 0.00);
            glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-0.05, 0.05, 0.00);
            glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.15, 0.05, 0.00);
        glEnd();
    glPopMatrix();
    
//     4. Menggambar Lingkaran di Tengah
    float PI = 3.141592;
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
    glutCreateWindow("Simple"); 
    glutDisplayFunc(RenderScene); 
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); 
    glutMainLoop(); 
    return 0; 
}
