#include <stdio.h>
#include <queue>
#include <vector>
#define MAX (long long int)1e16

long long int dist[510][510][3];
int x[510][510],y[510][510];
struct str{
	int first;
	int second;
	int type;
	long long int value;
};
bool operator<(str a, str b)
{
	return a.value>b.value;
}
std::priority_queue<str> Q;
std::vector<str> V[510][510][3];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<a;i++) for(int j=1;j<=b;j++) scanf("%d",&y[i][j]);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<b;j++)
		{
			V[i][j][0].push_back({i,j+1,0,x[i][j]});
			V[i][j+1][0].push_back({i,j,0,x[i][j]});
		}
	}
	
	for(int j=1;j<=b;j++) for(int i=1;i<a;i++) V[i][j][0].push_back({i+1,j,0,y[i][j]});
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			V[i][j][0].push_back({i,j,1,0});
			V[i][j][1].push_back({i,j,0,1});
		}
	}
	
	for(int j=1;j<=b;j++) for(int i=1;i<a;i++) V[i+1][j][1].push_back({i,j,1,1});
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) for(int k=0;k<=1;k++) dist[i][j][k] = MAX;
	
	Q.push({1,1,0,0});
	while(!Q.empty())
	{
		str A = Q.top();
		Q.pop();
		if(dist[A.first][A.second][A.type]!=MAX) continue;
		dist[A.first][A.second][A.type] = A.value;
		for(int i=0;i<V[A.first][A.second][A.type].size();i++)
		{
			str B = V[A.first][A.second][A.type][i];
			B.value += A.value;
			Q.push(B);
		}
	}
	printf("%lld",dist[a][b][0]);
}