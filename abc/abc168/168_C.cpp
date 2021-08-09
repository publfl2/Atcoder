#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	double e = 30*c + 0.5*d;
	double f = d*6;
	double g = a*a + b*b - 2*a*b*cos(PI*(e-f)/180);
	printf("%.18lf",sqrt(g));
}
