#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a+b>=15&&b>=8) printf("1");
	else if(a+b>=10&&b>=3) printf("2");
	else if(a+b>=3) printf("3");
	else printf("4");
}