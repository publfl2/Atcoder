#include <stdio.h>
#include <vector>
#define SIZE 4500

std::vector<int> S[25005010];
int check[25005010];
std::vector< std::pair<int,int> > ans;

int main()
{
	int ans1 = 0, ans2 = 0;
	freopen("output.txt","w",stdout);
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE;j++)
		{
			S[j*j-i+SIZE].push_back(j*j+i);
		}
	}
	
	for(int i=1;i<=SIZE*SIZE+SIZE;i++)
	{
		if(S[i].size()<10) continue;
		
		int count = 0;
		for(int j=0;j<S[i].size();j++)
		{
			if(check[S[i][j]]==0)
			{
				count++;
			}
		}
		if(count>=10)
		{
			ans1++;
			ans2 += count;
			for(int j=0;j<S[i].size();j++)
			{
				if(check[S[i][j]]==0)
				{
					int d = i-SIZE;
					int c = S[i][j];
					check[S[i][j]] = 1;
					ans.push_back(std::make_pair((c-d)/2,(d+c)/2));
				}
			}
		}
	}
	
	//printf("%d %d!!\n",ans1,ans2);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}
