#include<GL/glut.h> // header files
#include <math.h>
struct Point // structure of point
{
int x; // initializing x &y
int y;
};
void draw_dda(Point p1, Point p2) // function for draw dda
{
float dx = p2.x - p1.x; // using formulae
float dy = p2.y - p1.y;
float x1 = p1.x;
float y1 = p1.y;
float step = 0;
step=(abs(dx)>abs(dy))?abs(dx):abs(dy);
float xInc = dx/step; // steps for incrementing value of x and y
float yInc = dy/step;
for(float i = 1; i <= step; i++) // checking conditions
{
glVertex2i(x1, y1); //check point for vertex
x1 += xInc; // incrementing values
y1 += yInc;
}
}
void init() // initialization function
{
glClearColor(0, 0,0, 0.0); // set color to black
glColor3f(0.0f, 0.0f, 0.0f); // set color to white
glPointSize(25.0f);
gluOrtho2D(0.0f, 500.0f, 0.0f, 600.0f);
}
void draw_circle(Point pC, GLfloat radius) // function to dwar circle
{
float step = 1/radius; //calculating radius
float x, y; // declaring x & y in float data type
for(float theta = 0; theta <= 360; theta += step ) // formula for theta
{
x = pC.x + (radius * cos(theta));
y = pC.y + (radius * sin(theta));
glVertex2i(x, y);
}
}
Point p1={50,100};
Point p2={150,100};
Point p3={100,100};
Point p4={100,500};
Point f1={125,125};
Point f2={225,125};
Point f3={125,150};
Point f4={225,150};
Point f5={125,175};
Point f6={225,175};
Point c={175,150};
int radius = 20 ; // radius of the needles from the center
void display(void) // Terminal Points for Needle
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS); // beginning points
glColor3f(0.2,0,0);
draw_dda(p1,p2);
draw_dda(p3,p4);
glColor3f(0.8,0,0);
draw_dda(f5,f6);
glColor3f(01.0,1.0,1.0);
draw_dda(f3,f4);
glColor3f(0,1,0);
draw_dda(f1,f2);
glPointSize(10.0f);
glColor3f(0,0,1);
draw_circle(c,5);
glEnd(); // end of gl
glFlush();
if(f5.y<=475)
{
f1.y+=3;
f2.y+=3;
f3.y+=3;
f4.y+=3;
f5.y+=3;
f6.y+=3;
c.y+=3;
}
}
void Timer(int value) // function for timer
{
glutTimerFunc(10, Timer, 0);
glutPostRedisplay();
}
int main(int argc, char **argv) // main function
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(200, 200);
glutInitWindowSize(500, 600);
glutCreateWindow("Fast & Furious FLAGS");
glutDisplayFunc(display);
init();
Timer(0);
glutMainLoop();
return 0;
}
