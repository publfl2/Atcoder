#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	if(a%2==1) printf("No");
	else
	{
		for(int i=1;i<=a;i+=2)
		{
			if(x[i]!='h')
			{
				printf("No");
				goto u;
			}
		}
		for(int i=2;i<=a;i+=2)
		{
			if(x[i]!='i')
			{
				printf("No");
				goto u;
			}
		}
		printf("Yes");
		u:;
	}
}