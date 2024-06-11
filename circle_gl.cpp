#include<stdio.h>
#include<math.h>
#include<GL/glut.h>


int xc, yc,r;

void plot(int x , int y){
	glColor3d(1,0,1);
	glBegin(GL_POINTS);
	glVertex2d(xc+x,yc+y);
	glVertex2d(xc+x,yc-y);
	glVertex2d(xc-x,yc-y);
	glVertex2d(xc-x,yc+y);
	glVertex2d(yc+y,xc+x);
	glVertex2d(yc-y,xc+x);
	glVertex2d(yc-y,xc-x);
	glVertex2d(yc+y,xc-x);
	glEnd();
	
		
}

void bres_circle(int r){

	int x = 0;
	int y = r;
	int s=3-2*r;
	plot(x,y);
	while(x<y){
	
	x=x+1;
	if(s<0){
	s=s+2*x+1;}
	else{
	
	s=s+2*(x-y)+1;
	}
	}
	glFlush();


}


void circle(){

	glClear(GL_COLOR_BUFFER_BIT);
	bres_circle(r);
	
}

void init()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);
	gluOrtho2D(0,640,0,480);

}
int main(int argc,char **argv) {                   

printf("enter the radius");
scanf("%d",&xc);
printf("enter coordinates of centre:");
	scanf("%d %d" , &xc, &yc);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("BRES_CIRCLE");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	init();
	glutDisplayFunc(circle);
	glutMainLoop();                        




return 0;
}
