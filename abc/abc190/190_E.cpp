#include <stdio.h>
#include <vector>
#include <queue>

int dist[500010];
int check[500010][20];
int x[20],y[20][20];
int c;
int func(int bit, int k)
{
	if(bit==(1<<c)-1) return 0;
	if(check[bit][k]) return check[bit][k];
	
	int ans = 1234567890;
	for(int i=1;i<=c;i++)
	{
		if((bit&(1<<(i-1)))==0)
		{
			int t = func(bit+(1<<(i-1)),i) + y[k][i];
			ans = ans<t?ans:t;
		}
	}
	return check[bit][k] = ans;
}

std::vector<int> V[100010];
std::queue<int> Q;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	scanf("%d",&c);
	for(int i=1;i<=c;i++) scanf("%d",&x[i]);
	for(int i=1;i<=c;i++) for(int j=1;j<=c;j++) y[i][j] = -1;
	
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=a;j++) dist[j] = -1;
		Q.push(x[i]);
		dist[x[i]] = 0;
		while(!Q.empty())
		{
			int t = Q.front();
			Q.pop();
			for(int j=0;j<V[t].size();j++)
			{
				if(dist[V[t][j]]==-1)
				{
					dist[V[t][j]] = dist[t]+1;
					Q.push(V[t][j]);
				}
			}
		}
		for(int j=1;j<=c;j++) y[i][j] = dist[x[j]];
	}
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(y[i][j]==-1)
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	int ans = 1234567890;
	for(int i=1;i<=c;i++)
	{
		int t = func(1<<(i-1),i)+1;
		ans = ans<t?ans:t;
	}
	printf("%d",ans);
}
