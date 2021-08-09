#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX (long long int)1e18

struct str{
	int first;
	int second;
	int period;
};
std::vector<str> V[100010];

struct str2{
	int index;
	long long int value;
};
bool operator<(str2 a, str2 b)
{
	return a.value>b.value;
}
std::priority_queue<str2> Q;

long long int dist[100010];
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=b;i++)
	{
		int d,e,f,g;
		scanf("%d%d%d%d",&d,&e,&f,&g);
		V[d].push_back({e,f,g});
		V[e].push_back({d,f,g});
	}
	
	for(int i=1;i<=a;i++) dist[i] = MAX;
	Q.push({c,0});
	while(!Q.empty())
	{
		int k = Q.top().index;
		long long int d = Q.top().value;
		Q.pop();
		if(dist[k]!=MAX) continue;
		dist[k] = d;
		for(int i=0;i<V[k].size();i++)
		{
			long long int e = (d-1)/V[k][i].period+1;
			if(d==0) e = 0;
			Q.push({V[k][i].first,e*V[k][i].period+V[k][i].second});
		}
	}
	
	if(dist[d]==MAX) printf("-1");
	else printf("%lld",dist[d]);
}