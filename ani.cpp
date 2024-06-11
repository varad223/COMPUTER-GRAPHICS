#include<GL/glut.h>  // header  files
#include <math.h>
struct Point // structure of point
{
	int x;  // initializing x &y
	int y;
};
void draw_dda(Point p1, Point p2)  // function for draw dda
{
	float dx = p2.x - p1.x; // using formulae
	float dy = p2.y - p1.y;
	float x1 = p1.x;
	float y1 = p1.y;
	float step = 0;  
	step=(abs(dx)>abs(dy))?abs(dx):abs(dy);
	float xInc = dx/step;   // steps for incrementing value of x and y
	float yInc = dy/step;
	for(float i = 1; i <= step; i++) // checking conditions
	{
		glVertex2i(x1, y1);   //check point for vertex
		x1 += xInc;    // incrementing values
		y1 += yInc;
	}
}
void init() // initialization function
 {
	glClearColor(1.0, 1.0, 1.0, 0.0);  // set color to black
	glColor3f(0.0f, 0.0f, 0.0f); // set color to white
	glPointSize(5.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 300.0f);
} 
void draw_circle(Point pC, GLfloat radius)  // function to dwar circle
 {   
	float step = 1/radius;  //calculating radius
	float x, y;  // declaring x & y in float data type
	for(float theta = 0; theta <= 360; theta += step   ) // formula for theta
 	{
		x = pC.x + (radius * cos(theta));
		y = pC.y + (radius * sin(theta));
		glVertex2i(x, y);   
	}
}
Point c1={100,100};
Point c2={35,100};

Point m1={0,100};
Point m2={150,100};
Point m3={150,150};
Point m4={125,160};
Point m5={100,200};
Point m6={0,200};
int radius = 10   ;   // radius of the needles from the center
void display(void)  // Terminal Points for Needle
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);  // beginning points
	
	glColor3f(1.0,0,0);
	draw_dda(m1,m2);
	draw_dda(m2,m3);
	draw_dda(m3,m4);
	draw_dda(m4,m5);
	draw_dda(m5,m6);
	draw_dda(m6,m1);
	
	glPointSize(10.0f);
	glColor3f(0, 0.0, 0);
	draw_circle(c1, radius);
	draw_circle(c2, radius);
	draw_circle(c1,5);
	draw_circle(c2,5);
	draw_circle(c1,2);
	draw_circle(c2,2);


	
	glEnd();     // end of gl
	glFlush(); 
	
	if(m1.x<=640)
	{
		
		
		c1.x+=3;
		c2.x+=3;
		m1.x+=3;
		m2.x+=3;
		m3.x+=3;
		m4.x+=3;
		m5.x+=3;
		m6.x+=3;
	}
	else
	{
		c1.x=100;
		c2.x=35;

		m1.x=0;
		m2.x=150;
		m3.x=150;
		m4.x=125;
		m5.x=100;
		m6.x=0;
	}
		
}	
void Timer(int value)	// function for timer
{   
	glutTimerFunc(10, Timer, 0);
	glutPostRedisplay();
}
int main(int argc, char **argv) // main function
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 300);
	glutCreateWindow("Fast & Furious 9");
	glutDisplayFunc(display);
	init();
	Timer(0);
	glutMainLoop();
	return 0;
}


