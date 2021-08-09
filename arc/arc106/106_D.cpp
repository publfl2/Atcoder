#include <stdio.h>
#define MOD 998244353
long long int x[200010],sum[200010];
long long int s[200010];
long long int check[310][310];

long long int power(long long int s, long long int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans*=k, ans%=MOD;
		t/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(t==s) return 1;
	if(check[s][t]) return check[s][t];
	return check[s][t] = (comb(s-1,t-1)+comb(s-1,t))%MOD;
}

long long int value1[200010],value2[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	for(int j=1;j<=a;j++) s[j] = 1;
	sum[0] = a;
	
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=a;j++)
		{
			s[j] *= x[j];
			s[j] %= MOD;
		}
		for(int j=1;j<=a;j++) sum[i] += s[j], sum[i] %= MOD;
		long long int S = 0;
		for(int j=1;j<=a;j++) value1[i] += s[j], value1[i]%=MOD;
		for(int j=1;j<=i;j++) value1[i]*=2,value1[i]%=MOD;
	}
	
	for(int i=1;i<=b;i++)
	{
		long long int ans = 0;
		for(int j=0;j<=i;j++)
		{
			long long int t = sum[i-j]*sum[j];
			t %= MOD;
			t *= comb(i,j), t%=MOD;
			ans += t, ans %= MOD;
		}
		value2[i] = ans;
	}
	for(int i=1;i<=b;i++)
	{
		long long int ans = (value2[i]-value1[i]+MOD)*inv(2);
		printf("%lld\n",ans%MOD);
	}
}
