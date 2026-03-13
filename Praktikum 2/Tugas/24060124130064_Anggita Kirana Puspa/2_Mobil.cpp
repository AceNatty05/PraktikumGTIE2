#include <GL/glut.h>
#include <math.h>

// Nama: Anggita Kirana Puspa
// NIM: 24060124130064
// Lab: E2

// Kamus Lokal
float carX = 0.0f;
float wheelRotation = 0.0f;
// permukaan jalan
float roadTop = -0.22f;
float roadBottom = -0.65f;

// Algoritma
void drawCircle(float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    static double PI = 3.1415926f;
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void drawWheel() {
   	glColor3f(0.1f, 0.1f, 0.1f);
	drawCircle(0.07f, 100);

    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(0.04f, 100);

    glBegin(GL_LINES);
        glVertex2f(-0.04f, 0.0f);
        glVertex2f( 0.04f, 0.0f);

        glVertex2f(0.0f, -0.04f);
        glVertex2f(0.0f,  0.04f);

        glVertex2f(-0.028f, -0.028f);
        glVertex2f( 0.028f,  0.028f);

        glVertex2f(-0.028f,  0.028f);
        glVertex2f( 0.028f, -0.028f);
    glEnd();
}

void drawRoad() {
   glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, roadTop);
        glVertex2f( 1.0f, roadTop);
        glVertex2f( 1.0f, roadBottom);
        glVertex2f(-1.0f, roadBottom);
    glEnd();

    glLineWidth(4.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f(-1.0f, roadTop);
        glVertex2f( 1.0f, roadTop);
    glEnd();
	
	// Garis putus-putus di tengah jalan
    float midY = (roadTop + roadBottom) / 2.0f;

    for (float x = -1.0f; x < 1.0f; x += 0.18f) {
        glBegin(GL_LINES);
            glVertex2f(x, midY);
            glVertex2f(x + 0.09f, midY);
        glEnd();
    }
}

// Gambar Langit
void drawSky(){
	glColor3f(0.255f, 0.784f, 0.875f);
	glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.22f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f( 1.0f, 1.0f);
        glVertex2f(1.0f, -0.22f);
    glEnd();
}

// Gambar Rumput
void drawGrass(){
    glColor3f(0.2f, 0.7f, 0.2f); 

    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.65f);
        glVertex2f(-1.0f, -0.65f);
    glEnd();
}

// Gambar Detail Rumput
void drawGrassDetail(){
    glColor3f(0.1f, 0.6f, 0.1f);

    for(float x = -1.0f; x < 1.0f; x += 0.05f){
        glBegin(GL_TRIANGLES);
            glVertex2f(x, -0.65f);
            glVertex2f(x + 0.02f, -0.60f);
            glVertex2f(x + 0.04f, -0.65f);
        glEnd();
    }
}

// Gambar Setengah Lingkaran
void drawHalfCircle(float cx, float cy, float r){
    int segments = 100;

    glBegin(GL_LINE_STRIP);
    for(int i = 0; i <= segments; i++){
        float angle = 3.1415926f * i / segments;
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Memberi isian setengah lingkaran
void fillHalfCircle(float cx, float cy, float r) {
    int segments = 100;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy); 

        for (int i = 0; i <= segments; i++) {
            float angle = 3.1415926f * i / segments;
            float x = cx + r * cos(angle);
            float y = cy + r * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
}

// Membuat badan mobil
void drawCarBody() {
    // Body mobil
    glColor3f(0.969f, 0.800f, 0.388f);
	glBegin(GL_POLYGON);
    	glVertex2f(-0.63f, -0.23f);
        glVertex2f(-0.75f, -0.23f); 
        glVertex2f(-0.75f, 0.2f); 
		glVertex2f(-0.2f, 0.2f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, -0.23f);
		glVertex2f(-0.1f, -0.23f);
	glEnd();
	
	glColor3f(0.35f, 0.35f, 0.35f); 
    fillHalfCircle(-0.53f, -0.23f, 0.10f);
    fillHalfCircle(-0.20f, -0.23f, 0.10f);
    
    // Kerangka body mobil
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
    	glVertex2f(-0.63f, -0.23f);
        glVertex2f(-0.75f, -0.23f); 
        glVertex2f(-0.75f, 0.2f); 
		glVertex2f(-0.2f, 0.2f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, -0.23f);
		glVertex2f(-0.1f, -0.23f);	
    glEnd();
    
    glBegin(GL_LINES);
    	glVertex2f(-0.3f, -0.23f);
    	glVertex2f(-0.43f, -0.23f);
	glEnd();
	
	// Roda kiri
    drawHalfCircle(-0.53f, -0.23f, 0.10f);

    // Roda kanan
    drawHalfCircle(-0.20f, -0.23f, 0.10f);
	
	
	// Jendela 1
	glColor3f(0.643f, 0.929f, 0.776f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.70f,  0.00f);
        glVertex2f(-0.70f,  0.15f);
        glVertex2f(-0.55f,  0.15f);
        glVertex2f(-0.55f,  0.00f);
    glEnd();
    
    // Outline Jendela 1
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.70f,  0.00f);
        glVertex2f(-0.70f,  0.15f);
        glVertex2f(-0.55f,  0.15f);
        glVertex2f(-0.55f,  0.00f);
        glVertex2f(-0.70f,  0.00f);
    glEnd();

	// Jendela 2
	glColor3f(0.643f, 0.929f, 0.776f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.50f,  0.00f);
        glVertex2f(-0.50f,  0.15f);
        glVertex2f(-0.35f,  0.15f);
        glVertex2f(-0.35f,  0.00f);
    glEnd();
    
    // Outline Jendela 2
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.50f,  0.00f);
        glVertex2f(-0.50f,  0.15f);
        glVertex2f(-0.35f,  0.15f);
        glVertex2f(-0.35f,  0.00f);
        glVertex2f(-0.50f,  0.00f);
    glEnd();
    
	// Jendela 3
	glColor3f(0.643f, 0.929f, 0.776f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.30f,  0.00f);
        glVertex2f(-0.30f,  0.15f);
        glVertex2f(-0.20f,  0.15f);
        glVertex2f(-0.05f,  0.00f);
    glEnd();
    
    // Outline Jendela 3
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.30f,  0.00f);
        glVertex2f(-0.30f,  0.15f);
        glVertex2f(-0.20f,  0.15f);
        glVertex2f(-0.05f,  0.00f);
        glVertex2f(-0.30f,  0.00f);
    glEnd();

	// Sen
	glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.75f,  -0.05f);
        glVertex2f(-0.70f,  -0.05f);
        glVertex2f(-0.70f,  -0.15f);
        glVertex2f(-0.75f,  -0.15f);
    glEnd();
    
    // Outline Sen
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.75f,  -0.05f);
        glVertex2f(-0.70f,  -0.05f);
        glVertex2f(-0.70f,  -0.15f);
        glVertex2f(-0.75f,  -0.15f);
        glVertex2f(-0.75f,  -0.05f);
    glEnd();
    
    // Pintu 1
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    	glVertex2f(-0.52f,  -0.05f);
    	glVertex2f(-0.52f,  -0.12f);
    glEnd();
    
    // Pintu 2
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    	glVertex2f(-0.32f,  -0.05f);
    	glVertex2f(-0.32f,  -0.12f);
    glEnd();
    
    // Pintu 3
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    	glVertex2f(-0.28f,  -0.05f);
    	glVertex2f(-0.26f,  -0.05f);
    glEnd();
    
    // Bumper Belakang
    glColor3f(0.427f, 0.404f, 0.376f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.77f,  -0.23f);
        glVertex2f(-0.77f,  -0.28f);
        glVertex2f(-0.63f,  -0.28f);
        glVertex2f(-0.63f,  -0.23f);
    glEnd();
    
    //Outline Bumper Belakang
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    	glVertex2f(-0.77f,  -0.23f);
        glVertex2f(-0.77f,  -0.28f);
        glVertex2f(-0.63f,  -0.28f);
        glVertex2f(-0.63f,  -0.23f);
        glVertex2f(-0.77f,  -0.23f);
    glEnd();
    
    // Bumper Depan
    glColor3f(0.427f, 0.404f, 0.376f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.103f,  -0.23f);
        glVertex2f(-0.103f,  -0.28f);
        glVertex2f(0.02f,  -0.28f);
        glVertex2f(0.02f,  -0.23f);
    glEnd();
    
    //Outline Bumper Depan
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.103f,  -0.23f);
        glVertex2f(-0.103f,  -0.28f);
        glVertex2f(0.02f,  -0.28f);
        glVertex2f(0.02f,  -0.23f);
        glVertex2f(-0.103f,  -0.23f);
    glEnd();
}

void drawCar() {
	// Stack + Translasi Mobil
    glPushMatrix();
        glTranslatef(carX, -0.03f, 0.0f);

        drawCarBody();
        
        // Stack + Rotasi Roda
        glPushMatrix();
            glTranslatef(-0.53f, -0.25f, 0.0f);
            glRotatef(wheelRotation, 0.0f, 0.0f, 1.0f);
            drawWheel();
        glPopMatrix();
		
		// Stack +  Translasi Roda
        glPushMatrix();
            glTranslatef(-0.20f, -0.25f, 0.0f);
            glRotatef(wheelRotation, 0.0f, 0.0f, 1.0f);
            drawWheel();
        glPopMatrix();
    glPopMatrix();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
	
    drawRoad();
    drawSky();
    drawCar();
	drawGrass();
	drawGrassDetail();
    glFlush();
}

// Update posisi mobil
void update(int value) {
    carX += 0.003f;
    wheelRotation -= 5.0f;

    if (carX > 1.8f) {
        carX = -1.2f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(0.85f, 0.85f, 0.85f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 2D");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
