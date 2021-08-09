#include <stdio.h>
#define MOD 1000000007
long long int power(long long int s, long long int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		t/=2;
	}
	return ans;
}

long long int inv(long long int t)
{
	return power(t,MOD-2);
}

long long int fact[500010];
long long int comb(int s, int t)
{
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans %= MOD;
	ans *= inv(fact[s-t]), ans %= MOD;
	return ans;
}

long long int func(int s, int t)
{
	long long int C = comb(t,s);
	C *= fact[s], C%=MOD;
	return (C*C)%MOD;
}
int main()
{
	fact[0] = 1;
	for(int i=1;i<=500000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	long long int ans = 0;
	for(int i=0;i<=a;i++)
	{
		long long int C = 1;
		if(i%2==0)
		{
			C *= comb(a,i), C%= MOD;
			C *= comb(b,i), C%= MOD;
			C *= fact[i], C%= MOD;
			C *= func(a-i,b-i), C%= MOD;
			ans += C;
		}
		else
		{
			C *= comb(a,i), C%= MOD;
			C *= comb(b,i), C%= MOD;
			C *= fact[i], C%= MOD;
			C *= func(a-i,b-i), C%= MOD;
			ans -= C;
		}
		ans += MOD;
		ans %= MOD;
	}
	printf("%lld",ans);
	
}
