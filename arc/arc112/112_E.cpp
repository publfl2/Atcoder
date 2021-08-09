#include <stdio.h>
#define MOD 998244353
int a,b;
long long int func(int s, int t)
{
	if(s>a) return 0;
	if(t>b)
	{
		if(s==a) return 1;
		else return 0;
	}
	
	long long int s1 = (func(s,t+1)*2*(a-s))%MOD;
	long long int s2 = 2*func(s+1,t+1);
	return (s1+s2)%MOD;
}

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, b/=2;
		k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[10010];
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int x[3010];
int state[3010][3010];
long long int count[3010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=10000;i++) fact[i] = (fact[i-1]*i)%MOD;
	
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	count[0] = 1;
	for(int i=1;i<=a;i++) state[i][i] = 1;
	for(int i=2;i<=a;i++)
	{
		for(int j=1;j+i-1<=a;j++)
		{
			if(state[j][j+i-2]==1 && x[j+i-2]<x[j+i-1])
			{
				state[j][j+i-1] = 1;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		{
			if(state[i][j]==1)
			{
				count[j-i+1] += comb(a-j+i-1,i-1);
				count[j-i+1] %= MOD;
			}
		}
	}
	for(int i=0;i<=a;i++) printf("%lld ",count[i]);
	printf("\n");
	for(int i=0;i<=a;i++) printf("%lld ",func(i,1));
	printf("\n");
	
	long long int ans = 0;
	for(int i=0;i<=a;i++)
	{
		ans += func(i,1)*count[i];
		ans %= MOD;
	}
	printf("%lld",ans);
}