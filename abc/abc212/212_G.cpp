#include <stdio.h>
#include <vector>
#define MOD 998244353

std::vector<long long int> prime,V;
long long int func(long long int k)
{
	long long int ans = 1;
	long long int k2 = k;
	for(int i=0;i<prime.size();i++)
	{
		if(prime[i]*prime[i]>k) break;
		if(k2%prime[i]==0)
		{
			long long int t1 = prime[i], t2 = 1;
			k2/=prime[i];
			while(k2%prime[i]==0)
			{
				k2 /= prime[i];
				t1 *= prime[i], t2 *= prime[i];
			}
			ans *= (t1-t2), ans %= MOD;
		}
	}
	if(k2>1) ans *= (k2-1), ans %= MOD;
	return ans;
}

int main()
{
	long long int a;
	scanf("%lld",&a);
	a--;
	
	long long int a2 = a;
	for(long long int i=2;i*i<=a;i++)
	{
		if(a2%i==0)
		{
			prime.push_back(i);
			while(a2%i==0) a2/=i;
		}
	}
	if(a2>1) prime.push_back(a2);
	
	for(long long int i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			V.push_back(i);
			if(i*i!=a) V.push_back(a/i);
		}
	}
	
	long long int ans = 0;
	for(int i=0;i<V.size();i++)
	{
		long long int t = V[i];
		long long int s = func(a/V[i]);
		long long int t2 = (a/V[i]);
		t2 %= MOD;
		ans += (s*t2)%MOD, ans %= MOD;
	}
	printf("%lld",(ans+1)%MOD);
}