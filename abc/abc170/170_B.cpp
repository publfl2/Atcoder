#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b%2==1)
	{
		printf("No");
		return 0;
	}
	
	int c = 2*a;
	int d = 4*a;
	if(c<=b&&b<=d) printf("Yes");
	else printf("No");
}
