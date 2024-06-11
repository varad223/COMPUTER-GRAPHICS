#include<GL/glut.h>

void display(){
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(-0.5f,0.5f);
	glVertex2f(-1.0f,0.5f);
	glVertex2f(-0.5f,1.0f);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0.5f,0.5f);
	glVertex2f(1.0f,0.5f);
	glVertex2f(0.5f,1.0f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(0.3f,-0.3f);
	glVertex2f(0.5f,-0.5f);
	glVertex2f(0.3f,-0.7f);
	glVertex2f(-0.3f,-0.7f);
	glVertex2f(-0.3f,-0.3f);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(-0.4f,0.0f);
	glVertex2f(0.4f,0.0f);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(-0.4f,0.0f);
	glVertex2f(-0.56,-0.56);
	glVertex2f(-0.48,0.48);
	glEnd();
	
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(-0.23,0.23);
	glVertex2f(-0.23,-0.23);
	glVertex2f(-0.16,-0.16);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(0.0,0.0);
	glVertex2f(-0.45,0.40);
	glVertex2f(-0.6,0.6);
	glEnd();
	
	
	
	glFlush();
}
int main(int argc,char **argv){
	
	glutInit(&argc,argv);
	
	glutCreateWindow("OpenGL Sample Program");
	glutInitWindowSize(320,320);
	glutInitWindowPosition(50,50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
