#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=1000;i++)
	{
		if(b*i>=a)
		{
			printf("%d",c*i);
			return 0;
		}
	}
}
