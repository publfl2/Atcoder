#include <stdio.h>
#define MOD 1000000007

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int N,A,B;
		scanf("%lld%lld%lld",&N,&A,&B);
		
		long long int ans = 0;
		if(N-A-B+1>=1)
		{
			long long int S = (N-A+1)*(N-B+1);
			S %= MOD;
			long long int t = (N-A-B+1);
			long long int t2 = t*(t+1)/2;
			t2%=MOD;
			S *= t2;
			S %= MOD;
			ans += S;
			ans %= MOD;
		}
		if(N-A-B+1>=1)
		{
			long long int S = (N-B+1)*(N-A+1);
			S %= MOD;
			long long int t = (N-A-B+1);
			long long int t2 = t*(t+1)/2;
			t2%=MOD;
			S *= t2;
			S%=MOD;
			ans += S;
			ans %= MOD;
		}
		ans*=2;
		ans%=MOD;
		if(N-A-B+1>=1)
		{
			long long int t = (N-A-B+1);
			long long int t2 = t*(t+1)/2;
			t2%=MOD;
			ans -= 4*t2*t2;
			ans %= MOD;
			ans +=MOD;
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}
