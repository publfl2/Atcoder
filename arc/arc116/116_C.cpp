#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[200010];
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

long long int DP[30][200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = (fact[i-1]*i)%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) DP[1][i] = 1;
	for(int i=1;i<20;i++) for(int j=1;j<=b;j++) for(int k=2*j;k<=b;k+=j) DP[i+1][k] += DP[i][j], DP[i+1][k] %= MOD;
	
	long long int ans = 0;
	for(int i=1;i<=20;i++)
	{
		long long int s = comb(a-1,i-1);
		for(int j=1;j<=b;j++)
		{
			long long int t = DP[i][j];
			ans += s*t;
			ans %= MOD;
		}
	}
	printf("%lld",ans);
}