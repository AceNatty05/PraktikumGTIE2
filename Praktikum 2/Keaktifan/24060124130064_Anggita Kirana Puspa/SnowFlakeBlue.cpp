#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>
// Nama: Anggita Kirana Puspa
// NIM: 24060124130064
// Lab: E2

void dasar4(){
	glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0f);
    glColor3f(0.3725f, 0.6627f, 0.8980f);
    
    float sudut[4] = {0, 90, 45, 135};
   
   for(int i = 0; i < 4; i++){
   	glPushMatrix();
   	glRotatef(sudut[i], 0.0f, 0.0f, 1.0f);
   	
   	glBegin(GL_LINES);
   		glVertex3f(-0.8f, 0.0f, 0.0f);
        glVertex3f(0.8f, 0.0f, 0.0f);
    glEnd();
    
    glPopMatrix();
   }
	
    glFlush();
}

void satuCabang(){
	glLineWidth(4.0f);
    glColor3f(0.3725f, 0.6627f, 0.8980f);
    
    glBegin(GL_LINES);
    
    	// garis 1
    	glVertex3f(-0.2f, 0.8f, 0.0f);
   		glVertex3f( 0.0f, 0.6f, 0.0f);
    
    	// garis 2
    	glVertex3f(0.0f, 0.6f, 0.0f);
    	glVertex3f(0.2f, 0.8f, 0.0f);
    
    	// garis 3
    	glVertex3f(-0.2f, 0.6f, 0.0f);
   		glVertex3f( 0.0f, 0.4f, 0.0f);
    
    	// garis 4
    	glVertex3f(0.0f, 0.4f, 0.0f);
    	glVertex3f(0.2f, 0.6f, 0.0f);
    
    glEnd();
}

void gambarCabang(){
	glLineWidth(4.0f);
    glColor3f(0.3725f, 0.6627f, 0.8980f);
    
    float sudut[9] = {0, 45, 90, 135, 180, 225, 270, 315, 360};
    
    for(int i = 0; i < 8; i++){
    	glPushMatrix();
   		glRotatef(sudut[i], 0.0f, 0.0f, 1.0f);
   		
   		satuCabang();
   		
   		glPopMatrix();
    }
    glFlush();
}

void satuMotif(){
	glLineWidth(4.0f);
    glColor3f(0.3725f, 0.6627f, 0.8980f);
    
    glBegin(GL_LINES);
    	glVertex3f(-0.3f, 0.0f, 0.0f);
    	glVertex3f(-0.47f, 0.2f, 0.0f);
    	
    	glVertex3f(-0.47f, 0.2f, 0.0f);
    	glVertex3f(-0.2f, 0.22f, 0.0f);
    	
    glEnd();
}

void gambarMotif(){
	glLineWidth(4.0f);
    glColor3f(0.3725f, 0.6627f, 0.8980f);
    
    float sudut[9] = {0, 45, 90, 135, 180, 225, 270, 315, 360};
    
    for(int i = 0; i < 8; i++){
    	glPushMatrix();
   		glRotatef(sudut[i], 0.0f, 0.0f, 1.0f);
   		
   		satuMotif();
   		
   		glPopMatrix();
    }
    glFlush();
}

void display(){
	dasar4();
	gambarCabang();
	gambarMotif();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("SnowFlake");
    glutDisplayFunc(display);
    glClearColor(0.8706f, 0.9294f, 0.9804f, 1.0f);
    glutMainLoop();
}
