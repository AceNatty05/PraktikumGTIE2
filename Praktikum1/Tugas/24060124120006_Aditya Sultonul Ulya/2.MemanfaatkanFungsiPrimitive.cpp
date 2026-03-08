#include <GL/glut.h>

void scene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // =========================
    // Matahari (GL_TRIANGLE_FAN)
    // =========================
    glColor3f(1.0, 0.8, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.7, 0.7);
        glVertex2f(0.6, 0.7);
        glVertex2f(0.63, 0.77);
        glVertex2f(0.7, 0.8);
        glVertex2f(0.77, 0.77);
        glVertex2f(0.8, 0.7);
        glVertex2f(0.77, 0.63);
        glVertex2f(0.7, 0.6);
        glVertex2f(0.63, 0.63);
        glVertex2f(0.6, 0.7);
    glEnd();

    // Matahari OUTLINE (GL_LINE_LOOP)
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.6, 0.7);
        glVertex2f(0.63, 0.77);
        glVertex2f(0.7, 0.8);
        glVertex2f(0.77, 0.77);
        glVertex2f(0.8, 0.7);
        glVertex2f(0.77, 0.63);
        glVertex2f(0.7, 0.6);
        glVertex2f(0.63, 0.63);
    glEnd();

    // =========================
    // GUNUNG (GL_TRIANGLES)
    // =========================
    glColor3f(0.0, 0.7, 0.0);
    glBegin(GL_TRIANGLES);

        // gunung 1
        glVertex2f(-1.5, -0.2);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.25, -0.2);

        // gunung 2
        glVertex2f(-0.25, -0.2);
        glVertex2f(0.5, 0.5);
        glVertex2f(1.5, -0.2);

    glEnd();

    // =========================
    // GUNUNG OUTLINE (GL_LINE_STRIP)
    // =========================
    glColor3f(0.0, 0.4, 0.0);
    glBegin(GL_LINE_STRIP);
        // Gunung 1 outline
        glVertex2f(-1.5, -0.2);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.25, -0.2);
        // Gunung 2 outline (disambung)
        glVertex2f(-0.25, -0.2);
        glVertex2f(0.5, 0.5);
        glVertex2f(1.5, -0.2);
    glEnd();

    // =========================
    // HOUSE ROOF (GL_TRIANGLE_STRIP)
    // =========================
    glColor3f(0.7, 0.0, 0.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.25, 0.1);
        glVertex2f(0.25, 0.1);
        glVertex2f(-0.1, 0.3);
        glVertex2f(0.1, 0.3);
    glEnd();

    // =========================
    // HOUSE BODY (GL_QUADS)
    // =========================
    glColor3f(0.9, 0.7, 0.4);
    glBegin(GL_QUADS);
        glVertex2f(-0.25, -0.2);
        glVertex2f(0.25, -0.2);
        glVertex2f(0.25, 0.1);
        glVertex2f(-0.25, 0.1);
    glEnd();

    // DOOR (GL_QUADS)
    glColor3f(0.4, 0.2, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.05, -0.2);
        glVertex2f(0.05, -0.2);
        glVertex2f(0.05, -0.05);
        glVertex2f(-0.05, -0.05);
    glEnd();

    // =========================
    // ROAD (GL_QUAD_STRIP)
    // =========================
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.1, -0.2);
        glVertex2f(0.1, -0.2);

        glVertex2f(-0.15, -0.5);
        glVertex2f(0.15, -0.5);

        glVertex2f(-0.2, -0.8);
        glVertex2f(0.2, -0.8);
        
        glVertex2f(-0.25, -1.0);
        glVertex2f(0.25, -1.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(480,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("OpenGL Primitive Example");

    glutDisplayFunc(scene);

    glClearColor(0.5, 0.8, 1.0, 1.0);

    glutMainLoop();
    return 0;
}
