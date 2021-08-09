#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while(1)
	{
		c -= b;
		if(c<=0)
		{
			printf("Yes");
			return 0;
		}
		a -= d;
		if(a<=0)
		{
			printf("No");
			return 0;
		}
	}
}
