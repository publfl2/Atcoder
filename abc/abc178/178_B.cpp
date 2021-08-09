#include <stdio.h>

int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long int s = a*c;
	long long int ans = s;
	s = a*d;
	ans = ans>s?ans:s;
	s = b*c;
	ans = ans>s?ans:s;
	s = b*d;
	ans = ans>s?ans:s;
	printf("%lld",ans);
}
