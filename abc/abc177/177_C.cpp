#include <stdio.h>
#define MOD 1000000007
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		s*=s, s%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}
int main()
{
	int a;
	scanf("%d",&a);
	long long int S1 = 0, S2 = 0;
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		S1 += b, S1%=MOD;
		S2 += b*b, S2%=MOD;
	}
	S1 = S1*S1, S1%=MOD;
	printf("%lld\n",(S1-S2+MOD)*inv(2)%MOD);
}
