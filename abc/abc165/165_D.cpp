#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	
	if(b<=c) printf("%lld",a*(b-1)/b);
	else printf("%lld",a*c/b);
}
