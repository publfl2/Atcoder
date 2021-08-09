#include <stdio.h>
#define MOD 1000000007
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
int main()
{
	int a;
	scanf("%d",&a);
	long long int s1 = power(10,a);
	long long int s2 = power(9,a);
	long long int s3 = power(8,a);
	printf("%lld",(s1+2*(MOD-s2)+s3)%MOD);
}
