#include <stdio.h>
#define MOD 1000000007

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

long long int fact[2000010];
long long int comb(int a, int b)
{
	if(b<0) return 0;
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=2000000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b+c)
	{
		printf("0");
		return 0;
	}
	
	long long int ans1 = comb(a+b,a);
	long long int ans2 = comb(a+b,a-(c+1));
	printf("%lld",(ans1+(MOD-ans2))%MOD);
}