#include <stdio.h>
#include <vector>

std::vector<int> V[200010],save[200010];
int check[200010];
void func(int k, int C)
{
	if(check[k]) return;
	check[k] = C;
	for(int i=0;i<V[k].size();i++) func(V[k][i],C);
}

int x[200010],y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	int C = 1;
	for(int i=1;i<=a;i++) if(check[i]==0) func(i,C++);
	for(int i=1;i<=a;i++) save[check[i]].push_back(i);
	for(int i=1;i<=a;i++)
	{
		long long int sum = 0;
		for(int j=0;j<save[i].size();j++) sum += (x[save[i][j]] - y[save[i][j]]);
		if(sum!=0)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}
