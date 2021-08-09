#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int lcm(long long int a, long long int b)
{
	return (a/gcd(a,b))*b;
}
int main()
{
	int a;
	scanf("%d",&a);
	long long int ans = 1;
	for(int i=2;i<=a;i++) ans = lcm(ans,i);
	printf("%lld",ans+1);
}
