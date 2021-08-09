#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX (long long int)1e16

struct str{
	int first;
	int value1;
	int value2;
};
std::vector<str> V[100010];
long long int dist[100010];
std::priority_queue< std::pair<long long int,int> , std::vector< std::pair<long long int,int> > , std::greater< std::pair<long long int,int> > > Q;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e,f;
		scanf("%d%d%d%d",&c,&d,&e,&f);
		V[c].push_back({d,e,f});
		V[d].push_back({c,e,f});
	}
	
	for(int i=1;i<=a;i++) dist[i] = MAX;
	dist[1]	 = 0;
	Q.push(std::make_pair(0,1));
	while(!Q.empty())
	{
		long long int D = Q.top().first;
		int k = Q.top().second;
		Q.pop();
		if(dist[k]<D) continue;
		
		for(int i=0;i<V[k].size();i++)
		{
			int t = V[k][i].first;
			int t2 = (int)sqrt(V[k][i].value2);
			if(dist[t]>dist[k]+V[k][i].value1+V[k][i].value2/(dist[k]+1))
			{
				dist[t] = dist[k]+V[k][i].value1+V[k][i].value2/(dist[k]+1);
				Q.push({dist[k]+V[k][i].value1+V[k][i].value2/(dist[k]+1),t});
			}
			for(int j=t2-3;j<=t2+3;j++)
			{
				if(dist[k]>j) continue;
				long long int val = dist[k]+V[k][i].value1+V[k][i].value2/(j+1)+(j-dist[k]);
				if(dist[t]>val)
				{
					dist[t] = val;
					Q.push({val,t});
				}
			}
		}
	}
	if(dist[a]==MAX) printf("-1");
	else printf("%lld",dist[a]);
}