#include <stdio.h>
#include <vector>

std::pair<int,int> query[200010];
long long int sum1[200010],sum2[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		query[i] = std::make_pair(c,d);
		if(c==1) sum1[d]++;
		else sum2[d]++;
	}
	
	for(int i=1;i<=a;i++) sum1[i] += sum1[i-1];
	for(int i=1;i<=a;i++) sum2[i] += sum2[i-1];
	
	int H = a-1, W = a-1;
	long long int ans = a-2;
	ans *= (a-2);
	
	for(int i=1;i<=b;i++)
	{
		if(query[i].first==1)
		{
			if(2<=query[i].second&&query[i].second<=W)
			{
				ans -= (sum1[W]-sum1[query[i].second-1])*(H-1);
				W = query[i].second-1;
			}
		}
		else
		{
			if(2<=query[i].second&&query[i].second<=H)
			{
				ans -= (sum2[H]-sum2[query[i].second-1])*(W-1);
				H = query[i].second-1;
			}
		}
	}
	printf("%lld",ans);
}
