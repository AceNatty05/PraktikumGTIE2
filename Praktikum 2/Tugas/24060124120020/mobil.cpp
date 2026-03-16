

#include <GL/glut.h>
#include <cmath>

const int W = 800, H = 500;

float carX       = -(W / 2.0f + 120.0f);
float wheelAngle = 0.0f;
float speed      = 2.5f;
int   direction  = 1;   

void drawRect(float x, float y, float w, float h) {
    float hw = w/2, hh = h/2;
    glBegin(GL_QUADS);
        glVertex2f(x-hw, y-hh); glVertex2f(x+hw, y-hh);
        glVertex2f(x+hw, y+hh); glVertex2f(x-hw, y+hh);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int seg) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= seg; i++) {
            float a = 2.0f * M_PI * i / seg;
            glVertex2f(cx + r*cosf(a), cy + r*sinf(a));
        }
    glEnd();
}

void drawCircleOutline(float cx, float cy, float r, int seg) {
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < seg; i++) {
            float a = 2.0f * M_PI * i / seg;
            glVertex2f(cx + r*cosf(a), cy + r*sinf(a));
        }
    glEnd();
}

// Roda 
void drawWheel(float cx, float cy, float r) {
    glPushMatrix();                        
        glTranslatef(cx, cy, 0);
        glRotatef(wheelAngle, 0, 0, 1);   

        // Ban
        glColor3f(0.15f, 0.15f, 0.15f);
        drawCircle(0, 0, r, 32);

        // Velg
        glColor3f(0.80f, 0.80f, 0.82f);
        drawCircle(0, 0, r * 0.60f, 32);

        // jari -jari
        glColor3f(0.50f, 0.50f, 0.55f);
        glLineWidth(2.0f);
        for (int i = 0; i < 4; i++) {
            float a = M_PI / 2.0f * i;
            glBegin(GL_LINES);
                glVertex2f(0, 0);
                glVertex2f(r*0.57f*cosf(a), r*0.57f*sinf(a));
            glEnd();
        }

        //  tengah
        glColor3f(0.35f, 0.35f, 0.40f);
        drawCircle(0, 0, r * 0.15f, 16);

        // Outline 
        glColor3f(0.05f, 0.05f, 0.05f);
        glLineWidth(1.2f);
        drawCircleOutline(0, 0, r, 32);

    glPopMatrix();                        
}

// Mobil 
void drawCar() {
    glPushMatrix();                        // PUSH 
        glTranslatef(carX, 0, 0);

        if (direction == -1)
            glScalef(-1.0f, 1.0f, 1.0f);

        const float bW = 160.0f, bH = 45.0f, bY = 5.0f;
        const float wR = 24.0f;

        // Bodi bawah
        glColor3f(0.20f, 0.50f, 0.85f);
        drawRect(0, bY + bH/2.0f, bW, bH);

        // Kabin 
        glColor3f(0.28f, 0.55f, 0.90f);
        glBegin(GL_QUADS);
            glVertex2f(-65.0f, bY + bH);
            glVertex2f( 60.0f, bY + bH);
            glVertex2f( 45.0f, bY + bH + 42.0f);
            glVertex2f(-50.0f, bY + bH + 42.0f);
        glEnd();

        // Jendela
        glColor3f(0.70f, 0.88f, 1.00f);
        glBegin(GL_QUADS);
            glVertex2f(-42.0f, bY + bH +  5.0f);
            glVertex2f( 50.0f, bY + bH +  5.0f);
            glVertex2f( 38.0f, bY + bH + 36.0f);
            glVertex2f(-35.0f, bY + bH + 36.0f);
        glEnd();
        glColor3f(0.15f, 0.30f, 0.65f);
        glLineWidth(1.8f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(-42.0f, bY + bH +  5.0f);
            glVertex2f( 50.0f, bY + bH +  5.0f);
            glVertex2f( 38.0f, bY + bH + 36.0f);
            glVertex2f(-35.0f, bY + bH + 36.0f);
        glEnd();

        // Lampu depan
        glColor3f(1.00f, 0.96f, 0.70f);
        drawRect(77.0f, bY + bH - 10.0f, 14.0f, 10.0f);


        // Bumper
        glColor3f(0.30f, 0.30f, 0.35f);
        drawRect( 83.0f, bY + 10.0f, 12.0f, 18.0f);
        drawRect(-83.0f, bY + 10.0f, 12.0f, 18.0f);

        // Knalpot
        glColor3f(0.45f, 0.45f, 0.48f);
        drawRect(-91.0f, bY + 4.0f, 12.0f, 6.0f);

        // Roda depan & belakang
        drawWheel( 52.0f, bY - wR + 6.0f, wR);
        drawWheel(-52.0f, bY - wR + 6.0f, wR);

        // Outline bodi bawah
        glColor3f(0.10f, 0.28f, 0.62f);
        glLineWidth(1.5f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(-bW/2, bY); glVertex2f(bW/2, bY);
            glVertex2f(bW/2, bY+bH); glVertex2f(-bW/2, bY+bH);
        glEnd();

    glPopMatrix();                         // POP 
}

// Backgorund
void drawBackground() {
    // Langit
    glBegin(GL_QUADS);
        glColor3f(0.45f, 0.72f, 1.00f);
        glVertex2f(-W/2.0f, H/2.0f); glVertex2f(W/2.0f, H/2.0f);
        glColor3f(0.78f, 0.91f, 1.00f);
        glVertex2f(W/2.0f, -15.0f);  glVertex2f(-W/2.0f, -15.0f);
    glEnd();

    // Matahari
    glColor3f(1.00f, 0.90f, 0.25f);
    drawCircle(W/2.0f - 70.0f, H/2.0f - 55.0f, 38.0f, 36);

    // Rumput
    glColor3f(0.32f, 0.62f, 0.22f);
    drawRect(0, -25.0f, (float)W, 20.0f);

    // Jalan
    glColor3f(0.38f, 0.38f, 0.40f);
    drawRect(0, -105.0f, (float)W, 160.0f);

    // Bahu jalan
    glColor3f(0.85f, 0.76f, 0.18f);
    drawRect(0, -35.0f,  (float)W, 5.0f);
    drawRect(0, -170.0f, (float)W, 5.0f);

    // Marka putus-putus
    glColor3f(0.95f, 0.95f, 0.95f);
    float mx = -W/2.0f;
    while (mx < W/2.0f) {
        drawRect(mx + 25.0f, -103.0f, 50.0f, 7.0f);
        mx += 85.0f;
    }
}

// Timer loop
void timer(int) {
    float boundary = W/2.0f + 120.0f;
    float circ = 2.0f * M_PI * 24.0f;

    carX += speed * direction;
    // roda berputar sesuai arah jalan
    wheelAngle -= (speed / circ) * 360.0f * direction;

    if (carX >  boundary) { direction = -1; }
    if (carX < -boundary) { direction =  1; }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawBackground();
    drawCar();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-W/2.0f, W/2.0f, -H/2.0f, H/2.0f, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil ");

    glClearColor(0.50f, 0.76f, 1.00f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
