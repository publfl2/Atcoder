#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 2000000003

std::vector<int> V[100010];
std::vector< std::pair<int,int> > next[21][100010];
std::map<int,int> hash[100010];

struct str{
	int first;
	int second;
	int time1;
	int time2;
}query[100010];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	for(int i=1;i<=a;i++) V[i].push_back(0);
	for(int i=1;i<=b;i++)
	{
		int d,e,f,g;
		scanf("%d%d%d%d",&d,&e,&f,&g);
		query[i] = {d,e,2*f+1,2*g+1};
		V[d].push_back(2*f+1);
		V[e].push_back(2*g+1);
	}
	for(int i=1;i<=a;i++) V[i].push_back(MAX);
	
	for(int i=1;i<=a;i++)
	{
		std::sort(V[i].begin(),V[i].end());
		V[i].erase(std::unique(V[i].begin(),V[i].end()),V[i].end());
		for(int j=0;j<V[i].size();j++) hash[i][V[i][j]] = j;
		
		for(int k=0;k<=20;k++) next[k][i].resize(V[i].size()+1);
		for(int j=0;j+1<V[i].size();j++) next[0][i][j] = std::make_pair(i,j+1);
		next[0][i][V[i].size()-1] = std::make_pair(i,V[i].size()-1);
	}
	
	for(int i=1;i<=b;i++)
	{
		int s1 = query[i].first;
		int s2 = query[i].second;
		int t1 = query[i].time1;
		int t2 = query[i].time2;
		next[0][s1][hash[s1][t1]] = std::make_pair(s2,hash[s2][t2]);
	}
	
	for(int k=1;k<=20;k++)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				std::pair<int,int> P = next[k-1][i][j];
				next[k][i][j] = next[k-1][P.first][P.second];
			}
		}
	}
	
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		d*=2, f*=2;
		
		int min = 0, max = V[e].size()-1;
		int p = min;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(V[e][h]>=d)
			{
				p = h;
				max = h-1;
			}
			else min = h+1;
		}
		
		if(V[e][p]>f)
		{
			printf("%d\n",e);
			continue;
		}
		
		
		// start : (e,p)
		for(int k=20;k>=0;k--)
		{
			std::pair<int,int> P = next[k][e][p];
			if(V[P.first][P.second]<=f) e = P.first, p = P.second;
		}
		if(next[0][e][p].first == e) printf("%d\n",e);
		else printf("%d %d\n",e,next[0][e][p].first);
	}
	
	
}