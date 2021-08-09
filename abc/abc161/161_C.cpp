#include <stdio.h>

long long int func(long long int a, long long int b)
{
	if(a>b)
	{
		long long int s1 = func(a%b,b);
		long long int s2 = a%b;
		return s1<s2?s1:s2;
	}
	else
	{
		long long int s1 = (b-a);
		long long int s2 = a;
		return s1<s2?s1:s2;
	}
}
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	printf("%lld",func(a,b));
}
