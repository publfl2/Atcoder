#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+c==2*b) printf("Yes");
	else if(b+c==2*a) printf("Yes");
	else if(a+b==2*c) printf("Yes");
	else printf("No");
}