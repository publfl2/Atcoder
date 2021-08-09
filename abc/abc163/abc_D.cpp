#include <stdio.h>
#define MOD 1000000007
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	long long int sum = 0;
	for(int i=b;i<=a+1;i++)
	{
		long long int min = (long long int)(i-1)*i/2;
		long long int max = (long long int)(2*a-i+1)*i/2;
		sum += (max-min+1), sum%=MOD;
	}
	printf("%lld",sum);
}
