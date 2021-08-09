#include <stdio.h>
#include <string.h>
char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=x[a-i+1])
		{
			printf("No");
			return 0;
		}
	}
	for(int i=1;i<=(a-1)/2;i++)
	{
		if(x[i]!=x[(a-1)/2-i+1])
		{
			printf("No");
			return 0;
		}
	}
	for(int i=(a+3)/2;i<=a;i++)
	{
		if(x[i]!=x[a-i+(a+3)/2])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}
