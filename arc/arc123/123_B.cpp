#include <stdio.h>
#include <algorithm>
#include <set>

int x[100010],y[100010],z[100010];
std::multiset<int> S;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) scanf("%d",&z[i]);
	std::sort(x+1,x+a+1);
	std::sort(y+1,y+a+1);
	std::sort(z+1,z+a+1);
	
	int ans = 0;
	int min = 1, max = a;
	while(min<=max)
	{
		S.clear();
		int h = (min+max)/2;
		for(int i=1;i<=a;i++) S.insert(y[i]);
		
		for(int i=1;i<=h;i++)
		{
			std::multiset<int> ::iterator it = S.lower_bound(x[i]+1);
			if(it==S.end())
			{
				max = h-1;
				goto u;
			}
			if((*it)>=z[i+(a-h)])
			{
				max = h-1;
				goto u;
			}
			S.erase(it);
		}
		ans = h;
		min = h+1;
		u:;
	}
	printf("%d",ans);
}