#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[100010];
std::vector<int> ans;
int check[100010];
int x[100010];

void func(int k, int prev)
{
	if(check[x[k]]==0) ans.push_back(k);
	check[x[k]]++;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k);
	}
	check[x[k]]--;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	func(1,0);
	std::sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
}