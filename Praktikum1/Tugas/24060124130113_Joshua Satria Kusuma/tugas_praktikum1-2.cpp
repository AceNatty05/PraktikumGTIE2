// Nama	: Joshua Satria Kusuma
// NIM		: 24060124130113
// labs	: E2

#include <GL/glut.h> 

void border(){
	glLineWidth(5.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
		glVertex3f( -0.9f, -0.9f, 0.0f);
		glVertex3f( 0.9f, -0.9f, 0.0f);
		glVertex3f( 0.9f, 0.9f, 0.0f);
		glVertex3f( -0.9f, 0.9f, 0.0f);
	glEnd(); 

}

void sky(){
    glBegin(GL_QUADS);

        glColor3f(0.2, 0.0, 0.4);
        glVertex2f(-0.9, 0.9);
        glVertex2f(0.9, 0.9);

        glColor3f(1.0, 0.4, 0.0);
        glVertex2f(0.9, 0.0);
        glVertex2f(-0.9, 0.0);
    glEnd();
}

void mount(){
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.4f, 0.4f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);

		glColor3f(0.4f, 0.4f, 1.0f);
		glVertex3f(-0.9f, 0.0f, 0.0f);

		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(-0.45f, 0.89f, 0.0f);

		glColor3f(0.4f, 0.4f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);

		glColor3f(0.4f, 0.4f, 1.0f);
		glVertex3f(0.9f, 0.0f, 0.0f);

		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(0.45f, 0.89f, 0.0f);

	glEnd();

}

void field(){
	glBegin(GL_QUADS);
		// grass
		glColor3f(0.0f , 1.0f, 0.2f);
		glVertex2f(0.1f, 0.0f);

		glColor3f(0.0f , 1.0f, 0.2f);
		glVertex2f(0.9f, 0.0f);

		glColor3f(0.0f , 1.0f, 0.2f);
		glVertex2f(0.9f, -0.9f);

		glColor3f(0.0f , 1.0f, 0.2f);
		glVertex2f(0.1f, -0.9f);

		// dirt
		glColor3f(0.7f , 0.6f, 0.2f);
		glVertex2f(-0.9f, 0.0f);

		glColor3f(0.7f , 0.6f, 0.2f);
		glVertex2f(-0.1f, 0.0f);

		glColor3f(0.7f , 0.6f, 0.2f);
		glVertex2f(-0.1f, -0.9f);

		glColor3f(0.7f , 0.6f, 0.2f);
		glVertex2f(-0.9f, -0.9f);

		//mainroad
		glColor3f(0.0f , 0.0f, 0.0f);
		glVertex2f(-0.1f, 0.0f);

		glColor3f(0.0f , 0.0f, 0.0f);
		glVertex2f(0.1f, 0.0f);

		glColor3f(0.0f , 0.0f, 0.0f);
		glVertex2f(0.1f, -0.9f);

		glColor3f(0.0f , 0.0f, 0.0f);
		glVertex2f(-0.1f, -0.9f);
	glEnd();

}

void roadline(){
	glLineWidth(2.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
		glVertex2f(-0.09, -0.9);
		glVertex2f(-0.09, 0.0);
		glVertex2f(0.09, 0.0);
		glVertex2f(0.09, -0.9);
		glVertex2f(0.09, 0.0);
		glVertex2f(0.9f, 0.0f);
		glVertex2f(-0.9f, 0.0f);
	glEnd();

}

void midroadline(){
	glLineWidth(2.0f);
	glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, -0.1f);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, -0.2f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, -0.3f);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, -0.4f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, -0.5f);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, -0.6f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, -0.7f);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, -0.8f);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, -0.9f);
	glEnd();

}

void sun() {
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 0.3f);
        glVertex2f(0.0f, 0.0f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(-0.25f, 0.15f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(-0.2f, 0.28f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(-0.1f, 0.36f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(0.0f, 0.38f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(0.1f, 0.36f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(0.2f, 0.28f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(0.25f, 0.15f);

    glEnd();
}

void house(){
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.55f, 0.27f, 0.07f); 

        glVertex2f(-0.75f, -0.2f);
        glVertex2f(-0.75f, -0.6f);

        glColor3f(0.35f, 0.20f, 0.07f); 
        glVertex2f(-0.35f, -0.2f);
        glVertex2f(-0.35f, -0.6f);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.6f, 0.1f, 0.1f);

        glVertex2f(-0.8f, -0.2f); 

        glVertex2f(-0.55f, 0.05f);

        glVertex2f(-0.3f, -0.2f);  
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.2f, 0.1f, 0.0f); 

        glVertex2f(-0.6f, -0.6f);
        glVertex2f(-0.5f, -0.6f);
        glVertex2f(-0.5f, -0.4f);
        glVertex2f(-0.6f, -0.4f);
    glEnd();



    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 1.0f);

        glVertex2f(-0.7f, -0.35f);
        glVertex2f(-0.62f, -0.35f);
        glVertex2f(-0.62f, -0.28f);
        glVertex2f(-0.7f, -0.28f);
    glEnd();
}

void display(){
	glClear (GL_COLOR_BUFFER_BIT);

	sky();
	sun();
	mount();
	field();
	roadline();
	midroadline();
	house();

	border();

    glFlush();
}

int main(int argc, char* argv[]) { 
 
	glutInit(&argc, argv);
	glutInitWindowSize (640,640);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("The Classic");
	glutDisplayFunc (display);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
	glutMainLoop();
	return 0;
}