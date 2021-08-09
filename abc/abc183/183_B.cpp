#include <stdio.h>

int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	double ans = (double)(a*d+c*b)/(b+d);
	printf("%.12lf",ans);
}
