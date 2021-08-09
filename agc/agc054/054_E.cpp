#include <stdio.h>
#include <atcoder/convolution>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans *=k, ans %=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[1000010];
long long int func(int A, int N)
{
	if(N-A-2<0) return 0;
	long long int ans = 0;
	for(int B=A+1;B<=N;B++)
	{
		if(B-3<0) continue;
		if(B-A-2<0) continue;
		
		long long int k = fact[B-3];
		k *= inv(fact[B-A-2]), k %= MOD;
		k *= (B-A-1), k %= MOD;
		ans += k, ans %= MOD;
	}
	ans *= fact[N-A-2], ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=1000000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		long long int s1 = fact[a-1];
		long long int s2 = func(b,a);
		long long int s3 = func(a-b+1,a);
		printf("%lld\n",(s1-s2-s3+2*MOD)%MOD);
	}
}