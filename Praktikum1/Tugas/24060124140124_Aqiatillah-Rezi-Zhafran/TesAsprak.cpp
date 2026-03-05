#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. GL_LINE_STRIP 
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9f, 0.7f);
        glVertex2f(-0.7f, 0.5f);
        glVertex2f(-0.5f, 0.7f);
        glVertex2f(-0.3f, 0.5f);
        glVertex2f(-0.1f, 0.7f);
    glEnd();


    // 2. GL_LINE_LOOP 
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.2f, 0.7f);
        glVertex2f(0.4f, 0.8f);
        glVertex2f(0.6f, 0.7f);
        glVertex2f(0.55f, 0.5f);
        glVertex2f(0.25f, 0.5f);
    glEnd();


    // 3. GL_TRIANGLE_FAN 
	glColor3f(1.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(0.7f, 0.3f); 
    	glVertex2f(0.8f, 0.3f);
    	glVertex2f(0.77f, 0.37f);
    	glVertex2f(0.7f, 0.4f);
    	glVertex2f(0.63f, 0.37f);
    	glVertex2f(0.6f, 0.3f);
    	glVertex2f(0.63f, 0.23f);
    	glVertex2f(0.7f, 0.2f);
    	glVertex2f(0.77f, 0.23f);
    	glVertex2f(0.8f, 0.3f);
	glEnd();

    // 4. GL_TRIANGLE_STRIP 
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.0f, -0.3f);
        glVertex2f(0.2f, -0.1f);
        glVertex2f(0.3f, -0.3f);
        glVertex2f(0.5f, -0.1f);
    glEnd();


    // 5. GL_QUADS 
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.9f, -0.8f);
        glVertex2f(-0.6f, -0.8f);
        glVertex2f(-0.6f, -0.6f);
        glVertex2f(-0.9f, -0.6f);
    glEnd();


    // 6. GL_QUAD_STRIP 
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.1f, -0.8f);
        glVertex2f(0.1f, -0.6f);
        glVertex2f(0.3f, -0.8f);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.5f, -0.8f);
        glVertex2f(0.5f, -0.6f);
        glVertex2f(0.7f, -0.8f);
        glVertex2f(0.7f, -0.6f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tugas modul");

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

