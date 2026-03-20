
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
static int shoulder = 0, elbow = 0, telapak = 0, atas = 0, jari1 = 0,
           jari12 = 0, jari2 = 0, jari22 = 0, jari3 = 0, jari32 = 0, jari4 = 0,
           jari42 = 0, jempol1 = 0, jempol2 = 0, jempol3 = 0;

// Petunjuk:
// w/s : Menggerakkan Bahu keAtas dan keBawah
// a/d : Menggerakkan Lengan keKanan dan keKiri
// E/e : Menggerakkan Siku keAtas dan keBawah
// Q/q : Menggerakkan Telapak Tangan
// 1/! : Menggerakkan Jari Telunjuk
// 2/@ : Menggerakkan Jari Tengah
// 3/# : Menggerakkan Jari Manis
// 4/$ : Menggerakkan Jari Kelingking
// 5/% : Menggerakkan Jempol
// r : Menggerakkan Jempol ke samping

// Keaktifan
// z/x/c/v/b/n : Berbagai macam template kombinasi jari

void init(void) {
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  glTranslatef(-2.0, 0.0, 0.0);
  glRotatef((GLfloat)shoulder, 0.0, 1.0, 0.0);
  glRotatef((GLfloat)atas, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);

  glPushMatrix();
  glScalef(2.0, 0.4, 1.0);
  glColor3f(0.8f, 0.8f, 0.8f);
  glutWireCube(1.0);
  glPopMatrix();

  glTranslatef(1.0, 0.0, 0.0);
  glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);

  glPushMatrix();
  glScalef(2.0, 0.4, 1.0);
  glColor3f(0.8f, 0.8f, 0.8f);
  glutWireCube(1.0);
  glPopMatrix();

  /* ==== TELAPAK ==== */
  glTranslatef(1.0, 0.0, 0.0);
  glRotatef((GLfloat)telapak, 0.0, 0.0, 1.0);
  glTranslatef(0.5, 0.0, 0.0);

  glPushMatrix();
  glScalef(1.0, 0.6, 1.2);
  glutWireCube(1.0);
  glPopMatrix();

  /* ===== JARI 1 ===== */
  glPushMatrix();
  glTranslatef(0.5, 0.08, 0.45);
  glRotatef((GLfloat)jari1, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();

  glTranslatef(0.25, 0.0, 0.0);
  glRotatef((GLfloat)jari12, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();
  glPopMatrix();

  /* ===== JARI 2 ===== */
  glPushMatrix();
  glTranslatef(0.5, 0.08, 0.15);
  glRotatef((GLfloat)jari2, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();

  glTranslatef(0.25, 0.0, 0.0);
  glRotatef((GLfloat)jari22, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();
  glPopMatrix();

  /* ===== JARI 3 ===== */
  glPushMatrix();
  glTranslatef(0.5, 0.08, -0.15);
  glRotatef((GLfloat)jari3, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();

  glTranslatef(0.25, 0.0, 0.0);
  glRotatef((GLfloat)jari32, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();
  glPopMatrix();

  /* ===== JARI 4 ===== */
  glPushMatrix();
  glTranslatef(0.5, 0.08, -0.45);
  glRotatef((GLfloat)jari4, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();

  glTranslatef(0.25, 0.0, 0.0);
  glRotatef((GLfloat)jari42, 0.0, 0.0, 1.0);
  glTranslatef(0.25, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.5, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();
  glPopMatrix();

  /* ===== JEMPOL ===== */
  glPushMatrix();
  glTranslatef(0.0, 0.08, 0.75);
  glRotatef((GLfloat)jempol1, 0.0, 0.0, 1.0);
  glRotatef((GLfloat)jempol3, 0.0, 1.0, 0.0);
  glTranslatef(0.20, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.4, 0.2, 0.2);
  glutWireCube(1.0);
  glPopMatrix();

  glTranslatef(0.20, 0.0, 0.0);
  glRotatef((GLfloat)jempol2, 0.0, 1.0, 0.0);
  glTranslatef(0.18, 0.0, 0.0);

  glPushMatrix();
  glScalef(0.35, 0.18, 0.18);
  glutWireCube(1.0);
  glPopMatrix();
  glPopMatrix();

  glPopMatrix();
  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 'Q':
    telapak = (telapak - 5) % 360;
    glutPostRedisplay();
    break;
  case 'q':
    telapak = (telapak + 5) % 360;
    glutPostRedisplay();
    break;
  case '1':
    jari1 = (jari1 + 5) % 360;
    glutPostRedisplay();
    break;
  case '!':
    jari12 = (jari12 + 5) % 360;
    glutPostRedisplay();
    break;
  case '2':
    jari2 = (jari2 + 5) % 360;
    glutPostRedisplay();
    break;
  case '@':
    jari22 = (jari22 + 5) % 360;
    glutPostRedisplay();
    break;
  case '3':
    jari3 = (jari3 + 5) % 360;
    glutPostRedisplay();
    break;
  case '#':
    jari32 = (jari32 + 5) % 360;
    glutPostRedisplay();
    break;
  case '4':
    jari4 = (jari4 + 5) % 360;
    glutPostRedisplay();
    break;
  case '$':
    jari42 = (jari42 + 5) % 360;
    glutPostRedisplay();
    break;
  case '5':
    jempol1 = (jempol1 + 5) % 360;
    glutPostRedisplay();
    break;
  case '%':
    jempol2 = (jempol2 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'r':
    jempol3 = (jempol3 - 5) % 360;
    glutPostRedisplay();
    break;
  case 'a':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'd':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 's':
    atas = (atas - 5) % 360;
    glutPostRedisplay();
    break;
  case 'w':
    atas = (atas + 5) % 360;
    glutPostRedisplay();
    break;

  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;

  case 'z':
    atas = -35 % 360;
    elbow = 60 % 360;
    telapak = 60 % 360;
    jari1 = 0 % 360;
    jari12 = 0 % 360;
    jari2 = 60 % 360;
    jari22 = 60 % 360;
    jari3 = 60 % 360;
    jari32 = 60 % 360;
    jari4 = 0 % 360;
    jari42 = 0 % 360;
    jempol1 = 0 % 360;
    jempol2 = 0 % 360;
    jempol3 = -45 % 360;
    glutPostRedisplay();
    break;
  case 'x':
    atas = -35 % 360;
    elbow = 60 % 360;
    telapak = 60 % 360;
    jari1 = 0 % 360;
    jari12 = 0 % 360;
    jari2 = 60 % 360;
    jari22 = 60 % 360;
    jari3 = 60 % 360;
    jari32 = 60 % 360;
    jari4 = 60 % 360;
    jari42 = 60 % 360;
    jempol1 = 0 % 360;
    jempol2 = 0 % 360;
    jempol3 = -45 % 360;
    glutPostRedisplay();
    break;
  case 'c':
    atas = -35 % 360;
    elbow = 60 % 360;
    telapak = 60 % 360;
    jari1 = 60 % 360;
    jari12 = 60 % 360;
    jari2 = 60 % 360;
    jari22 = 60 % 360;
    jari3 = 60 % 360;
    jari32 = 60 % 360;
    jari4 = 60 % 360;
    jari42 = 60 % 360;
    jempol1 = 0 % 360;
    jempol2 = 0 % 360;
    jempol3 = -45 % 360;
    glutPostRedisplay();
    break;
  case 'v':
    atas = -35 % 360;
    elbow = 60 % 360;
    telapak = 60 % 360;
    jari1 = 60 % 360;
    jari12 = 60 % 360;
    jari2 = 0 % 360;
    jari22 = 0 % 360;
    jari3 = 60 % 360;
    jari32 = 60 % 360;
    jari4 = 60 % 360;
    jari42 = 60 % 360;
    jempol1 = 0 % 360;
    jempol2 = 0 % 360;
    jempol3 = -45 % 360;
    glutPostRedisplay();
    break;
  case 'b':
    atas = -35 % 360;
    elbow = 60 % 360;
    telapak = 60 % 360;
    jari1 = 60 % 360;
    jari12 = 60 % 360;
    jari2 = 60 % 360;
    jari22 = 60 % 360;
    jari3 = 60 % 360;
    jari32 = 60 % 360;
    jari4 = 60 % 360;
    jari42 = 60 % 360;
    jempol1 = 60 % 360;
    jempol2 = 60 % 360;
    jempol3 = 0 % 360;
    glutPostRedisplay();
    break;
  case 'n':
    atas = -35 % 360;
    elbow = 60 % 360;
    telapak = 60 % 360;
    jari1 = 0 % 360;
    jari12 = 0 % 360;
    jari2 = 0 % 360;
    jari22 = 0 % 360;
    jari3 = 0 % 360;
    jari32 = 0 % 360;
    jari4 = 0 % 360;
    jari42 = 0 % 360;
    jempol1 = 0 % 360;
    jempol2 = 0 % 360;
    jempol3 = -45 % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(700, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}