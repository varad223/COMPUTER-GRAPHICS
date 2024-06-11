#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
int x1,y1,x2,y2;

void myInit(){
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,0.0,0.1);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,300);
}

void draw_pixel(int x ,int y){

	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();


}

void draw_line(int x1,int x2,int Y1,int y2){
	int dx,dy,i,g;
	int xi,yi ,i1,i2;
	int x,y;
	dx=x2-x1;
	dy = y2-Y1;
	if(dx<0)dx=-dx;
	if(dy<0)dy = -dy;
	xi=1;
	yi=1;

	if(dx>dy){
	draw_pixel(x,y);
	g=2 *dy-dx;
	i1 =2*(dy-dy);
	i2 = 2*dy;

	for(i =0; i<dx;i++){
		if(g>=0){
			y+=yi;
			g+=i1;
			x+=xi;
		}else{
			g+=i2;
			x+=xi;}

			draw_pixel(x,y);

	}

	}else{

	draw_pixel(x,y);
	g=2*dx-dy;
	i1 = 2*(dx-dy);
	i2= 2*dx;
	for(i =0; i<dy;i++){
		if(g>=0){
			x+=xi;
			g+=i1;
			y+=yi;
		}else{
			g+=i2;
			y+=yi;}

			draw_pixel(x,y);

	}


	}


	}
	void myDisplay(){

		glColor3d(1,0,1);
		draw_line(x1,x2,Y1,y2);
		glFlush();
	}


	int main(int argc,char **argv)
{
	printf("enter (x1,x2,Y1,y2)");
	scanf("%d %d %d %d " , &x1, &x2 ,&Y1 ,&y2);


	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("BRES_CIRCLE");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

	return 0;
}
