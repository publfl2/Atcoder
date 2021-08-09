#include <stdio.h>
#include <vector>
#include <queue>

struct str{
	int first;
	int second;
	int prev;
};

std::vector<int> V[200010];
std::queue< str > Q;
int check[200010],prev[200010];
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
	
	Q.push({1,1,0});
	while(!Q.empty())
	{
		int x0 = Q.front().first;
		int y0 = Q.front().second;
		int p = Q.front().prev;
		Q.pop();
		
		if(check[x0]) continue;
		check[x0] = y0;
		prev[x0] = p;
		for(int i=0;i<V[x0].size();i++) Q.push({V[x0][i],y0+1,x0});
	}
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			printf("No");
			return 0;
		}
	}
	
	printf("Yes\n");
	for(int i=2;i<=a;i++) printf("%d\n",prev[i]);
}
