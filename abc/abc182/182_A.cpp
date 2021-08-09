#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int c = 2*a+100;
	printf("%d",b>c?0:c-b);
}
