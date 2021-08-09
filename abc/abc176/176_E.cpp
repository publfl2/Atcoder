#include <stdio.h>
#include <vector>
#include <set>

std::set<int> S[300010];
std::vector<int> V1,V2;
int count1[300010],count2[300010];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		count1[d]++;
		count2[e]++;
		S[d].insert(e);
	}
	
	int max1 = count1[1];
	for(int i=2;i<=a;i++) max1 = max1>count1[i]?max1:count1[i];
	int max2 = count2[1];
	for(int i=2;i<=b;i++) max2 = max2>count2[i]?max2:count2[i];
	
	for(int i=1;i<=a;i++) if(count1[i]==max1) V1.push_back(i);
	for(int i=1;i<=b;i++) if(count2[i]==max2) V2.push_back(i);
	
	for(int i=0;i<V1.size();i++)
	{
		for(int j=0;j<V2.size();j++)
		{
			if(S[V1[i]].find(V2[j])==S[V1[i]].end())
			{
				printf("%d",max1+max2);
				return 0;
			}
		}
	}
	printf("%d",max1+max2-1);
}
