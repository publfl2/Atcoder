#include <stdio.h>
#include <vector>
int check[100010];
std::vector<int> V[100010];
void func(int k, int C)
{
	check[k] = C;
	for(int i=0;i<V[k].size();i++) if(check[V[k][i]]==0) func(V[k][i],C);
}
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
	
	int C = 1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			func(i,C++);
		}
	}
	printf("%d\n",C-2);
}
