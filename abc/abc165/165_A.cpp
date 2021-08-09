#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int d = (b-1)/a + 1;
	int e = c/a;
	if(d<=e)
	{
		printf("OK");
	}
	else printf("NG");
}
