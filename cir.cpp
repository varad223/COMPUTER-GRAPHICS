#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int Xc,Yc,r;

void plot (int x,int y)
{
	 glColor3d(1,0,1);
	 glBegin(GL_POINTS);
	 glVertex2d(Xc+x ,Yc+y);
	 glVertex2d(Xc+x ,Yc-y);
	 glVertex2d(Xc-x ,Yc-y);
	 glVertex2d(Xc-x ,Yc+y);
	 glVertex2d(Xc+y ,Yc+x);
	 glVertex2d(Xc+y ,Yc-x);
	 glVertex2d(Xc-y ,Yc-x);
	 glVertex2d(Xc-y ,Yc+x);
	 glEnd();
}
	
void bres_circle(int r)
{
	int x=0,y=r;
	int S=3-2*r;
	plot(x,y);
	
	while(x<y)
	{
		x+=1;
		if(S<0)
		{
			S=S+2*x+1;
		}
		else
		{
			S=S+2*(x-y)+1;
			y=y-1 ;
		}
		plot(x,y);
	}
	glFlush();
}

void circle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	bres_circle(r);
}

void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	//glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,640,0,480);
}

int main(int argc,char **argv)
{
	printf("enter radius of circle:");
	scanf("%d" , &r);
	printf("enter coordinates of centre:");
	scanf("%d %d" , &Xc, &Yc);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("BRES_CIRCLE");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	init();
	glutDisplayFunc(circle);
	glutMainLoop();
	
	return 0;
}
