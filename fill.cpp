#include<stdio.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

int option=1;
struct point
{
	int x;
	int y;
};

struct Color
{
	float r,g,b;
};

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

Color getPixelColor(int x,int y)
{
	Color color;
	glReadPixels(x,y,1,1,GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(int x,int y,Color color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void floodfill(int x,int y,Color oldcolor, Color newcolor)
{
	Color color;
	color=getPixelColor(x,y);
	
	if(color.r == oldcolor.r && color.g==oldcolor.g && color.b == oldcolor.b)
	{
		setPixelColor(x,y,newcolor);
		floodfill(x+1, y, oldcolor, newcolor);
		floodfill(x, y+1, oldcolor, newcolor);
		floodfill(x-1, y, oldcolor, newcolor);
		floodfill(x, y-1, oldcolor, newcolor);
		floodfill(x+1, y+1, oldcolor, newcolor);
		floodfill(x+1, y-1, oldcolor, newcolor);
		floodfill(x-1, y-1, oldcolor, newcolor);
		floodfill(x-1, y-1, oldcolor, newcolor);
	}
	return;
}

void boundaryfill(int x,int y, Color fcolor, Color bcolor)
{
	Color color;
	color= getPixelColor(x,y);
	if((color.r != fcolor.r || color.g != fcolor.g || color.b != fcolor.b) && (color.r != bcolor.r || color.g != bcolor.g ||color.b != bcolor.b))
	{
		setPixelColor(x,y,fcolor);
		boundaryfill(x+1, y, fcolor, bcolor);
		boundaryfill(x, y+1, fcolor, bcolor);
		boundaryfill(x-1, y, fcolor, bcolor);
		boundaryfill(x, y-1, fcolor, bcolor);
	}
	return;
}

void OnMouseClick(int button, int state, int x,int y)
{
	Color newColor ={0.0f, 0.0f, 1.0f};
	Color oldColor ={0.0f, 0.0f, 0.0f};
	Color bColor ={1.0f ,1.0f, 1.0f};
	Color fColor ={0.0f ,0.0f, 1.0f};
	
	if(option ==1)
		floodfill(x, 500-y, oldColor, newColor);
	else
		boundaryfill(x, 500-y, fColor, bColor);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2i(250,250);
	glVertex2i(250,300);
	glVertex2i(300,300);
	glVertex2i(300,250);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	cout<<"1.FLOODFILL"<<endl;
	cout<<"2.BOUNDARYFILL"<<endl;
	cout<<"ENTER OPTION:";
	cin>>option;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("POLYGON FILLING");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(OnMouseClick);
	glutMainLoop();
	return 0;
}
