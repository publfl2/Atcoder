#include <stdio.h>
#include <queue>
#include <vector>

struct str{
	int x0;
	int y0;
	int level;
};
bool operator<(str a, str b)
{
	return a.level>b.level;
}
std::priority_queue<str> Q;

char x[1010][1010];
int check[1010][1010];
int direX[5]={1,0,-1,0}, direY[5] = {0,1,0,-1};

int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	
	for(int i=2;i<=a+1;i++) scanf("%s",x[i]+2);
	for(int i=0;i<=a+3;i++)
	{
		for(int j=0;j<=b+3;j++)
		{
			if(2<=i&&i<=a+1&&2<=j&&j<=b+1) continue;
			x[i][j] = '#';
		}
	}
	
	Q.push({c+1,d+1,1});
	while(!Q.empty())
	{
		int x0 = Q.top().x0;
		int y0 = Q.top().y0;
		int level = Q.top().level;
		
		Q.pop();
		if(check[x0][y0]) continue;
		
		check[x0][y0] = level;
		for(int i=0;i<4;i++)
		{
			if(x[x0+direX[i]][y0+direY[i]]=='#') continue;
			Q.push({x0+direX[i],y0+direY[i],level});
		}
		
		for(int i=-2;i<=2;i++)
		{
			for(int j=-2;j<=2;j++)
			{
				if(x[x0+i][y0+j]=='#') continue;
				Q.push({x0+i,y0+j,level+1});
			}
		}
	}
	
	if(check[e+1][f+1]==0) printf("-1");
	else printf("%d",check[e+1][f+1]-1);
}
