#include <stdio.h>
#include <vector>

std::vector<int> V[400010];
int check[400010];
int S;
int func(int k, int prev)
{
	check[k] = 1;
	int control = 0;
	int ans = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev)
		{
			if(control==0) control = 1;
			else S++;
		}
		else if(check[V[k][i]]==1) S++;
		else ans += func(V[k][i],k)+1;
	}
	return ans;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	int ans = 0;
	for(int i=1;i<=400000;i++)
	{
		if(check[i]==0)
		{
			S = 0;
			ans += func(i,0);
			if(S>0) ans++;
		}
	}
	printf("%d",ans);
}
