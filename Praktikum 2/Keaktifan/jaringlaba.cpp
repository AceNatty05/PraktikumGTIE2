#include <GL/glut.h>
#include <math.h>

int sisi = 8;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float sudut = 2 * M_PI / sisi;

    
    glBegin(GL_LINES);
    for(int i=0;i<sisi;i++){
        float x = cos(i*sudut);
        float y = sin(i*sudut);

        glVertex2f(0,0);
        glVertex2f(x*0.8,y*0.8);
    }
    glEnd();

    
    for(float r=0.2;r<=0.8;r+=0.2){
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<sisi;i++){
            float x = r*cos(i*sudut);
            float y = r*sin(i*sudut);
            glVertex2f(x,y);
        }
        glEnd();
    }

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Jaring Laba-laba");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
