#include <stdio.h>
#include <vector>

#define MOD 998244353
std::pair<int,int> P[110];
long long int DP[400010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i]=std::make_pair(c,d);
	}
	DP[a] = 1;
	for(int i=a-1;i>=1;i--)
	{
		long long int S = 0;
		for(int j=1;j<=b;j++)
		{
			int s = i+P[j].first;
			int t = i+P[j].second;
			S += (DP[s]-DP[t+1]+MOD)%MOD;
			S %= MOD;
		}
		DP[i] = (DP[i+1] + S)%MOD;
	}
	printf("%lld",(DP[1]-DP[2]+MOD)%MOD);
}
