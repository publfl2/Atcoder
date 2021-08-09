#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int e = a<b?a:b;
	int f = c<d?c:d;
	printf("%d",e<f?e:f);
}
