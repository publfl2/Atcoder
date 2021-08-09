#include <stdio.h>
#include <string.h>
#define MOD 2019

long long int power(int s, int t)
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
long long int inv(int k)
{
	return power(k,1343);
}


char x[200010];
int y[200010];
long long int check[200010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int s = 0;
	for(int i=1;i<=a;i++)
	{
		s*=10;
		s+=(x[i]-'0');
		s%=MOD;
		y[i] = s;
	}
	for(int i=1;i<=a;i++)
	{
		long long int t = y[i] * power(inv(10),i);
		t %= MOD;
		check[t]++;
	}
	check[0]++;
	
	long long int ans = 0;
	for(int i=0;i<MOD;i++)
	{
		ans += check[i]*(check[i]-1)/2;
	}
	printf("%lld",ans);
}
