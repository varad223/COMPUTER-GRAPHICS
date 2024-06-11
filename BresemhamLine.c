#include<iostream>
#include<gl/glut.h>
using namespace std;
int X1, Y1, X2, Y2;
void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(1.0, 0, 0);
	gluOrtho2D(-500, 500, -500, 500);
}
void plot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}
void draw_line(int X1, int Y1, int X2, int Y2) {
	int dx, dy, Xinc, Yinc, inc1, inc2, G,x,y;
	dx = X2 - X1;
	dy = Y2 - Y1;
	Xinc = 1;
	Yinc = 1;
	if (X1 > X2)
		Xinc = -1;
	if(Y1>Y2)
		Yinc = -1;
	x = X1;
	y = Y1;
	if (dx > dy) {
		plot(x, y);
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		G = 2 * dy - dx;
		for(int i = 0; i < dx; i++ ){
			if (G > 0) {
				y += Yinc;
				G = G + inc1;
			}
			else {
				G = G + inc2;
			}
			x += Xinc;
			plot(x, y);
		}
	}
	else //dx<dy
	{
		plot(x, y);
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		G = 2 * dy - dx;
		for (int i = 0; i < dy; i++) {
			if (G > 0) {
				y += Yinc;
				G = G + inc1;
			}
			else {
				G = G + inc2;
			}
			x += Xinc;
			plot(x, y);
		}
	}
}
void myDisplay() {
	draw_line(X1, Y1, X2, Y2);
	glFlush();
}
void main(int argc, char** argv) {

	cout<<"Enter (x1, y1, x2, y2)\n";
	cin>>X1>>Y1>>X2>>Y2;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
