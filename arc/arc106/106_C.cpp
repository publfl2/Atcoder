#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1&&b==0)
	{
		printf("1 2");
		return 0;
	}
	if(b<0) printf("-1");
	else if(b==a) printf("-1");
	else
	{
		int s = b+1;
		int t = a-(1+s);
		if(t<0) printf("-1");
		else
		{
			ans.push_back(std::make_pair(1,2*s+2));
			for(int i=1;i<=s;i++) ans.push_back(std::make_pair(2*i,2*i+1));
			int C = 2*s+2;
			for(int i=1;i<=t;i++) ans.push_back(std::make_pair(C+2*i-1,C+2*i));
			for(int i=0;i<ans.size();i++)
			{
				printf("%d %d\n",ans[i].first,ans[i].second);
			}
		}
	}
}
