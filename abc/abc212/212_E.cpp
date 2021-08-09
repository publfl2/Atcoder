#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int DP[5010][5010];
long long int sum[5010];
std::pair<int,int> P[5010];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		P[i] = std::make_pair(d,e);
	}
	
	DP[1][0] = 1;
	for(int j=1;j<=c;j++)
	{
		for(int i=1;i<=a;i++) sum[i] = (sum[i-1]+DP[i][j-1])%MOD;
		for(int i=1;i<=a;i++) DP[i][j] = (sum[a] - DP[i][j-1] + MOD) % MOD;
		for(int i=1;i<=b;i++)
		{
			DP[P[i].first][j] += (MOD-DP[P[i].second][j-1]), DP[P[i].first][j] %= MOD;
			DP[P[i].second][j] += (MOD-DP[P[i].first][j-1]), DP[P[i].second][j] %= MOD;
		}
	}
	
	printf("%lld",DP[1][c]);
}