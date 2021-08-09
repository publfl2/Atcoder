#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b<a) printf("0");
	else printf("%d",b-a+1);
}