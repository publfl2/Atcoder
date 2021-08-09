#include <stdio.h>
#include <vector>
#include <queue>

std::vector< std::pair<int,int> > V[30];
char x[2020][2020];
int direX[5]={1,0,-1,0}, direY[5]={0,1,0,-1};

std::queue< std::pair<int,int> > Q;
int dist[2020][2020],color[30];
std::pair<int,int> P;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='S')
			{
				dist[i][j] = 1;
				Q.push(std::make_pair(i,j));
			}
			if(x[i][j]=='G') P =std::make_pair(i,j);
			if('a'<=x[i][j]&&x[i][j]<='z') V[x[i][j]-'a'].push_back(std::make_pair(i,j));
		}
	}
	
	while(!Q.empty())
	{
		int s = Q.front().first;
		int t = Q.front().second;
		Q.pop();
		if(x[s][t]=='#') continue;
		if(s<1) continue;
		if(t<1) continue;
		if(s>a) continue;
		if(t>b) continue;
		
		for(int i=0;i<4;i++)
		{
			int s0 = s+direX[i];
			int t0 = t+direY[i];
			if(x[s0][t0]!='#'&&dist[s0][t0]==0)
			{
				dist[s0][t0] = dist[s][t] + 1;
				Q.push(std::make_pair(s0,t0));
			}
		}
		if('a'<=x[s][t]&&x[s][t]<='z'&&color[x[s][t]-'a']==0)
		{
			color[x[s][t]-'a'] = 1;
			for(int i=0;i<V[x[s][t]-'a'].size();i++)
			{
				int s0 = V[x[s][t]-'a'][i].first;
				int t0 = V[x[s][t]-'a'][i].second;
				if(x[s0][t0]!='#'&&dist[s0][t0]==0)
				{
					dist[s0][t0] = dist[s][t] + 1;
					Q.push(std::make_pair(s0,t0));
				}
			}
		}
	}
	
	if(dist[P.first][P.second]==0) printf("-1");
	else printf("%d",dist[P.first][P.second]-1);
}
