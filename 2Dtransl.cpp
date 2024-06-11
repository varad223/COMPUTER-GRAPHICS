#include<stdio.h>
#include<math.h>
#include<GL/freeglut.h>
#include<math.h>
#define MAX 10

int vertices, x[MAX], y[MAX];
int i, xtemp[MAX], ytemp[MAX];

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
	glutCreateWindow("20 Transformation");
	init();
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	for(i=0;i<vertices;i++)
		glVertex2f(x[i],y[i]);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	for(i=0;i<vertices;i++)
		glVertex2f(xtemp[i],ytemp[i]);
	glEnd();
	
	glFlush();
	glutMainLoop();
}

void translation()
{
	printf("\n\nTRANSALTION");
	int dx,dy;
	printf("enter translation factor (dx,dy) :");
	scanf("%d%d", &dx, &dy);
	for(i=0;  i<vertices; i++)
	{
		xtemp[i]= xtemp[i]+dx;
		ytemp[i]= ytemp[i]+dy;
	}
	display();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	
	printf("BEFORE TRANSFORMATION COLOUR: BLACK\n");
	printf("AFTER TRANSFORMATION COLOUR: RED\n");
	printf("Range of x and y is -500 to 500\n\n");
	printf("Enter the no of vertices of polygon: ");
	scanf("%d", &vertices);
	printf("enter the coordinates incloclwise/anticloclkwise order: \n");
	
	for(i=0; i<vertices; i++)
	{
		printf("vertex- %d:", 
		i+1);
		scanf("%d%d", &x[i],&y[i]);
		xtemp[i]=x[i];
		ytemp[i]=y[i];
	}
	
	printf("\n\n 2D TRANSFORMATION\n\n");
	printf("1.translation\n Enter your choice:");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			translation();
			break;
	}
	
	return 0;
}
	
	
