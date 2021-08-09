#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int b = strlen(x+1);
	if(b<=a) printf("%s",x+1);
	else
	{
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		printf("...");
	}
}
