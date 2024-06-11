#include<iostream>
#include<math.h>
#include<GL/glut.h>

using namespace std;
int v;
int xtemp[10];
int ytemp[10];
int x[10],y[10];

void init()
{
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.101, 1.0, 0.980, 1.0);
	gluOrtho2D(-500,500,-500,500);
}
void display()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,750);
	glutCreateWindow("2D Transformation");
	init();
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(int i=0;i<v;i++)
		glVertex2f(x[i],y[i]);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	for(int i=0;i<v;i++)
		glVertex2f(xtemp[i],ytemp[i]);
	glEnd();
	
	glFlush();
	glutMainLoop();
}

void translation()
{
	cout<<"Translation\n";
	int dx,dy;
	cout<<"Enter translating factor\n";
	cin>>dx>>dy;
	for(int i;i<v;i++)
	{
	xtemp[i]=xtemp[i]+dx;
	ytemp[i]=ytemp[i]+dy;
	}
	display();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	
	cout<<"BEFORE TRANSFORMATION COLOUR: BLACK\n";
	cout<<"AFTER TRANSFORMATION COLOUR: RED\n";
	cout<<"Range of x and y is -500 to 500\n\n";
	cout<<"Enter the no of vertices of polygon: ";
	cin>>v;
	cout<<"enter the coordinates incloclwise/anticloclkwise order: \n";
	
	for(int i=0; i<v; i++)
	{
		cout<<"\nvertex-"<<i+1<<" ";
		cin>>x[i]>>y[i];
		xtemp[i]=x[i];
		ytemp[i]=y[i];
	}
	translation();
}
