#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;;i++)
	{
		if((360*i)%a==0)
		{
			printf("%d",(360*i)/a);
			return 0;
		}
	}
}
