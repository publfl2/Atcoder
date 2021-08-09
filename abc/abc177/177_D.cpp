#include <stdio.h>
#include <vector>
std::vector<int> V[200010];
int check[200010];

int func(int k)
{
	check[k] = 1;
	int ans = 1;
	for(int i=0;i<V[k].size();i++) if(check[V[k][i]]==0) ans+=func(V[k][i]);
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
		V[d].push_back(c);
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			int S = func(i);
			ans = ans>S?ans:S;
		}
	}
	printf("%d",ans);
}
