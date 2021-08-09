#include <stdio.h>
#define MOD 1000000007

long long int DP[100010];
int x[100010];
int main()
{
	DP[0] = 1;
	DP[1] = 1;
	for(int i=2;i<=100000;i++) DP[i] = (DP[i-1] + DP[i-2])%MOD;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int t = DP[i-1] * DP[a-i+1];
		t %= MOD;
		ans += (t*x[i]), ans %= MOD;
	}
	
	for(int i=2;i<=a;i++)
	{
		long long int t = DP[i-2] * DP[a-i];
		t %= MOD;
		ans += ((MOD-t)*x[i]), ans %= MOD;
	}
	printf("%lld",ans);
}