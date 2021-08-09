#include <stdio.h>
#include <atcoder/maxflow>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	atcoder::mf_graph<int> G(3+a+b+2*c);
	int source = a+b+2*c+1, sink = a+b+2*c+2;
	for(int i=1;i<=a;i++) G.add_edge(source,i,1);
	for(int j=1;j<=b;j++) G.add_edge(a+2*c+j,sink,1);
	
	for(int i=1;i<=c;i++)
	{
		G.add_edge(a+i,a+c+i,1);
		int d,e,f,g;
		scanf("%d%d%d%d",&d,&e,&f,&g);
		for(int j=d;j<=f;j++) G.add_edge(j,a+i,1);
		for(int j=e;j<=g;j++) G.add_edge(a+c+i,a+2*c+j,1);
	}
	
	printf("%d",G.flow(source,sink));
}