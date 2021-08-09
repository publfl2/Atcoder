#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	b*=a, c*=a;
	if(b<=d&&d<=c) printf("No");
	else printf("Yes");
}
