#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <stack>

struct str{
	int x0;
	int y0;
	int z0;
}x1[1010],x2[1010];
std::map<int,int> y1,y2;
int z1[3010],z2[3010];
std::vector<int> V1,V2;

int s = 1, t = 1;
int control = 0;
int check[3010][3010],next[3010][3010][5];
long long int value[3010][3010];
std::stack< std::pair<int,int> > St;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		x1[i] = {c,d,e};
		V1.push_back(c), V1.push_back(d), V2.push_back(e);
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		x2[i] = {c,d,e};
		V1.push_back(c), V2.push_back(d), V2.push_back(e);
	}
	std::sort(V1.begin(),V1.end());
	std::sort(V2.begin(),V2.end());
	
	for(int i=0;i<V1.size();i++) if(y1[V1[i]]==0) y1[V1[i]] = s, z1[s++] = V1[i];
	for(int i=0;i<V2.size();i++) if(y2[V2[i]]==0) y2[V2[i]] = t, z2[t++] = V2[i];
	
	for(int i=0;i<s;i++) for(int j=0;j<t;j++) next[i][j][1] = next[i][j][2] = next[i][j][3] = next[i][j][4] = 1;
	
	// 1234 = URDL
	
	for(int i=1;i<=a;i++)
	{
		int c = y1[x1[i].x0], d = y1[x1[i].y0], e = y2[x1[i].z0];
		for(int j=c;j<d;j++)
		{
			next[j][e-1][2] = 0;
			next[j][e][4] = 0;
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		int c = y1[x2[i].x0], d = y2[x2[i].y0], e = y2[x2[i].z0];
		for(int j=d;j<e;j++)
		{
			next[c-1][j][1] = 0;
			next[c][j][3] = 0;
		}
	}
	
	for(int i=1;i<=s-2;i++) for(int j=1;j<=t-2;j++) value[i][j] = (long long int)(z1[i+1]-z1[i])*(z2[j+1]-z2[j]);
	
	int x0 = -1, y0 = -1;
	
	for(int i=1;i<=s-2;i++)
	{
		if(z1[i]<=0 && 0<=z1[i+1])
		{
			x0 = i;
			break;
		}
	}
	
	for(int i=1;i<=t-2;i++)
	{
		if(z2[i]<=0 && 0<=z2[i+1])
		{
			y0 = i;
			break;
		}
	}
	
	if(x0==-1 || y0==-1)
	{
		printf("INF");
		return 0;
	}
	long long int ans = 0;
	
	St.push(std::make_pair(x0,y0));
	
	while(!St.empty())
	{
		x0 = St.top().first;
		y0 = St.top().second;
		St.pop();
		
		if(x0==0 || x0==s-1)
		{
			control = 1;
			break;
		}
		if(y0==0 || y0==t-1)
		{
			control = 1;
			break;
		}
	
		if(check[x0][y0]) continue;
		check[x0][y0] = 1;
	
		ans += value[x0][y0];
		// 1234 = URDL
		if(next[x0][y0][1]==1) St.push(std::make_pair(x0+1,y0));
		if(next[x0][y0][2]==1) St.push(std::make_pair(x0,y0+1));
		if(next[x0][y0][3]==1) St.push(std::make_pair(x0-1,y0));
		if(next[x0][y0][4]==1) St.push(std::make_pair(x0,y0-1));
	}
	
	if(control==1) printf("INF");
	else printf("%lld",ans);
}
