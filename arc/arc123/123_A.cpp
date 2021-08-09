#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	long long int x = b-a, y = c-b;
	if(x<=y)
	{
		if((y-x)%2==0) printf("%lld",(y-x)/2);
		else printf("%lld",(y-x)/2+2);
	}
	else printf("%lld",x-y);
}