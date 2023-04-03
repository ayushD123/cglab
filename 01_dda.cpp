#include<iostream>
#include<stdio.h>
#include<glut.h>
using namespace std;
//int x1, y1, x2, y2;
void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();

}
void LineDda(int x0, int y0, int xe, int ye)
{

	int dx = xe - x0, dy = ye - y0, steps, k;
	float xinc, yinc, x = x0, y = y0;
	if (fabs(dx) < fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xinc = float(dx) / float(steps);
	yinc = float(dy) / float(steps);
	setPixel(round(x), round(y));
	for (k = 0; k < steps; k++)
	{
		x += xinc;
		y += yinc;
		setPixel(round(x), round(y));
	}
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
void disp1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(5);
	LineDda(100, 200, 300, 400);
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("LineDda");
	myinit();
	glutDisplayFunc(disp1);
	glutMainLoop();
	return 0;
}

