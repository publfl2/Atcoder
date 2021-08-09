#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<=b&&b<=6*a) printf("Yes");
	else printf("No");
}