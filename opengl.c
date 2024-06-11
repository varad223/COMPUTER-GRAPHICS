#include<GL/glut.h>
void display()
{
//glBegin(GL_TRIANGLES);
glBegin(GL_QUADS);
glColor3f(0.0f,1.0f,1.0f);
glVertex2f(-0.5f,-0.5f);
glVertex2f(0.5f,-0.5f);
glVertex2f(0.5f,0.5f);
glVertex2f(-0.5f,0.5f);
glEnd();
glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("OpenGL Program");
	glutInitWindowSize(320,320);
	glutInitWindowPosition(50,50);
	glutDisplayFunc(display);
	glutMainLoop();
	
return 0;
}

