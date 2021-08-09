#include <stdio.h>
#include <vector>

std::vector<int> V[2010];
int check[2010];
int func(int k)
{
	if(check[k]) return 0;
	check[k] = 1;
	int ans = 1;
	for(int i=0;i<V[k].size();i++) ans += func(V[k][i]);
	return ans;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) check[j] = 0;
		ans += func(i);
	}
	printf("%d",ans);
}