#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==1) printf("%lld",power(c,b));
	else if(b==1) printf("%lld",power(c,a));
	else
	{
		long long int ans = 0;
		for(int i=1;i<=c;i++)
		{
			long long int s1 = power((c-i+1),b)%MOD;
			long long int t1 = (power(i,a) - power(i-1,a) + MOD)%MOD;
			ans += (s1*t1)%MOD;
			ans %= MOD;
		}
		printf("%lld",ans);
	}
}