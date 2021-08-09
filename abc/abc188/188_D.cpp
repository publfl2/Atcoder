#include <stdio.h>
#include <map>
std::map<int,long long int> event;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		event[c] += e;
		event[d+1] -= e;
	}
	
	long long int ans = 0;
	long long int S = 0;
	std::map<int,long long int> :: iterator it;
	for(it=event.begin();it!=event.end();it++)
	{
		std::map<int,long long int> :: iterator it2 = it;
		it2++;
		if(it2==event.end()) break;
		S += (it->second);
		
		if(S<b) ans += S*(it2->first - it->first);
		else ans += (long long int)b*(it2->first - it->first);
	}
	printf("%lld",ans);
}
