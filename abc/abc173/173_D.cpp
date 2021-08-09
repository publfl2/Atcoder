#include <stdio.h>
#include <set>
#include <algorithm>

int x[200010];
std::multiset<int> S;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	S.insert(x[a]);
	long long int ans = 0;
	for(int i=a-1;i>=1;i--)
	{
		std::multiset<int> ::iterator it = S.end();
		it--;
		
		ans += (*it);
		S.erase(it);
		S.insert(x[i]);
		S.insert(x[i]);
	}
	printf("%lld",ans);
}
