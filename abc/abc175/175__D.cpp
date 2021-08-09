#include <stdio.h>
#include <vector>

std::pair<int,long long int> next[5010][110];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&next[i][0].first);
	for(int i=1;i<=a;i++) scanf("%lld",&next[i][0].second);
	
	for(int k=1;k<=30;k++)
	{
		for(int i=1;i<=a;i++)
		{
			next[i][k].first = next[next[i][k-1].first][k-1].first;
			next[i][k].second = next[next[i][k-1].first][k-1].second + next[i][k-1].second;
		}
	}
	
	long long int ans = 0;
	
	for(int i=1;i<=a;i++)
	{
		int C = b;
		long long int S = 0;
		int t = i;
		
		for(int k=30;k>=0;k--)
		{
			if(C>=(1<<k))
			{
				C -= (1<<k);
				S += next[t][k].second;
				t = next[t][k].first;
			}
		}
		ans = ans>S?ans:S;
	}
	printf("%lld",ans);
}
