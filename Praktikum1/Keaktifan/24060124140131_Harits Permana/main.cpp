#include <gl/glut.h>

void kotak(double x1, double y1, double x2, double y2){
	glRectf(x1,y1,x2,y2);
	glFlush();
}

void bertingkat(){
    kotak(-0.9, -0.4, -0.5, -0.1);
    kotak(-0.2, -0.4,  0.2, -0.1);
    kotak( 0.5, -0.4,  0.9, -0.1);
    kotak(-0.55, 0.1, -0.15, 0.4); 
    kotak( 0.15,  0.1,  0.55, 0.4);
}

int main(int argc,char* argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize (640,480);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Segiempat bertingkat");
	glutDisplayFunc(bertingkat);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
