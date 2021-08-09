#include <stdio.h>
#define MOD 998244353
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k;
		k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}
long long int fact[2000010];
long long int comb(long long int s, long long int t)
{
	long long int ans = fact[s];
	ans *= inv(fact[s-t]), ans %= MOD;
	ans *= inv(fact[t]), ans %= MOD;
	return ans;
}
int main()
{
	fact[0] = 1;
	for(int i=1;i<=2000000;i++) fact[i] = (fact[i-1]*i)%MOD;
	int a;
	scanf("%d",&a);
	printf("%lld",comb(a+a-1,a));
}

