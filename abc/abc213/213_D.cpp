#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> V[200010];
void func(int k, int prev)
{
	printf("%d ",k);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k);
		printf("%d ",k);
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
	for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end());
	
	func(1,0);
}