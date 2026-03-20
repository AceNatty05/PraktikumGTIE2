/* Nama File : InteractiveArm.cpp
 * Deskripsi : Simulasi tangan interaktif dengan fitur pergerakan benda, rotasi benda, 
                dan pergerakan sendi seluruh tangan (1.0 Release)
 * Pembuat   : Rafif Setya Imaduddin (24060124130115)
 * Tanggal   : 19 Maret 2026
 * Keybind   : p = Telunjuk Atas ([ROTASI] Bawah)
 *             P = Telunjuk Atas ([ROTASI] Atas)
 *             l = Telunjuk Bawah ([ROTASI] Bawah)
 *             L = Telunjuk Bawah ([ROTASI] Atas)
 *             o = Jari Tengah Atas ([ROTASI] Bawah)
 *             O = Jari Tengah Atas ([ROTASI] Atas)
 *             k = Jari Tengah Bawah ([ROTASI] Bawah)
 *             K = Jari Tengah Bawah ([ROTASI] Atas)
 *             i = Jari Manis Atas ([ROTASI] Bawah)
 *             I = Jari Manis Atas ([ROTASI] Atas)
 *             j = Jari Manis Bawah ([ROTASI] Bawah)
 *             J = Jari Manis Bawah ([ROTASI] Atas)
 *             u = Kelingking Atas ([ROTASI] Bawah)
 *             U = Kelingking Atas ([ROTASI] Atas)
 *             h = Kelingking Bawah ([ROTASI] Bawah)
 *             H = Kelingking Bawah ([ROTASI] Atas)
 *             y = Jempol Atas ([ROTASI] Bawah)
 *             Y = Jempol Atas ([ROTASI] Atas)
 *             g = Jempol Bawah ([ROTASI] Bawah)
 *             G = Jempol Bawah ([ROTASI] Atas)
 *             b = Jempol Bawah ([ROTASI] Kanan)
 *             B = Jempol Bawah ([ROTASI] Kiri)
 *             R = Pergelangan Tangan ([ROTASI] Atas)
 *             r = Pergelangan Tangan ([ROTASI] Bawah)
 *             T = Pergelangan Tangan ([ROTASI] Kiri : Relatif Tangan Sumbu-Z)
 *             t = Pergelangan Tangan ([ROTASI] Kanan : Relatif Tangan Sumbu-Z)
 *             V = Pergelangan Tangan ([ROTASI] Kiri : Relatif Tangan Sumbu-Y)
 *             v = Pergelangan Tangan ([ROTASI] Kanan : Relatif Tangan Sumbu-Y)
 *             E = Sikut ([ROTASI] Bawah)
 *             e = Sikut ([ROTASI] Atas)
 *             F = Bahu ([ROTASI] Bawah)
 *             f = Bahu ([ROTASI] Atas)
 *             a = Rotasi Objek (Kiri : Relatif Tangan)
 *             d = Rotasi Objek (Kanan : Relatif Tangan)
 *             w = Rotasi Objek (Atas : Relatif Tangan)
 *             s = Rotasi Objek (Bawah : Relatif Tangan)
 *             A = Translasi Objek (Kiri)
 *             D = Translasi Objek (Kanan)
 *             W = Translasi Objek (Atas)
 *             S = Translasi Objek (Bawah)
 *             Mouse Wheel Atas / Mouse Kiri = Zoom In
 *             Mouse Wheel Bawah / Mouse Kanan = Zoom Out
 * 
 */

#include <GL/glut.h>
#include <gl/gl.h>
#include <math.h>

/* === KAMUS GLOBAL === */
static int shoulder = 0;
static int elbow = 0;
static int wristX = 0;
static int wristZ = 0;
static int wristY = 0;
static int thumbBFinger1 = 0;
static int thumbUFinger1 = 0;
static int thumbBFinger2 = 0;
static int pointBFinger = 0;
static int pointUFinger = 0;
static int middleBFinger = 0;
static int middleUFinger = 0;
static int ringBFinger = 0;
static int ringUFinger = 0;
static int pinkyBFinger = 0;
static int pinkyUFinger = 0;
static int objectRotateY = 0;
static int objectRotateX = 0;
static GLfloat objectTranslateY = 0;
static GLfloat objectTranslateX = 0;
static GLfloat camTranslateZ = 0;

void init(void) {
    /* === KAMUS LOKAL === */

    /* === ALGORITMA === */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void reshape(int width, int height) {
    /* === KAMUS LOKAL === */

    /* === ALGORITMA === */
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) width / (GLfloat) height, 0.01, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.5);
}

void keyboard(unsigned char key, int x, int y) {
    /* === KAMUS LOKAL === */

    /* === ALGORITMA === */
    switch(key) {
        // Transformasi Seluruh Objek
        case 'a':
            objectRotateY = (objectRotateY - 5) % 360;
            glutPostRedisplay();
            break;

        case 'd':
            objectRotateY = (objectRotateY + 5) % 360;
            glutPostRedisplay();
            break;

        case 'w':
            objectRotateX = (objectRotateX - 5) % 360;
            glutPostRedisplay();
            break;

        case 's':
            objectRotateX = (objectRotateX + 5) % 360;
            glutPostRedisplay();
            break;

        case 'A':
            objectTranslateX = fmod(objectTranslateX - 0.1, 360.0);
            glutPostRedisplay();
            break;

        case 'D':
            objectTranslateX = fmod(objectTranslateX + 0.1, 360.0);
            glutPostRedisplay();
            break;

        case 'W':
            objectTranslateY = fmod(objectTranslateY + 0.1, 360.0);
            glutPostRedisplay();
            break;

        case 'S':
            objectTranslateY = fmod(objectTranslateY - 0.1, 360.0);
            glutPostRedisplay();
            break;

        // Tangan
        case 'f':
            shoulder = (shoulder + 10) % 360;
            glutPostRedisplay();
            break;
        case 'F':
            shoulder = (shoulder - 10) % 360;
            glutPostRedisplay();
            break;

        case 'e':
            if (elbow < 170) { 
                elbow = (elbow + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'E':
            if (elbow > 0) {
                elbow = (elbow - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'r':
            if (wristX < 90) { 
                wristX = (wristX + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'R':
            if (wristX > -90) { 
                wristX = (wristX - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'v':
            if (wristY < 45) {
                wristY = (wristY + 5) % 360;
                glutPostRedisplay();
            }
            break;

        case 'V':
            if (wristY > -45) {
                wristY = (wristY - 5) % 360;
                glutPostRedisplay();
            }
            break;

        case 't':
            if (wristZ > -45) {
                wristZ = (wristZ - 5) % 360;
                glutPostRedisplay();
            }
            break;

        case 'T':
            if (wristZ < 60) {
                wristZ = (wristZ + 5) % 360;
                glutPostRedisplay();
            }
            break;

        // Jari
        case 'l':
            if (pointBFinger < 100) {
                pointBFinger = (pointBFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'p':
            if (pointUFinger < 120) {
                pointUFinger = (pointUFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'L':
            if (pointBFinger > 0) {
                pointBFinger = (pointBFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'P':
            if (pointUFinger > 0) {
                pointUFinger = (pointUFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'k':
            if (middleBFinger < 100) {
                middleBFinger = (middleBFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'o':
            if (middleUFinger < 120) {
                middleUFinger = (middleUFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'K':
            if (middleBFinger > 0) {
                middleBFinger = (middleBFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'O':
            if (middleUFinger > 0) {
                middleUFinger = (middleUFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'j':
            if (ringBFinger < 100) {
                ringBFinger = (ringBFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'i':
            if (ringUFinger < 120) {
                ringUFinger = (ringUFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'J':
            if (ringBFinger > 0) {
                ringBFinger = (ringBFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'I':
            if (ringUFinger > 0) {
                ringUFinger = (ringUFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'h':
            if (pinkyBFinger < 100) {
                pinkyBFinger = (pinkyBFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'u':
            if (pinkyUFinger < 120) {
                pinkyUFinger = (pinkyUFinger + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'H':
            if (pinkyBFinger > 0) {
                pinkyBFinger = (pinkyBFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'U':
            if (pinkyUFinger > 0) {
                pinkyUFinger = (pinkyUFinger - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'g':
            if (thumbBFinger1 < 80) {
                thumbBFinger1 = (thumbBFinger1 + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'y':
            if (thumbUFinger1 < 80) { 
                thumbUFinger1 = (thumbUFinger1 + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'G':
            if (thumbBFinger1 > 0) {
                thumbBFinger1 = (thumbBFinger1 - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'Y':
            if (thumbUFinger1 > 0) {
                thumbUFinger1 = (thumbUFinger1 - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'B':
            if (thumbBFinger2 > -45) {
                thumbBFinger2 = (thumbBFinger2 - 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 'b':
            if (thumbBFinger2 < 80) {
                thumbBFinger2 = (thumbBFinger2 + 10) % 360;
                glutPostRedisplay();
            }
            break;

        case 32: 
            exit(0);
            break;

        default:
            break;
    }
}

void mouse(int tombol, int state, int x, int y) {
    /* === KAMUS LOKAL === */

    /* === ALGORITMA === */
    if (state == GLUT_DOWN) {
        if (tombol == 3 || tombol == 0) {
            camTranslateZ = camTranslateZ + 0.35;
        } 
        else if (tombol == 4 || tombol == 2) { 
            camTranslateZ = camTranslateZ - 0.35;
        }
        glutPostRedisplay();
    }
}

void rotation(const char* sendi) {
    /* === KAMUS LOKAL === */

    /* === ALGORITMA === */
    if (sendi == "Shoulder") {
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
    } 
    
    else if (sendi == "Elbow") {
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
    } 
    
    else if (sendi == "Wrist") {
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) wristX, 0.0, 0.0, 1.0);
        glRotatef((GLfloat) wristZ, 0.0, 1.0, 0.0);
        glRotatef((GLfloat) wristY, 1.0, 0.0, 0.0);
        glTranslatef(0.5, 0.0, 0.0);
    } 
    
    else if (sendi == "Point Bottom") {
        glTranslatef(0.4, 0.0, 0.0);
        glRotatef((GLfloat) pointBFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.3, -0.1, 0.375);
    } 
    
    else if (sendi == "Point Upper") {
        glTranslatef(0.2, 0.0, 0.0);
        glRotatef((GLfloat) pointUFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);
    } 
    
    else if (sendi == "Middle Bottom") {
        glTranslatef(0.35, 0.0, 0.0);
        glRotatef((GLfloat) middleBFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.4, -0.1, 0.125);
    } 
    
    else if (sendi == "Middle Upper") {
        glTranslatef(0.2, 0.0, 0.0);
        glRotatef((GLfloat) middleUFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.3, 0.0, 0.0);
    } 
    
    else if (sendi == "Ring Bottom") {
        glTranslatef(0.3, 0.0, 0.0);
        glRotatef((GLfloat) ringBFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.425, -0.1, -0.125);
    } 
    
    else if (sendi == "Ring Upper") {
        glTranslatef(0.25, 0.0, 0.0);
        glRotatef((GLfloat) ringUFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);
    } 
    
    else if (sendi == "Pinky Bottom") {
        glTranslatef(0.3, 0.0, 0.0);
        glRotatef((GLfloat) pinkyBFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.37, -0.11, -0.38);
    } 
    
    else if (sendi == "Pinky Upper") {
        glTranslatef(0.2, 0.0, 0.0);
        glRotatef((GLfloat) pinkyUFinger, 0.0, 0.0, 1.0);
        glTranslatef(0.15, 0.0, 0.0);
    } 
    
    else if (sendi == "Thumb Bottom") {
        glTranslatef(-0.1, 0.0, 0.6);
        glRotatef((GLfloat) thumbBFinger2, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, -0.6);

        glTranslatef(-0.1, 0.0, 0.0);
        glRotatef((GLfloat) thumbBFinger1, 0.0, 0.0, 1.0);
        glTranslatef(0.1, 0.0, 0.6);
    } 
    
    else if (sendi == "Thumb Upper") {
        glTranslatef(0.15, 0.0, 0.0);
        glRotatef((GLfloat) thumbUFinger1, 0.0, 1.0, 0.0);
        glTranslatef(0.2, 0.0, 0.0);
    }
}

void wireCubeObject(double x, double y, double z) {
    /* === KAMUS LOKAL === */

    /* === ALGORITMA === */
    glScalef(x, y, z);
    glutWireCube(1.0);  
}

void display(void) {
    /* === KAMUS LOKAL === */

    /* === ALGORITMA === */
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        // Translasi Semua Objek terhadap Sumbu-X dan Sumbu-Y
        glTranslatef(objectTranslateX, objectTranslateY, camTranslateZ);

        // Rotasi Semua Objek terhadap Sumbu-Y
        glRotatef((GLfloat) objectRotateY, 0.0, 1.0, 0.0);

        // Rotasi Semua Objek terhadap Sumbu-X
        glRotatef((GLfloat) objectRotateX, 1.0, 0.0, 0.0);

        // Rotasi Semua Objek
        glRotatef(40.0, 1.0, 0.5, 0.0);
        // Offset Semua Objek
        glTranslatef(-1.8, 1.5, 1.9);
        // Skala Semua Objek
        glScalef(0.8, 0.8, 0.8);

        // Rotasi Bahu
        rotation("Shoulder");

        // Lengan Atas
        glPushMatrix();
            wireCubeObject(2.0, 0.4, 1.0);
        glPopMatrix();

        // Rotasi Sikut
        rotation("Elbow");

        // Lengan Bawah
        glPushMatrix();
            wireCubeObject(2.0, 0.4, 0.6);
        glPopMatrix();

        // Rotasi Pergelangan Tangan Terhadap Sumbu-X, Sumbu-Y, Sumbu-Z 
        // (Relatif Tangan (Orangnya), bukan Relatif Persepektif Kamera Awal)
        rotation("Wrist");

        glPushMatrix();
            // Telapak Tangan
            glPushMatrix();
                wireCubeObject(1.0, 0.4, 1.0);
            glPopMatrix();

            // Telunjuk
            glPushMatrix();
                // Rotasi Telunjuk Bawah
                rotation("Point Bottom");

                // Telunjuk Bawah
                glPushMatrix();
                    wireCubeObject(0.4, 0.2, 0.25);
                glPopMatrix();

                // Rotasi Telunjuk Atas
                rotation("Point Upper");

                // Telunjuk Atas
                glPushMatrix();
                    wireCubeObject(0.4, 0.2, 0.25);
                glPopMatrix();
            glPopMatrix();

            // Jari Tengah
            glPushMatrix();
                // Rotasi Jari Tengah Bawah
                rotation("Middle Bottom");

                // Jari Tengah Bawah
                glPushMatrix();
                    wireCubeObject(0.5, 0.2, 0.25);
                glPopMatrix();

                // Rotasi Jari Tengah Atas
                rotation("Middle Upper");

                // Jari Tengah Atas
                glPushMatrix();
                    wireCubeObject(0.5, 0.2, 0.25);
                glPopMatrix();
            glPopMatrix();

            // Jari Manis
            glPushMatrix();
                // Rotasi Jari Manis Bawah
                rotation("Ring Bottom");

                // Jari Manis Bawah
                glPushMatrix();
                    wireCubeObject(0.45, 0.2, 0.25);
                glPopMatrix();

                // Rotasi Jari Manis Atas
                rotation("Ring Upper");

                // Jari Manis Atas
                glPushMatrix();
                    wireCubeObject(0.45, 0.2, 0.25);
                glPopMatrix();
            glPopMatrix();

            // Kelingking
            glPushMatrix();
                // Rotasi Kelingking Bawah
                rotation("Pinky Bottom");

                // Kelingking Bawah
                glPushMatrix();
                    wireCubeObject(0.35, 0.2, 0.25);
                glPopMatrix();

                // Rotasi Kelingking Atas
                rotation("Pinky Upper");

                // Kelingking Atas
                glPushMatrix();
                    wireCubeObject(0.35, 0.2, 0.25);
                glPopMatrix();
            glPopMatrix();


            // Jempol
            glPushMatrix();
                // Rotasi Jempol Bawah
                rotation("Thumb Bottom");

                // Jempol Bawah
                glPushMatrix();
                    glRotatef(90.0, 1.0, 0.0, 0.0);
                    wireCubeObject(0.35, 0.2, 0.3);
                glPopMatrix();

                // Rotasi Jempol Atas
                rotation("Thumb Upper");

                // Jempol Atas
                glPushMatrix();
                    glRotatef(90.0, 1.0, 0.0, 0.0);
                    wireCubeObject(0.35, 0.2, 0.3);
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
        
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    /* === KAMUS === */

    /* === ALGORITMA === */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}