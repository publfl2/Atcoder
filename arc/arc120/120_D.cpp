#include <stdio.h>
#include <algorithm>
#include <set>

int x[400010];
std::pair<int,int> y[400010];
int type[400010];

std::multiset<int> S1,S2;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=2*a;i++) y[i] = {x[i],i};
	std::sort(y+1,y+2*a+1);
	for(int i=1;i<=a;i++) type[y[i].second] = -1;
	for(int i=a+1;i<=2*a;i++) type[y[i].second] = 1;
	
	for(int i=1;i<=2*a;i++)
	{
		if(type[i]==1)
		{
			std::multiset<int> ::iterator it = S2.upper_bound(x[i]);
			if(it==S2.begin())
			{
				printf("(");
				S1.insert(x[i]);
			}
			else
			{
				printf(")");
				it--;
				S2.erase(it);
			}
		}
		else
		{
			std::multiset<int> ::iterator it = S1.lower_bound(x[i]);
			if(it==S1.end())
			{
				printf("(");
				S2.insert(x[i]);
			}
			else
			{
				printf(")");
				S1.erase(it);
			}
		}
	}
}