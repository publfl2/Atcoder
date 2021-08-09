#include <stdio.h>
#include <vector>
#include <algorithm>

long long int S = 0;
std::vector<long long int> V1,V2;
int x[110];

void func(int s, int t, std::vector<long long int> &V)
{
	if(s>t)
	{
		V.push_back(S);
		return;
	}
	
	func(s+1,t,V);
	S += x[s];
	func(s+1,t,V);
	S -= x[s];
}

int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int h = (1+a)/2;
	func(1,h,V1);
	func(h+1,a,V2);
	std::sort(V1.begin(),V1.end());
	std::sort(V2.begin(),V2.end());
	
	long long int ans = 0;
	for(int i=0;i<V1.size();i++)
	{
		int min = 0, max = V2.size();
		while(min<=max)
		{
			int h = (min+max)/2;
			if(V1[i]+V2[h]<=b)
			{
				ans = ans>V1[i]+V2[h]?ans:V1[i]+V2[h];
				min = h+1;
			}
			else max = h-1;
		}
	}
	printf("%lld",ans);
}
