#include <stdio.h>
#include <vector>

int check[4000010],temp[4000010];
std::vector<int> V[4000010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
	}
	
	check[a] = 1;
	for(int i=1;i<=2*a;i++)
	{
		for(int j=0;j<V[i].size();j++) temp[V[i][j]] = 0;
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j]-1>=0 && check[V[i][j]-1]==1) temp[V[i][j]] = 1;
			if(V[i][j]+1<=2*a && check[V[i][j]+1]==1) temp[V[i][j]] = 1;
		}
		for(int j=0;j<V[i].size();j++) check[V[i][j]] = temp[V[i][j]];
	}
	
	int ans = 0;
	for(int j=0;j<=2*a;j++) ans += check[j];
	printf("%d",ans);
}