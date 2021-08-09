#include <stdio.h>
#include <queue>

struct str{
	int x0;
	int y0;
	int dist;
};
bool operator<(str a, str b)
{
	return a.dist>b.dist;
}

std::priority_queue<str> Q;
int x[2500010],check[510][510],check2[510][510];
int direX[5]={1,0,-1,0},direY[5]={0,1,0,-1};
int main()
{
	freopen("input.txt","r",stdin);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a*a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			int s1 = (i-1)<(a-i)?(i-1):(a-i);
			int s2 = (j-1)<(a-j)?(j-1):(a-j);
			check[i][j] = s1<s2?s1:s2;
			check2[i][j] = 1;
		}
	}
	
	long long int sum = 0;
	for(int i=1;i<=a*a;i++)
	{
		int s = (x[i]-1)/a+1;
		int t = (x[i]-1)%a+1;
		check2[s][t] = 0;
		sum += check[s][t];
		
		for(int j=0;j<4;j++)
		{
			if(check[s][t] < check[s+direX[j]][t+direY[j]])
			{
				check[s+direX[j]][t+direY[j]] = check[s][t];
				Q.push({s+direX[j],t+direY[j],check[s][t]});
			}
		}
		while(!Q.empty())
		{
			int x0 = Q.top().x0;
			int y0 = Q.top().y0;
			int dist = Q.top().dist;
			Q.pop();
			
			for(int j=0;j<4;j++)
			{
				if(check[x0][y0]+check2[x0][y0] < check[x0+direX[j]][y0+direY[j]])
				{
					check[x0+direX[j]][y0+direY[j]] = check[x0][y0]+check2[x0][y0];
					Q.push({x0+direX[j],y0+direY[j],check[x0][y0]+check2[x0][y0]});
				}
			}
		}
	}
	printf("%lld",sum);
}
