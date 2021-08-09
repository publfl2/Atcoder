#include <stdio.h>

int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if(b<c) printf("No");
	else if(d<a) printf("No");
	else printf("Yes");
}
