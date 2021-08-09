#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 123456789
struct MCMF{
	struct Edge{
		int first;
		int second;
		int capacity;
		int cost;
	};
	std::vector<int> V[5010][5010];
	std::vector<Edge> E;
	std::vector<int> V2[5010];
	
	void setEdge(int first, int second, int capacity, int cost)
	{
		int n = E.size();
		E.push_back({first,second,capacity,cost});
		E.push_back({second,first,0,-cost});
		V[first][second].push_back(n);
		V[second][first].push_back(n+1);
	}
	
	int vSize;
	int source,sink;
	
	int dist[5010],check[5010],prev[5010];
	void init()
	{
		for(int i=0;i<=vSize;i++)
		{
			for(int j=0;j<=vSize;j++)
			{
				if(V[i][j].size()>0) V2[i].push_back(j);
			}
		}
	}
	std::vector<int> SPFA()
	{
		for(int i=0;i<=vSize;i++) check[i] = 0;
		for(int i=0;i<=vSize;i++) dist[i] = MAX;
		std::queue<int> Q;
		Q.push(source);
		dist[source] = 0;
		while(!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			
			check[v] = 0;
			for(int j=0;j<V2[v].size();j++)
			{
				int i = V2[v][j];
				for(int k=0;k<V[v][i].size();k++)
				{
					int e = V[v][i][k];
					if(E[e].capacity>0)
					{
						if(dist[i]>dist[v]+E[e].cost)
						{
							dist[i] = dist[v] + E[e].cost;
							prev[i] = e;
							if(check[i]==0)
							{
								check[i] = 1;
								Q.push(i);
							}
						}
					}
				}
			}
		}
		
		std::vector<int> path;
		if(dist[sink]==MAX) return path;
		else
		{
			int v = sink;
			while(v!=source)
			{
				path.push_back(prev[v]);
				v = E[prev[v]].first;
			}
			return path;
		}
	}
	
	std::pair<int,int> getMCMF() // <Flow,Cost>
	{
		int flow = 0, cost = 0;
		while(1)
		{
			std::vector<int> path = SPFA();
			if(path.size()==0) return std::make_pair(flow,cost);
			else
			{
				int f = MAX, c = 0;
				for(int i=0;i<path.size();i++)
				{
					f = f<E[path[i]].capacity?f:E[path[i]].capacity;
					c += E[path[i]].cost;
				}
				flow += f;
				cost += f*c;
				for(int i=0;i<path.size();i++)
				{
					E[path[i]].capacity -= f;
					E[path[i]^1].capacity += f;
				}
			}
		}
	}	
}G;

char x[110][110];
std::queue< std::pair<int,int> > Q;
int inQueue[110][110];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='o')
			{
				Q.push(std::make_pair(i,j));
				inQueue[i][j] = 1;
				while(!Q.empty())
				{
					int s = Q.front().first;
					int t = Q.front().second;
					Q.pop();
					
					inQueue[s][t] = 0;
					int v1 = b*(i-1) + j;
					int v2 = a*b+b*(s-1) + t;
					G.setEdge(v1,v2,1,-(s-i+t-j));
					if((x[s+1][t]=='o' || x[s+1][t]=='.')&&inQueue[s+1][t]==0)
					{
						inQueue[s+1][t] = 1;
						Q.push(std::make_pair(s+1,t));
					}
					if((x[s][t+1]=='o' || x[s][t+1]=='.')&&inQueue[s][t+1]==0)
					{
						inQueue[s][t+1] = 1;
						Q.push(std::make_pair(s,t+1));
					}
				}
			}
		}
	}
	
	G.source = 2*a*b+1;
	G.sink = 2*a*b+2;
	G.vSize = 2*a*b+2;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='o')
			{
				int v1 = b*(i-1)+j;
				G.setEdge(2*a*b+1,v1,1,0);
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]!='#')
			{
				int v1 = a*b+b*(i-1)+j;
				G.setEdge(v1,2*a*b+2,1,0);
			}
		}
	}
	
	G.init();
	std::pair<int,int> P = G.getMCMF();
	printf("%d",-P.second);
}
