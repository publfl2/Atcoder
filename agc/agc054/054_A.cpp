#include <stdio.h>

char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	if(x[1]!=x[a]) printf("1");
	else
	{
		if(a==2) printf("-1");
		else
		{
			for(int i=3;i<=a-1;i++)
			{
				if(x[i-1]!=x[1]&&x[i]!=x[1])
				{
					printf("2");
					return 0;
				}
			}
			printf("-1");
		}
	}
}