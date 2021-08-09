#include <stdio.h>
#include <string.h>

char x[200010],y[200010];
int main()
{
	scanf("%s",x+1);
	scanf("%s",y+1);
	int a = strlen(x+1);
	int count = 0;
	for(int i=1;i<=a;i++) if(x[i]!=y[i]) count++;
	printf("%d",count);
}
