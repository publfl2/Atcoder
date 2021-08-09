#include <stdio.h>
#include <vector>
#include <queue>

struct str{
	int x0;
	int y0;
	int dist;
	int count;
	int type;
};
bool operator<(str a, str b)
{
	if(a.dist==b.dist) a.count<b.count;
	return a.dist>b.dist;
}
std::priority_queue<str> Q;

std::vector<int> check[1000010],check2[5][1000010];
std::vector<char> x[1000010];
char y[1000010];


int direX[5]={0,1,0,-1},direY[5]={1,0,-1,0};

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int s1,t1,s2,t2;
	scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
	
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i].push_back('@');
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) check[i].push_back(0);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) for(int k=0;k<=4;k++) check2[k][i].push_back(0);
	
	for(int i=1;i<=a;i++)
	{
		scanf("%s", y+1);
		for(int j=1;j<=b;j++) x[i][j] = y[j];
	}
	
	Q.push({s1,t1,1,0,4});
	while(!Q.empty())
	{
		int x0 = Q.top().x0;
		int y0 = Q.top().y0;
		int dist = Q.top().dist;
		int count = Q.top().count;
		int type = Q.top().type;
		Q.pop();
		if(x[x0][y0]=='@') continue;
		
		if(check[x0][y0]>0)
		{
			if(check[x0][y0]==dist && check2[type][x0][y0]==0 && count>0)
			{
				check2[type][x0][y0] = 1;
				Q.push({x0+direX[type],y0+direY[type],dist,count-1,type});
			}
			continue;
		}
		check[x0][y0] = dist;
		check2[type][x0][y0] = 1;
		if(count>0) Q.push({x0+direX[type],y0+direY[type],dist,count-1,type});
		else Q.push({x0+direX[type],y0+direY[type],dist+1,c-1,type});
		for(int i=0;i<4;i++)
		{
			if(i==type) continue;
			Q.push({x0+direX[i],y0+direY[i],dist+1,c-1,i});
		}
	}
	if(check[s2][t2]==0) printf("-1");
	else printf("%d",check[s2][t2]-1);
}
