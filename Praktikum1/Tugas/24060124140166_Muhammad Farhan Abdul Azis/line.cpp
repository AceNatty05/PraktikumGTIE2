#include <GL/glut.h>

void Garis(void) {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the width of the line to 2.0 pixels
    glLineWidth(2.0f);

    // Start drawing lines
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);    // Set color to White
        glVertex3f(0.00, 0.20, 0.0);    // Starting point (Top)
        glVertex3f(0.00, -0.20, 0.0);   // Ending point (Bottom)
    glEnd();

    // Force execution of OpenGL commands
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    
    // Create the window with the title "Membuat Garis"
    glutCreateWindow("Membuat Garis");

    glutDisplayFunc(Garis);

    // Background color set to Blue
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}