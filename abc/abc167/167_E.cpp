#include <stdio.h>
#define MOD 998244353

int a,b,c;
long long int fact[200010];

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
long long int inv(long long int a)
{
	return power(a,MOD-2);
}
long long int comb(long long int a, long long int b)
{
	long long int s = fact[a];
	s *= inv(fact[b]), s%=MOD;
	s *= inv(fact[a-b]), s%=MOD;
	return s;
}
long long int func(long long int s, long long int t)
{
	return comb(s,t)*power(b-1,s-t) % MOD;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++)
	{
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
	}
	
	scanf("%d%d%d",&a,&b,&c);
	
	long long int ans = 0;
	for(int i=0;i<=c;i++)
	{
		ans += b*func(a-1,i);
		ans %= MOD;
	}
	printf("%lld",ans);
}
