#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum = 0;
	int min = 123;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int b;
			scanf("%d",&b);
			sum += b;
			min = min<b?min:b;
		}
	}
	printf("%d\n",sum-(a*b*min));
}
