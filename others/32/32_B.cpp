#include <stdio.h>
#include <algorithm>

std::pair<int,int> ans[1000010];
int p =1;
int main()
{
	int a;
	scanf("%d",&a);
	if(a%2==0)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				if(i+j==a+1) continue;
				ans[p++] = std::make_pair(i,j);
			}
		}
	}
	else
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				if(i+j==a) continue;
				ans[p++] = std::make_pair(i,j);
			}
		}
	}
	printf("%d\n",p-1);
	for(int i=1;i<p;i++) printf("%d %d\n",ans[i].first,ans[i].second);
}
