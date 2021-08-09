#include <stdio.h>
#include <vector>
std::pair<int,int> P[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i] = std::make_pair(b,c);
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			double d = (double)(P[i].second-P[j].second)/(P[i].first-P[j].first);
			if(-1<=d&&d<=1) ans++;
		}
	}
	printf("%d",ans);
}
