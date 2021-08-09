#include <stdio.h>
#include <algorithm>
#include <vector>
int x[2010];
long long int y[2010];
int a;
struct str{
	int first;
	int second;
};

bool operator<(str a, str b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
std::vector<str> V;
long long int check[2010][2010];
long long int func(int s,int t)
{
	if(s>t) return 0;
	if(check[s][t]) return check[s][t];
	
	int k = (s-1) + (a-t);
	int val = V[a-1-k].first;
	int ind = V[a-1-k].second;
	
	long long int s1 = func(s,t-1) + (long long int)val*(t-ind);
	long long int s2 = func(s+1,t) + (long long int)val*(ind-s);
	return check[s][t] = s1>s2?s1:s2;
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) V.push_back({x[i],i});
	std::sort(V.begin(),V.end());
	
	printf("%lld",func(1,a));
}
