#include <stdio.h>
#include <queue>
#include <vector>
#define MOD 1000000007

std::queue<int> Q;
int dist[200010];
long long int count[200010];
std::vector<int> V[200010];
std::vector<int> save[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	for(int i=1;i<=a;i++) dist[i] = -1;
	Q.push(1);
	dist[1] = 0;
	while(!Q.empty())
	{
		int t = Q.front();
		Q.pop();
		
		for(int i=0;i<V[t].size();i++)
		{
			if(dist[V[t][i]]==-1)
			{
				dist[V[t][i]] = dist[t] + 1;
				Q.push(V[t][i]);
			}
		}
	}
	if(dist[a]==-1) printf("0");
	else
	{
		for(int i=1;i<=a;i++) save[dist[i]].push_back(i);
		count[1] = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<save[i].size();j++)
			{
				int t = save[i][j];
				for(int k=0;k<V[t].size();k++)
				{
					if(dist[V[t][k]]==dist[t]-1) count[t] += count[V[t][k]], count[t] %= MOD;
				}
			}
		}
		printf("%lld",count[a]);
	}
}