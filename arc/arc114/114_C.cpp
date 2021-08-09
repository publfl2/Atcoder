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
long long int DP[5010][5010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++) DP[i][1] = 1;
	for(int j=2;j<=b;j++)
	{
		long long int S1 = 0, S2 = 0, S3 = 1;
		
		DP[1][j] = DP[1][j-1] + S1 + S2 + S3;
		for(int i=2;i<=a;i++)
		{
			S1 *= j, S1 += DP[i-1][j-1], S1 %= MOD;
			S2 *= (j-1), S2 += DP[i-1][j], S2 %= MOD;
			DP[i][j] = (DP[i][j-1] + S1 + S2 + power(j,i-2)+1)%MOD;
		}
		
	}
	printf("%lld",DP[a][b]);
}