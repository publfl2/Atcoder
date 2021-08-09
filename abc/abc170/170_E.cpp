#include <stdio.h>
#include <set>

std::multiset<int> S[200010],S2;
int locate[200010],value[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		S[d].insert(c);
		locate[i] = d;
		value[i] = c;
	}
	
	for(int i=1;i<=200000;i++)
	{
		if(S[i].end()==S[i].begin()) continue;
		std::multiset<int> ::iterator it = S[i].end();
		it--;
		S2.insert(*it);
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		std::multiset<int> ::iterator it,it2;
		
		it = S[locate[c]].end();
		it--;
		it2 = S2.find(*it);
		S2.erase(it2);
		
		if(S[d].begin()!=S[d].end())
		{
			it = S[d].end();
			it--;
			it2 = S2.find(*it);
			S2.erase(it2);
		}
		
		it = S[locate[c]].find(value[c]);
		S[locate[c]].erase(it);
		if(S[locate[c]].begin()!=S[locate[c]].end())
		{
			it = S[locate[c]].end();
			it--;
			S2.insert(*it);
		}
		
		S[d].insert(value[c]);
		it = S[d].end();
		it--;
		S2.insert(*it);
		
		locate[c] = d;
		
		it2 = S2.begin();
		printf("%d\n",*it2);
	}
}
