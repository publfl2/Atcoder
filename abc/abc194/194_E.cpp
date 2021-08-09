#include <stdio.h>
#include <set>

int x[1500010];
std::set<int> S;
int count[1500010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=0;i<=a;i++) S.insert(i);
	
	for(int i=1;i<=b;i++)
	{
		count[x[i]]++;
		if(count[x[i]]==1) S.erase(x[i]);
	}
	
	std::set<int> ::iterator it = S.begin();
	int ans = (*it);
	
	for(int i=2;i+b-1<=a;i++)
	{
		count[x[i-1]]--;
		if(count[x[i-1]]==0) S.insert(x[i-1]);
		count[x[i+b-1]]++;
		if(count[x[i+b-1]]==1) S.erase(x[i+b-1]);
		it = S.begin();
		int t = (*it);
		ans = ans<t?ans:t;
	}
	
	printf("%d",ans);
}