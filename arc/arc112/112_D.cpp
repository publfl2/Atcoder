#include <stdio.h>
#include <vector>

std::pair<int,int> next[1010][1010];
std::pair<int,int> find(std::pair<int,int> P)
{
	if(next[P.first][P.second]==P) return P;
	else return next[P.first][P.second] = find(next[P.first][P.second]);
}

char x[1010][1010];
int check[1010][1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	x[1][1] = '#';
	x[1][b] = '#';
	x[a][1] = '#';
	x[a][b] = '#';
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) next[i][j] = std::make_pair(i,j);
	
	int count1 = 0, count2 = 0;
	for(int i=1;i<=a;i++)
	{
		int last = -1;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#')
			{
				if(last!=-1)
				{
					std::pair<int,int> s = std::make_pair(i,last);
					std::pair<int,int> t = std::make_pair(i,j);
					s = find(s);
					t = find(t);
					if(s.first != t.first || s.second != t.second) next[s.first][s.second] = t;
				}
				last = j;
			}
		}
		if(last==-1) count1++;
	}
	
	for(int j=1;j<=b;j++)
	{
		int last = -1;
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]=='#')
			{
				if(last!=-1)
				{
					std::pair<int,int> s = std::make_pair(last,j);
					std::pair<int,int> t = std::make_pair(i,j);
					s = find(s);
					t = find(t);
					if(s.first != t.first || s.second != t.second) next[s.first][s.second] = t;
				}
				last = i;
			}
		}
		if(last==-1) count2++;
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#')
			{
				std::pair<int,int> s = std::make_pair(i,j);
				s = find(s);
				if(s==std::make_pair(i,j) && check[i][j]==0)
				{
					//printf("%d %d??\n",i,j);
					ans++;
					check[i][j] = 1;
				}
			}
		}
	}
	int ans2 = count1<count2?count1:count2;
	if(ans2>0) printf("%d",ans+ans2-1);
	else printf("%d",ans-1);
}