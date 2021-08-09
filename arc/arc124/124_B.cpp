#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <atcoder/maxflow>

int x[2010],y[2010];
std::vector<int> ans;
std::multiset<int> S;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int j=1;j<=a;j++) scanf("%d",&y[j]);
	
	for(int j=1;j<=a;j++)
	{
		S.clear();
		for(int i=1;i<=a;i++)
		{
			if(i==j) continue;
			S.insert(y[i]);
		}
		int t = x[1]^y[j];
		for(int i=2;i<=a;i++)
		{
			std::multiset<int> ::iterator it = S.find(x[i]^t);
			if(it==S.end()) goto u;
			else S.erase(it);
		}
		ans.push_back(t);
		u:;
	}
	
	std::sort(ans.begin(),ans.end());
	ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
}