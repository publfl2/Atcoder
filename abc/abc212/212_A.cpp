#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>0&&b>0) printf("Alloy");
	else if(a==0) printf("Silver");
	else printf("Gold");
}