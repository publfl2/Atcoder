#include <stdio.h>
#include <atcoder/maxflow>
#define MAX 123456789

char x[110][110];
int y[110][110];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[i][j]=='B') y[i][j] = 0;
			else if(x[i][j]=='W') y[i][j] = 1;
			else y[i][j] = -1;
		}
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if(y[i][j]!=-1) y[i][j] += (i+j), y[i][j] %= 2;
	
	atcoder::mf_graph<int> G(a*a+2);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<a;j++)
		{
			int s = a*(i-1)+(j-1);
			int t = a*(i-1)+(j);
			G.add_edge(s,t,1);
			G.add_edge(t,s,1);
		}
	}
	for(int j=1;j<=a;j++)
	{
		for(int i=1;i<a;i++)
		{
			int s = a*(i-1)+(j-1);
			int t = a*(i)+(j-1);
			G.add_edge(s,t,1);
			G.add_edge(t,s,1);
		}
	}
	
	int source = a*a, sink = a*a+1;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			int s = a*(i-1)+(j-1);
			if(y[i][j]==0) G.add_edge(source,s,MAX);
			if(y[i][j]==1) G.add_edge(s,sink,MAX);
		}
	}
	
	int t = G.flow(source,sink);
	printf("%d\n",2*a*(a-1)-t);
}