#include <stdio.h>
#include <queue>
 
std::queue< std::pair<int,int> > Q;
std::pair<int,int> check1[2010],check2[2010];
int inQueue1[2010],inQueue2[2010];
char x[2010][2010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	for(int i=1;i<=a;i++)
	{
		int S1 = 0, S2 = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='.') S1++;
			else S2++;
		}
		check1[i] = std::make_pair(S1,S2);
	}
	
	for(int j=1;j<=b;j++)
	{
		int S1 = 0, S2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]=='.') S1++;
			else S2++;
		}
		check2[j] = std::make_pair(S1,S2);
	}
	
	for(int i=1;i<=a;i++)
	{
		if(check1[i].first==0 || check1[i].second==0)
		{
			inQueue1[i] = 1;
			Q.push(std::make_pair(1,i));
		}
	}
	
	for(int j=1;j<=b;j++)
	{
		if(check2[j].first==0||check2[j].second==0)
		{
			inQueue2[j] = 1;
			Q.push(std::make_pair(2,j));
		}
	}
	
	int ans = 0;
	while(!Q.empty())
	{
		int s = Q.front().first;
		int t = Q.front().second;
		Q.pop();
		
		if(s==1) if(check1[t].first==0 && check1[t].second==0) continue;
		if(s==2) if(check2[t].first==0 && check2[t].second==0) continue;
		
		ans++;
		if(s==1)
		{
			char k;
			if(check1[t].first>0) k = '.';
			else k = '#';
			for(int j=1;j<=b;j++)
			{
				if(x[t][j]==k)
				{
					if(k=='.') check2[j].first--;
					else check2[j].second--;
				}
				if(inQueue2[j]==0 && (check2[j].first==0 || check2[j].second==0))
				{
					inQueue2[j] = 1;
					Q.push(std::make_pair(2,j));
				}
			}
		}
		else
		{
			char k;
			if(check2[t].first>0) k = '.';
			else k = '#';
			for(int i=1;i<=a;i++)
			{
				if(x[i][t]==k)
				{
					if(k=='.') check1[i].first--;
					else check1[i].second--;
				}
				if(inQueue1[i]==0 && (check1[i].first==0 || check1[i].second==0))
				{
					inQueue1[i] = 1;
					Q.push(std::make_pair(1,i));
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(inQueue1[i]==0)
		{
			printf("%d",ans);
			return 0;
		}
	}
	for(int j=1;j<=b;j++)
	{
		if(inQueue2[j]==0)
		{
			printf("%d",ans);
			return 0;
		}
	}
	printf("%d",a+b-1);
}