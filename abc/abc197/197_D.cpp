#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int main()
{
	int a;
	scanf("%d",&a);
	
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	double xr = (double)(x1+x2)/2;
	double yr = (double)(y1+y2)/2;
	double xvec = x1 - xr;
	double yvec = y1 - yr;
	double xvec2 = cos(2*PI/a) * xvec - sin(2*PI/a) * yvec;
	double yvec2 = sin(2*PI/a) * xvec + cos(2*PI/a) * yvec;
	printf("%.12lf %.12lf",xvec2 + xr, yvec2 + yr);
}