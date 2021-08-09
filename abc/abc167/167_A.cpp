#include <stdio.h>
#include <string.h>
char x[100010],y[100010];
int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=y[i])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}
