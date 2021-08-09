#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

int a;
int check[10],x[10];
int weight[10];
int dist[10];
int ans = 1234567890;
std::map<int,int> M;
std::vector< std::pair<int,int> > V;

int getMax(int k)
{
	std::map<int,int> ::iterator it = M.upper_bound(k);
	it--;
	return it->second;
}

void func(int k)
{
	if(k>a)
	{
		ans = ans<dist[a]?ans:dist[a];
		return;
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) continue;
		
		check[i] = 1;
		weight[k] = x[i];
		
		int sum = x[i];
		dist[k] = 0;
		for(int j=k-1;j>=1;j--)
		{
			sum += weight[j];
			int t = getMax(sum-1);
			dist[k] = dist[k]>dist[j]+t?dist[k]:dist[j]+t;
		}
		func(k+1);
		check[i] = 0;
	}
}
int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		for(int j=1;j<=a;j++)
		{
			if(x[j]>d)
			{
				printf("-1");
				return 0;
			}
		}
		V.push_back(std::make_pair(d,c));
	}
	std::sort(V.begin(),V.end());
	M[0] = 0;
	for(int i=0;i<V.size();i++) M[V[i].first] = V[i].second;
	std::map<int,int> ::iterator it;
	int max = 0;
	for(it=M.begin();it!=M.end();it++)
	{
		max = max>it->second?max:it->second;
		M[it->first] = max;
	}
	
	func(1);
	printf("%d",ans);
}
