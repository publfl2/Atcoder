#include <stdio.h>

long long int abs(long long int k)
{
	return k>0?k:-k;
}
int main()
{
	long long int a,b,c,d,e;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
	
	if(d>=b)
	{
		printf("NO");
		return 0;
	}
	
	long long int dist = abs(a-c);
	if(dist<=e*(b-d)) printf("YES");
	else printf("NO");
}
