#include <stdio.h>
#include <vector>
#define MAX 1234567890

int a;
int x[200010],ans[200010];
std::vector<int> V[200010];
std::vector<int> A[200010];
void func(int k, int prev)
{
	int min = 1, max = a;
	int p = 0;
	
	while(min<=max)
	{
		int h = (min+max)/2;
		if(A[h][A[h].size()-1] >= x[k])
		{
			p = h;
			max = h-1;
		}
		else min = h+1;
	}
	A[p].push_back(x[k]);
	
	min = 1, max = a;
	int p2 = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(A[h][A[h].size()-1] != MAX)
		{
			p2 = h;
			min = h+1;
		}
		else max = h-1;
	}
	ans[k] = p2;
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k);
	}
	A[p].pop_back();
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) A[i].push_back(MAX);
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	func(1,0);
	for(int i=1;i<=a;i++) printf("%d\n",ans[i]);
}
