#include <stdio.h>
#include <set>
#include <map>

std::set<long long int> S;
std::map<long long int,int> check;
long long int x[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) S.insert(x[i]);
	
	long long int ans = 0;
	while(1)
	{
		check.clear();
		std::set<long long int> ::iterator it1, it2;
		it1 = S.begin();
		while(1)
		{
			it2 = S.end();
			it2--;
			if((*it2)<2*(*it1)) break;
			long long int s = (*it1);
			long long int t = (*it2);
			long long int k = (t-s)/s;
			if(check[t%s]==0)
			{
				check[t%s] = 1;
				S.erase(t);
				S.insert(t-k*s);
			}
			else S.erase(t);
		}
		it2 = S.end();
		it2--;
		if(it1==it2) break;
		long long int s = (*it1);
		long long int t = (*it2);
		S.erase(t);
		S.insert(t-s);
	}
	printf("%lld",(*S.begin()));
}
