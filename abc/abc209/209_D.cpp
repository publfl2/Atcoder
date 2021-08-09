#include <stdio.h>
#include <vector>

int dist[100010];
std::vector<int> V[100010];
void func(int k ,int prev, int C)
{
	dist[k] = C;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,C+1);
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	func(1,0,0);
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if((dist[c]+dist[d])%2==1) printf("Road\n");
		else printf("Town\n");
	}
}