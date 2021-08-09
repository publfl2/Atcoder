#include <stdio.h>
#define MOD 998244353

long long int DP[110];
long long int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	DP[a+1] = 1;
	for(int i=a;i>=1;i--)
	{
		DP[i] = x[i] * DP[i+1];
		DP[i] %= MOD;
		int sign = 1;
		int min = x[i];
		for(int j=1;i+j<=a;j++)
		{
			min = min<x[i+j]?min:x[i+j];
			sign *= (-1);
			DP[i] += sign*min*DP[i+j+1];
			DP[i] %= MOD;
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",DP[i]);
}