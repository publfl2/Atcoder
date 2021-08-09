#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int c = 0, d = 0;
	while(a)
	{
		c += (a%10);
		a/=10;
	}
	while(b)
	{
		d += (b%10);
		b/=10;
	}
	printf("%d",c>d?c:d);
}
