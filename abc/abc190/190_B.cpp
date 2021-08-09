#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		if(d<b&&e>c)
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}
