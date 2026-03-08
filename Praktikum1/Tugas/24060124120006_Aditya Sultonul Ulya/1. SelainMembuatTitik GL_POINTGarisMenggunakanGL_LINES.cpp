#include <GL/glut.h>
#include <math.h>

float PI = 3.1415926;

// garis tebal menggunakan quad
void drawLineQuad(float x1, float y1, float x2, float y2, float width){
    float dx = x2 - x1;
    float dy = y2 - y1;
    float len = sqrt(dx*dx + dy*dy);

    float px = -dy / len * width;
    float py = dx / len * width;

    glBegin(GL_QUADS);
        glVertex2f(x1 + px, y1 + py);
        glVertex2f(x1 - px, y1 - py);
        glVertex2f(x2 - px, y2 - py);
        glVertex2f(x2 + px, y2 + py);
    glEnd();
}

// titik quad
void drawDot(float x, float y, float size){
    glBegin(GL_QUADS);
        glVertex2f(x-size, y-size);
        glVertex2f(x+size, y-size);
        glVertex2f(x+size, y+size);
        glVertex2f(x-size, y+size);
    glEnd();
}

void star(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.0,0.0);

    float outer = 0.75;      
    float dotRadius = 0.85;  
    float inner = 0.35;

    float width = 0.01;

    float sideAngle = 5 * PI / 180.0;  

    for(int i=0;i<5;i++){

        float angle = i * 72.0 * PI / 180.0;

        float tipX = outer * sin(angle);
        float tipY = outer * cos(angle);

        float dotX = dotRadius * sin(angle);
        float dotY = dotRadius * cos(angle);

        float x1 = inner * sin(angle - sideAngle);
        float y1 = inner * cos(angle - sideAngle);

        float x2 = inner * sin(angle + sideAngle);
        float y2 = inner * cos(angle + sideAngle);

        drawLineQuad(x1,y1,tipX,tipY,width);
        drawLineQuad(x2,y2,tipX,tipY,width);

        drawDot(dotX,dotY,0.015);
    }

    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Star");

    glutDisplayFunc(star);

    glClearColor(1.0,1.0,1.0,1.0);

    glutMainLoop();
    return 0;
}
