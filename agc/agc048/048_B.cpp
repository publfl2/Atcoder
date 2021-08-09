#include <stdio.h>
#include <set>

struct str{
	long long int first;
	long long int second;
	long long int value;
}P[100010];

std::set< std::pair<long long int,int> > S1,S2;
long long int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) scanf("%lld",&y[i]);
	int b = (a/2);
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		long long int s1 = x[2*i-1] + x[2*i];
		long long int s2 = y[2*i-1] + y[2*i];
		long long int m = s1>s2?s1:s2;
		ans += m;
		long long int t1 = x[2*i-1] + y[2*i];
		long long int t2 = y[2*i-1] + x[2*i];
		P[i] = {t1-m,t2-m,m};
	}
	for(int i=1;i<=b;i++)
	{
		S1.insert(std::make_pair(P[i].first,i));
		S2.insert(std::make_pair(P[i].second,i));
	}
	while(1)
	{
		if(S1.empty()||S2.empty()) break;
		std::set< std::pair<long long int,int> > ::iterator it,it2;
		it = S1.end();
		it--;
		it2 = S2.end();
		it2--;
		
		if((it->second)==(it2->second)) break;
		if((it->first)+(it2->first)<=0) break;
		ans += (it->first)+(it2->first);
		int s = it->second;
		int t = it2->second;
		S1.erase(std::make_pair(P[s].first,s));
		S1.erase(std::make_pair(P[t].first,t));
		S2.erase(std::make_pair(P[s].second,s));
		S2.erase(std::make_pair(P[t].second,t));
	}
	printf("%lld",ans);
}
