#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int ans[200010];
int check[200010];
void func(int k, int prev, int &C)
{
	ans[k] = C++;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(check[V[k][i]]==0)
		{
			func(V[k][i],k,C);
			ans[k] = C++;
		}
	}
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(check[V[k][i]]==1)
		{
			func(V[k][i],k,C);
		}
	}
}

int dist[200010];
void func2(int k, int prev, int d)
{
	dist[k] = d;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func2(V[k][i],k,d+1);
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	func2(1,0,0);
	int s = 1;
	for(int i=1;i<=a;i++) if(dist[i]>dist[s]) s = i;
	func2(s,0,0);
	int t = 1;
	for(int i=1;i<=a;i++) if(dist[i]>dist[t]) t = i;
	int p = t;
	while(p!=s)
	{
		check[p] = 1;
		for(int i=0;i<V[p].size();i++)
		{
			if(dist[V[p][i]]==dist[p]-1)
			{
				p = V[p][i];
				break;
			}
		}
	}
	check[p] = 1;
	
	int C = 1;
	func(s,0,C);
	
	int min = ans[1];
	for(int i=1;i<=a;i++) min = min<ans[i]?min:ans[i];
	min--;
	for(int i=1;i<=a;i++) printf("%d ",ans[i]-min);
}