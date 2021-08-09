#include <stdio.h>
#include <algorithm>
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

long long int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+a+1);
	
	long long int t = 0;
	long long int ans = 0;
	for(int i=a;i>=1;i--)
	{
		long long int s = x[i]*inv(power(2,i+1));
		s %= MOD;
		ans += (s*t)%MOD, ans %= MOD;
		t += (x[i]*power(2,i));
		t %= MOD;
	}
	for(int i=1;i<=a;i++) ans += (x[i]*x[i])%MOD, ans %= MOD;
	printf("%lld",ans);
}