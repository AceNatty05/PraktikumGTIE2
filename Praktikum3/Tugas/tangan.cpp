// Nama     : Farhan Dwiyan Akbar
// NIM      : 24060124140137

// ==========================================================
// PETUNJUK 
// ==========================================================
//
// === LENGAN ===
// Bahu:
//   s  : putar maju
//   S  : putar mundur
//
// Siku:
//   e  : tekuk
//   E  : luruskan
//
// === JARI ===
//
// Jari 1 (Ibu Jari):
//   q / a : ruas 1
//   w / x : ruas 2
//
// Jari 2:
//   t / g : ruas 1
//   y / h : ruas 2
//   u / j : ruas 3
//
// Jari 3:
//   i / k : ruas 1
//   o / l : ruas 2
//   p / ; : ruas 3
//
// Jari 4:
//   z / v : ruas 1
//   c / b : ruas 2
//   n / m : ruas 3
//
// Jari 5:
//   1 / 2 : ruas 1
//   3 / 4 : ruas 2
//   5 / 6 : ruas 3
//
// ==========================================================

#include <GL/glut.h>

int shoulder = 0;
int elbow = 0;

int finger[5][3] = {0};

void drawSegment()
{
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);

        // ===== SHOULDER =====
        glRotatef(shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // ===== ELBOW =====
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef(elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // ===== TELAPAK =====
        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();
            glScalef(0.8, 0.3, 0.2);
            glutWireCube(1.0);
        glPopMatrix();

        // ===== JARI =====
        for(int i = 0; i < 5; i++)
        {
            glPushMatrix();

            glTranslatef(0.5, 0.2 - i*0.1, 0.0);

            // ruas 1
            glRotatef(finger[i][0], 0.0, 0.0, 1.0);
            glTranslatef(0.2, 0.0, 0.0);
            drawSegment();

            // ruas 2
            glTranslatef(0.2, 0.0, 0.0);
            glRotatef(finger[i][1], 0.0, 0.0, 1.0);
            glTranslatef(0.2, 0.0, 0.0);
            drawSegment();

            // ruas 3
            if(i != 0)
            {
                glTranslatef(0.2, 0.0, 0.0);
                glRotatef(finger[i][2], 0.0, 0.0, 1.0);
                glTranslatef(0.2, 0.0, 0.0);
                drawSegment();
            }

            glPopMatrix();
        }

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void rotateFinger(int f, int s, int delta)
{
    int newAngle = finger[f][s] + delta;
    if(newAngle >= 0 && newAngle <= 90)
        finger[f][s] = newAngle;
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        // ===== SHOULDER =====
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;

        // ===== ELBOW =====
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;

        // ===== IBU JARI =====
        case 'q': rotateFinger(0,0,5); break;
        case 'a': rotateFinger(0,0,-5); break;
        case 'w': rotateFinger(0,1,5); break;
        case 'x': rotateFinger(0,1,-5); break;

        // ===== JARI 2 =====
        case 't': rotateFinger(1,0,5); break;
        case 'g': rotateFinger(1,0,-5); break;
        case 'y': rotateFinger(1,1,5); break;
        case 'h': rotateFinger(1,1,-5); break;
        case 'u': rotateFinger(1,2,5); break;
        case 'j': rotateFinger(1,2,-5); break;

        // ===== JARI 3 =====
        case 'i': rotateFinger(2,0,5); break;
        case 'k': rotateFinger(2,0,-5); break;
        case 'o': rotateFinger(2,1,5); break;
        case 'l': rotateFinger(2,1,-5); break;
        case 'p': rotateFinger(2,2,5); break;
        case ';': rotateFinger(2,2,-5); break;

        // ===== JARI 4 =====
        case 'z': rotateFinger(3,0,5); break;
        case 'v': rotateFinger(3,0,-5); break;
        case 'c': rotateFinger(3,1,5); break;
        case 'b': rotateFinger(3,1,-5); break;
        case 'n': rotateFinger(3,2,5); break;
        case 'm': rotateFinger(3,2,-5); break;

        // ===== JARI 5 =====
        case '1': rotateFinger(4,0,5); break;
        case '2': rotateFinger(4,0,-5); break;
        case '3': rotateFinger(4,1,5); break;
        case '4': rotateFinger(4,1,-5); break;
        case '5': rotateFinger(4,2,5); break;
        case '6': rotateFinger(4,2,-5); break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tangan Robot");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
