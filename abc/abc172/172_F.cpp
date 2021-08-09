#include <stdio.h>
#include <set>

std::set<long long int> Set[3];
std::pair<int,int> P[50];
long long int x[310];
long long int bit[50];
void func(int type, int start, int end, long long int sum)
{
	if(start<end)
	{
		Set[type].insert(sum);
		return;
	}
	
	sum *=2;
	func(type,start-1,end,sum+P[start].first);
	func(type,start-1,end,sum+P[start].second);
}
int main()
{
	bit[0] = 1;
	for(int i=1;i<=42;i++) bit[i] = 2*bit[i-1];
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	long long int S = 0;
	for(int i=3;i<=a;i++) S^=x[i];
	long long int T = x[1] + x[2];
	
	// T >= S
	int up = 0;
	for(int i=41;i>=0;i--)
	{
		int s = 0, t = 0;
		t = (T/bit[i])%2;
		s = (S/bit[i])%2;
		if(up==0)
		{
			if(s==0&&t==0) up = 0, P[i] = std::make_pair(0,0);
			else if(s==0&&t==1)
			{
				up = 1;
				P[i] = std::make_pair(0,0);
			}
			else if(s==1&&t==0)
			{
				up = 1;
				P[i] = std::make_pair(1,0);
			}
			else if(s==1&&t==1) up = 0, P[i] = std::make_pair(1,0);
		}
		else
		{
			if(s==0&&t==0)
			{
				up = 0;
				P[i] = std::make_pair(1,1);
			}
			else if(s==0&&t==1)
			{
				up = 1;
				P[i] = std::make_pair(1,1);
			}
			else if(s==1&&t==0)
			{
				up = 1;
				P[i] = std::make_pair(1,0);
			}
			else if(s==1&&t==1)
			{
				printf("-1");
				return 0;
			}
		}
	}
	if(up==1)
	{
		printf("-1");
		return 0;
	}
	func(1,41,21,0);
	func(2,20,0,0);
	
	long long int ans = -1;
	for(std::set<long long int> ::iterator it = Set[1].begin() ; it != Set[1].end(); it++)
	{
		long long int val = (*it)*bit[21];
		if(val>x[1]) continue;
		std::set<long long int> ::iterator it2 = Set[2].upper_bound(x[1]-val);
		if(it2==Set[2].begin()) continue;
		it2--;
		val += (*it2);
		ans = ans>val?ans:val;
	}
	if(ans<=0) printf("-1");
	else printf("%lld",x[1]-ans);
}
