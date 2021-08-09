#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 1234567890

struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	if(a.second==b.second) return a.first>b.first;
	return a.second>b.second;
}
std::priority_queue<str> Q;

int a;
std::vector< std::pair<int,int> > V[2010];
int dist[2010];
int func(int k)
{
	for(int i=1;i<=a;i++) dist[i] = MAX;
	for(int i=0;i<V[k].size();i++) Q.push({V[k][i].first,V[k][i].second});
	while(!Q.empty())
	{
		int s = Q.top().first;
		int t = Q.top().second;
		Q.pop();
		if(dist[s]!=MAX) continue;
		dist[s] = t;
		for(int i=0;i<V[s].size();i++) Q.push({V[s][i].first,V[s][i].second+t});
	}
	return dist[k];
}
int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
	}
	for(int i=1;i<=a;i++)
	{
		int t = func(i);
		if(t==MAX) printf("-1\n");
		else printf("%d\n",t);
	}
}
