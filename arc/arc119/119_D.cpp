#include <stdio.h>
#include <vector>

struct str{
	int first;
	int second;
	int value;
};
std::vector<str> ans;

char x[2510][2510];
int check1[2510],check2[2510];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	int s1,s2;
	
	s1 = 0, s2 = 0;
	for(int i=1;i<=a;i++)
	{
		int control = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='R')
			{
				if(check1[j]==1) control = 1;
				else check1[j] = 1, s1++;
			}
		}
		s2 += control;
	}
	int ans1 = s1*a + s2*b - s1*s2;
	
	s1 = 0, s2 = 0;
	for(int j=1;j<=b;j++)
	{
		int control = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]=='R')
			{
				if(check2[i]==1) control = 1;
				else check2[i] = 1, s2++;
			}
		}
		s1 += control;
	}
	int ans2 = s1*a + s2*b - s1*s2;
	
	if(ans1>=ans2)
	{
		for(int j=1;j<=b;j++) check1[j] = 0;
		for(int i=1;i<=a;i++)
		{
			int control = 0;
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='R')
				{
					if(check1[j]==1)
					{
						if(control==0)
						{
							control = 1;
							ans.push_back({i,j,1});
						}
					}
				}
			}
			
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='R')
				{
					if(check1[j]==0)
					{
						check1[j] = 1;
						ans.push_back({i,j,2});
					}
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=a;i++) check2[i] = 0;
		for(int j=1;j<=b;j++)
		{
			int control = 0;
			for(int i=1;i<=a;i++)
			{
				if(x[i][j]=='R')
				{
					if(check2[i]==1)
					{
						if(control==0)
						{
							control = 1;
							ans.push_back({i,j,2});
						}
					}
				}
			}
			
			for(int i=1;i<=a;i++)
			{
				if(x[i][j]=='R')
				{
					if(check2[i]==0)
					{
						check2[i] = 1;
						ans.push_back({i,j,1});
					}
				}
			}
		}
	}
	
	printf("%d\n",ans.size());
	while(!ans.empty())
	{
		str A = ans.back();
		ans.pop_back();
		if(A.value==1) printf("X %d %d\n",A.first,A.second);
		else printf("Y %d %d\n",A.first,A.second);
	}
}