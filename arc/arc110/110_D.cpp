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

long long int comb(int s, int t)
{
	if(t==0) return 1;
	long long int k = comb(s-1,t-1);
	k *= s, k %= MOD;
	k *= inv(t), k %= MOD;
	return k;
}

int x[2010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int s = 0;
	for(int i=1;i<=a;i++) s += x[i];
	if(s>b) printf("0");
	else printf("%lld",comb(b+a,s+a));
}
