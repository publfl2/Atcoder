#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	if(d>a+b) printf("%d",a-(d-a-b));
	else if(d>a) printf("%d",a);
	else printf("%d",d);
}
