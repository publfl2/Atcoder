#include <stdio.h>
#include <vector>

// 1: left, 2:right
std::vector< std::pair<int,int> > V[110];
int ans[10010];
int check[110];

void func(int k, int prev)
{
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		if(check[V[k][i].first]==1)
		{
			if(ans[V[k][i].second]==0) ans[V[k][i].second] = k;
		}
		else
		{
			ans[V[k][i].second] = k;
			func(V[k][i].first,k);
		}
	}
}

std::pair<int,int> edge[10010];
int x[110];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		edge[i] = std::make_pair(c,d);
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int s = edge[i].first;
		int t = edge[i].second;
		if(x[s]<x[t]) ans[i] = t;
		else if(x[s]>x[t]) ans[i] = s;
		else
		{
			V[s].push_back(std::make_pair(t,i));
			V[t].push_back(std::make_pair(s,i));
		}
	}
	for(int i=1;i<=a;i++) if(check[i]==0) func(i,0);
	
	for(int i=1;i<=b;i++)
	{
		int s = ans[i];
		if(s==edge[i].first) printf("->\n");
		else printf("<-\n");
	}
}
