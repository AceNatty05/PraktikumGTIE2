#include <GLUT/glut.h>

void drawBranch(void) {
    glBegin(GL_LINE_STRIP);

    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.3);

    glVertex2f(0.05, 0.35);
    glVertex2f(0.0, 0.3);

    glVertex2f(-0.05, 0.35);
    glVertex2f(0.0, 0.3);

    glVertex2f(0.0, 0.6);

    glVertex2f(0.07, 0.65);
    glVertex2f(0.0, 0.6);

    glVertex2f(-0.07, 0.65);
    glVertex2f(0.0, 0.6);

    glEnd();
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,1.0,1.0);

    glPushMatrix();

    for(int i=0;i<6;i++){
        drawBranch();
        glRotatef(60,0,0,1); 
    }

    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(0,0,0,1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Snowflake - OpenGL GLUT");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}