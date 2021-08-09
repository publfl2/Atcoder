#include <stdio.h>
#include <queue>
#include <vector>

struct str{
	int first;
	int second;
	int value;
};
bool operator<(str a, str b)
{
	return a.value>b.value;
}
std::priority_queue<str> Q;

int check[510][510];
char x[510][510];
std::vector< std::pair<int,int> > dire1, dire2;

int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	dire1.push_back({1,0});
	dire1.push_back({-1,0});
	dire1.push_back({0,1});
	dire1.push_back({0,-1});
	for(int i=-2;i<=2;i++)
	{
		for(int j=-2;j<=2;j++)
		{
			if(abs(i)==2&&abs(j)==2) continue;
			dire2.push_back({i,j});
		}
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	Q.push({1,1,1});
	while(!Q.empty())
	{
		str A = Q.top();
		Q.pop();
		if(check[A.first][A.second]) continue;
		check[A.first][A.second] = A.value;
		
		for(int i=0;i<dire1.size();i++)
		{
			int s = A.first + dire1[i].first;
			int t = A.second + dire1[i].second;
			if(1<=s&&s<=a&&1<=t&&t<=b&&x[s][t]=='.') Q.push({s,t,A.value});
		}
		for(int i=0;i<dire2.size();i++)
		{
			int s = A.first + dire2[i].first;
			int t = A.second + dire2[i].second;
			if(1<=s&&s<=a&&1<=t&&t<=b) Q.push({s,t,A.value+1});
		}
	}
	printf("%d",check[a][b]-1);
}