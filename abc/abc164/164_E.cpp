#include <stdio.h>
#include <vector>
#include <queue>
struct str{
	int x0;
	int cost;
	int time;
};
std::vector<str> V[60];
struct str2{
	int x0;
	int coin;
	long long int dist;
};
bool operator<(str2 a, str2 b)
{
	return a.dist>b.dist;
}
std::priority_queue<str2> Q;
std::pair<int,int> x[60];
long long int check[60][3000];

long long int MAX = 1;
int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e,f,g;
		scanf("%d%d%d%d",&d,&e,&f,&g);
		V[d].push_back({e,f,g});
		V[e].push_back({d,f,g});
	}
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		x[i]=std::make_pair(d,e);
	}
	
	if(c>2500) c = 2500;
	Q.push({1,c,1});
	while(!Q.empty())
	{
		int x0 = Q.top().x0;
		int coin = Q.top().coin;
		long long int dist = Q.top().dist;
		Q.pop();
		
		if(check[x0][coin]) continue;
		check[x0][coin] = dist;
		
		if(coin+x[x0].first <= 2500) Q.push({x0,coin+x[x0].first,dist+x[x0].second});
		for(int i=0;i<V[x0].size();i++) if(V[x0][i].cost<=coin) Q.push({V[x0][i].x0,coin-V[x0][i].cost,dist+V[x0][i].time});
	}
	
	for(int i=2;i<=a;i++)
	{
		long long int ans = MAX;
		for(int j=0;j<=2500;j++)
		{
			if(check[i][j]>0) ans = ans<check[i][j]?ans:check[i][j];
		}
		printf("%lld\n",ans-1);
	}
}
