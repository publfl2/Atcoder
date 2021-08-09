#include <stdio.h>
#include <map>
#include <stack>

struct str{
	int s;
	int t;
	long long int k;
	int level;
};
std::stack<str> St;

std::map<int,long long int> V[260030];
int check[260010];
std::pair<int,int> x[260010];

long long int func2(int s, int t)
{
	if(check[s]==1)
	{
		std::map<int,long long int> ::iterator it = V[s].upper_bound(t);
		it--;
		return (it->second);
	}
	
	long long int s1 = func2(s/2,t);
	long long int s2 = 0;
	if(t>=x[s].first) s2 = func2(s/2,t-x[s].first)+x[s].second;
	return s1>s2?s1:s2;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].second,&x[i].first);
	
	for(int i=0;i<=1023;i++) V[i][0] = 0;
	St.push({1,0,0,10});
	while(!St.empty())
	{
		int s = St.top().s;
		int t = St.top().t;
		long long int k = St.top().k;
		int level = St.top().level;
		St.pop();
		
		if(level==0) continue;
		check[s] = 1;
	
		V[s][t] = V[s][t]>k?V[s][t]:k;
		St.push({2*s,t,k,level-1});
		St.push({2*s+1,t,k,level-1});
		
		
		t += x[s].first, k += x[s].second;
		if(t>100000) continue;
		
		V[s][t] = V[s][t]>k?V[s][t]:k;
		St.push({2*s,t,k,level-1});
		St.push({2*s+1,t,k,level-1});
	}
	
	for(int i=1;i<=1023;i++)
	{
		long long int val = 0;
		for(std::map<int,long long int> ::iterator it = V[i].begin();it!=V[i].end();it++)
		{
			val = val>(it->second)?val:(it->second);
			V[i][it->first] = val;
		}
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(check[c]==1)
		{
			std::map<int,long long int> ::iterator it = V[c].upper_bound(d);
			it--;
			printf("%lld\n",it->second);
		}
		else printf("%lld\n",func2(c,d));
	}
}
