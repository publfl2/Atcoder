#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
struct str{
	int x0;
	int y0;
}x[200010];
bool cmp1(str a, str b)
{
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	return a.y0>b.y0;
}

std::vector<str> V1,V2;
std::set<int> S1,S2;
long long int y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S1.clear();
		S2.clear();
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			if(c>d) V1.push_back({b,c-d}), ans += c;
			else V2.push_back({a-b,d-c}), ans += d;
		}
		
		std::sort(V1.begin(),V1.end(),cmp1);
		int size1 = 0;
		for(int i=0;i<V1.size();i++) if(V1[i].x0>=size1+1) size1++;
		
		for(int i=1;i<=size1;i++) S1.insert(i);
		std::sort(V1.begin(),V1.end(),cmp2);
		for(int i=0;i<V1.size();i++)
		{
			std::set<int> ::iterator it = S1.upper_bound(V1[i].x0);
			if(it==S1.begin())
			{
				ans -= V1[i].y0;
				continue;
			}
			it--;
			S1.erase(it);
		}
		
		std::sort(V2.begin(),V2.end(),cmp1);
		int size2 = 0;
		for(int i=0;i<V2.size();i++) if(V2[i].x0>=size2+1) size2++;
		
		for(int i=1;i<=size2;i++) S2.insert(i);
		std::sort(V2.begin(),V2.end(),cmp2);
		for(int i=0;i<V2.size();i++)
		{
			std::set<int> ::iterator it = S2.upper_bound(V2[i].x0);
			if(it==S2.begin())
			{
				ans -= V2[i].y0;
				continue;
			}
			it--;
			S2.erase(it);
		}
		
		printf("%lld\n",ans);
	}
}
