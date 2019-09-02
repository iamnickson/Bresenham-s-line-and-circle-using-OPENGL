#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Center of the cicle = (320, 240)
int xc = 320, yc = 240;
int r;

void plot_point(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc+x, yc+y);
	glVertex2i(xc+x, yc-y);
	glVertex2i(xc+y, yc+x);
	glVertex2i(xc+y, yc-x);
	glVertex2i(xc-x, yc-y);
	glVertex2i(xc-y, yc-x);
	glVertex2i(xc-x, yc+y);
	glVertex2i(xc-y, yc+x);
	glEnd();
}
void bresenham_circle(int r)
{
	int x=0,y=r;
	float pk=(5.0/4.0)-r;

	/* Plot the points */
	/* Plot the first point */
	plot_point(x,y);
	int k;
	/* Find all vertices till x=y */
	while(x < y)
	{
		x = x + 1;
		if(pk < 0)
			pk = pk + 2*x+1;
		else
		{
			y = y - 1;
			pk = pk + 2*(x - y) + 1;
		}
		plot_point(x,y);
	}
	glFlush();
}
void circles(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//int radius1 = 100;
	int radius1 = r;
	//int radius2 = 200;
	bresenham_circle(radius1);
	//bresenham_circle(radius2);
}

void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0 , 640 , 0 , 480);
}

void main(int argc, char **argv)
{
	printf( "Enter (r)\n");
	scanf("%d", &r);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("Bresenham complete circle");
	Init();
	glutDisplayFunc(circles);
	glutMainLoop();
}
