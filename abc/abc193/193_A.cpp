#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%.12lf",(double)100*(a-b)/a);
}