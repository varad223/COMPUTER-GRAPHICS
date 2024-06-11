#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

double x1,y1,x2,y2;
  
  
  void plot(int x, int y)
  {
  
  glBegin(GL_POINTS);
  glColor3f(1.0,0.0,1.0);
 		glVertex2d(x,y);
  glEnd();
  }
void LINE(float x1, float y1, float x2, float y2)
{
	double dx=x2-x1;
	double dy=y2-y1;
	float xinc,yinc,x=x1,y=y1;
	
 	if(dx<0)
 	{
 		dx=-dx;
 	}
 	if(dy<0)
 	{
 		dy=-dy;
 	}
 	incx=1;
 	incy=1;
 	
 	if(x2<x1)
 	{
 		incx=-1;
 	}
 	if(y2<x1)
 	{
 		incy=-1;
 	}
 	
 	x=x1;
 	y=y1;
 	
 	if(dx>dy || dy<dx )
 	{
 		
 	plot(x,y);
 		g=2dy-dx;
 		inc1=2(dy-dx);
 		inc2=2dy;
 	}
 	
 	for(int i=0;i<dx;i++)
 	{
 		if(g>=0)
 		{
 			g=g+inc1;
 			x=x+incx;
 			y=y+incy;
 		}
 		else
 		{
 			g=g+inc2;
 			x=x+incx;
 		}
 		plot(x,y);
 	}
 	
 	for(int i=0;i<dy;i++)
 	{
 		if(g>=0)
 		{
 			g=g+inc1;
 			x=x+incx;
 			y=y+incy;
 			}
 		else
 		{
 			g=g+inc2;
 			x=x+incx;
 		}
 		plot(x,y);
 	}
 	
 	
 	glFlush();
 }
 
void Init()
{
	glClearColor3f(0.0,0.0,0.0,1);
	glColor3f(1.0,0.0,0.0);
	gluOrtho2D(0,640,0,480);
}
 void disp()
 {
 
 LINE(X1,Y1,X2,Y2);
 

}
int main(int argc,char **argv)
{
	printf("enter two end points of the line");
	printf("\n");
	printf("\nenter point1 (X1,Y1)");
	scanf("%lf",&X1);
	printf("\nenter point1 (X1,Y1)");
	scanf("%lf",&Y1);
	printf("\nenter point1 (X1,Y1)");
	scanf("%lf",&X2);
	printf("\nenter point1 (X1,Y1)");
	scanf("%lf",&Y2);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("DDA Line");
	Init();
	glitDisplayFunc(LINE);
	glutMainLoop();
	return 0;
}
