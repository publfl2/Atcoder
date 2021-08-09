#include <stdio.h>
#include <vector>

std::vector<int> start[210],end[210];
std::vector< std::pair<int,int> > query;
int check[210];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		if(c==1||b==2*a)
		{
			printf("No");
			return 0;
		}
		
		if(b==-1&&c==-1) continue;
		else if(b==-1) end[c-1].push_back(-1);
		else if(c==-1) start[b].push_back(-1);
		else
		{
			if(b>=c)
			{
				printf("No");
				return 0;
			}
			start[b].push_back(c-1);
			end[c-1].push_back(b);
			query.push_back(std::make_pair(b,c-1));
		}
	}
	
	for(int i=0;i<query.size();i++)
	{
		int b = query[i].first;
		int c = query[i].second;
		int dist = c-b+1;
		while(1)
		{
			if(b<1 || c>=2*a)
			{
				printf("No");
				return 0;
			}
			int b2 = b, c2 = c;
			for(int j=b;j<=c;j++)
			{
				while(!end[j].empty())
				{
					int k = end[j].back();
					if(k!=-1&&k!=j-dist+1)
					{
						printf("No");
						return 0;
					}
					b2 = b2<j-dist+1?b2:j-dist+1;
					end[j].pop_back();
				}
			}
			for(int j=b;j<=c;j++)
			{
				while(!start[j].empty())
				{
					int k = start[j].back();
					if(k!=-1&&k!=j+dist-1)
					{
						printf("No");
						return 0;
					}
					c2 = c2>j+dist-1?c2:j+dist-1;
					start[j].pop_back();
				}
			}
			if(b==b2&&c==c2) break;
			b = b2, c = c2;
		}
		if(b<1||c>=2*a)
		{
			printf("No");
			return 0;
		}
		for(int j=b;j<=c;j++)
		{
			if(check[j]>0 && check[j]!=dist)
			{
				printf("No");
				return 0;
			}
			check[j] = dist;
		}
	}
	printf("Yes");
}
