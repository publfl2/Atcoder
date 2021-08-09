#include <stdio.h>
#include <vector>

int x[200010],min[200010];
std::vector<int> V[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
	}
	
	int ans = -1234567890;
	for(int i=1;i<=a;i++) min[i] = 1234567890;
	
	for(int i=1;i<=a;i++)
	{
		if(min[i]!=1234567890) ans = ans>x[i]-min[i]?ans:x[i]-min[i];
		min[i] = min[i]<x[i]?min[i]:x[i];
		for(int j=0;j<V[i].size();j++) min[V[i][j]] = min[V[i][j]]<min[i]? min[V[i][j]]:min[i];
	}
	printf("%d",ans);
}
