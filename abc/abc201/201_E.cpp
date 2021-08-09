#include <stdio.h>
#include <vector>
#define MOD 1000000007

std::vector< std::pair<int,long long int> > V[200010];
long long int dist[200010];
void func(int k, int prev, long long int h)
{
	dist[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		func(V[k][i].first,k,h^V[k][i].second);
	}
}

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		long long int d;
		scanf("%d%d%lld",&b,&c,&d);
		V[b].push_back({c,d});
		V[c].push_back({b,d});
	}
	
	func(1,0,0);
	
	long long int ans = 0;
	long long int s = 1;
	for(int j=0;j<=60;j++)
	{
		for(int k=1;k<=a;k++) x[k] = (dist[k]/s)%2;
		int count = 0;
		for(int k=1;k<=a;k++) if(x[k]==1) count++;
		long long int val = (long long int)count*(a-count);
		val %= MOD;
		val *= (s%MOD);
		val %= MOD;
		ans += val, ans %= MOD;
		s*=2;
	}
	printf("%lld",ans);
}