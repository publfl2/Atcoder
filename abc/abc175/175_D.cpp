#include <stdio.h>
#include <vector>
std::pair<int, long long int> period[5010];
int x[5010],y[5010];
int check[5010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) check[j] = 0;
		
		int C = i;
		long long int S = 0;
		
		for(int j=0;j<=a;j++)
		{
			if(check[C]==1)
			{
				period[i] = std::make_pair(j,S);
				break;
			}
			check[C] = 1;
			C = x[C];
			S += y[C];
		}
	}
	
	long long int ans = -1;
	for(int i=1;i<=18;i++) ans*=10;
	
	for(int i=1;i<=a;i++)
	{
		int C = i;
		long long int S = 0;
		
		for(int j=1;j<=period[i].first;j++)
		{
			if(j>b) break;
			C = x[C];
			S += y[C];
			int t = (b-j)/period[i].first;
			long long int s1 = S;
			long long int s2 = S + t*period[i].second;
			ans = ans>s1?ans:s1;
			ans = ans>s2?ans:s2;
			
		}
	}
	printf("%lld",ans);
}
