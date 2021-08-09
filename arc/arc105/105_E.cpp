#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
int check[100010];
int func(int k)
{
	if(check[k]) return 0;
	check[k] = 1;
	int sum = 1;
	for(int i=0;i<V[k].size();i++) sum += func(V[k][i]);
	return sum;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) check[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		int C1 = func(1);
		int C2 = func(a);
		for(int i=2;i<a;i++) if(check[i]==0) V2.push_back(func(i));
		for(int i=0;i<4;i++)
		{
			long long int S = i*(i-1)/2 + (long long int)(a-i)*(a-i-1)/2 - b;
			if(S%2==0) win[i] = 0;
			else win[i] = 1;
		}
	}
}
