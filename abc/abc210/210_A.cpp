#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(b<=a) printf("%d",c*b+(a-b)*d);
	else printf("%d",a*c);
}