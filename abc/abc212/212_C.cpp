#include <stdio.h>
#include <vector>
#include <algorithm>

int x[200010],y[200010];
std::vector< std::pair<int,int> > V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int j=1;j<=b;j++) scanf("%d",&y[j]);
	for(int i=1;i<=a;i++) V.push_back({x[i],1});
	for(int i=1;i<=b;i++) V.push_back({y[i],2});
	std::sort(V.begin(),V.end());
	
	int ans = 1234567890;
	for(int i=0;i+1<V.size();i++)
	{
		if(V[i].second!=V[i+1].second)
		{
			int t = V[i+1].first - V[i].first;
			ans = ans<t?ans:t;
		}
	}
	printf("%d",ans);
}