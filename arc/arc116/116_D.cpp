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

long long int fact[10010];
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}
long long int comb2[10010];

int count[30],a;
long long int check[30][10010];
long long int func(int s, int t)
{
	if(s<0)
	{
		if(t==0) return 1;
		else return 0;
	}
	if(check[s][t]!=-1) return check[s][t];
	
	t+=count[s];
	long long int ans = 0;
	for(int i=0;i<=t && 2*i<=a;i++)
	{
		ans += (comb2[2*i]*func(s-1,2*(t-i)));
		ans %= MOD;
	}
	check[s][t-count[s]] = ans;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=10000;i++) fact[i] = (fact[i-1]*i)%MOD;
	
	int b;
	scanf("%d%d",&a,&b);
	if(b%2==1)
	{
		printf("0");
		return 0;
	}
	b/=2;
	
	for(int i=0;b;i++)
	{
		count[i] = b%2;
		b/=2;
	}
	
	for(int i=0;i<=a;i+=2) comb2[i] = comb(a,i);
	for(int i=0;i<=20;i++) for(int j=0;j<=10000;j++) check[i][j] = -1;
	printf("%lld",func(20,0));
}