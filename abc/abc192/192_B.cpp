#include <stdio.h>
#include <string.h>

char x[1010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i+=2)
	{
		if('a'<=x[i]&&x[i]<='z');
		else
		{
			printf("No");
			return 0;
		}
	}
	for(int i=2;i<=a;i+=2)
	{
		if('A'<=x[i]&&x[i]<='Z');
		else
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}