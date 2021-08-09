#include <stdio.h>
#include <queue>
#define MAX 123456789
int dist[1010][3];

struct str{
	int x0;
	int y0;
	int value;
};
bool operator<(str a, str b)
{
	return a.value>b.value;
}
std::priority_queue<str> Q;

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	for(int i=1;i<=1000;i++) dist[i][0] = dist[i][1] = MAX;
	Q.push({a,0,0});
	while(!Q.empty())
	{
		int s = Q.top().x0;
		int t = Q.top().y0;
		int k = Q.top().value;
		Q.pop();
		if(s<1) continue;
		if(s>100) continue;
		
		if(dist[s][t]!=MAX) continue;
		dist[s][t] = k;
		
		Q.push({s+2*t-1,1-t,k+c});
		Q.push({s,1-t,k+c});
		Q.push({s+1,t,k+d});
		Q.push({s-1,t,k+d});
	}
	printf("%d",dist[b][1]);
}
