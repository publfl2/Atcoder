#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#define MOD 998244353

struct str{
	int x0;
	int y0;
	int z0;
	long long int value;
};
bool operator<(str a, str b)
{
	return a.x0+a.y0+a.z0>b.x0+b.y0+b.z0;
}
std::priority_queue<str> Q;
int a;
long long int power(long long int a, long long int b)
{
	long long int s = 1;
	long long int t = a;
	while(b)
	{
		if(b%2==1) s *= t, s%=MOD;
		t*=t, t%=MOD;
		b/=2;
	}
	return s;
}

std::vector<int> ans[5];
std::set<int> V[5][100010];
int check[100010];
std::pair<int,int> edge[5][100010];
void func(int C)
{
	std::vector<int> V2,V3,V4;
	for(int i=a;i>=1;i--) V2.push_back(i);
	while(V2.size()>0)
	{
		V4.clear();
		V3.clear();
		for(int i=0;i<V2.size();i++) check[V2[i]] = 0;
		for(int i=0;i<V2.size();i++)
		{
			if(check[V2[i]]==0)
			{
				check[V2[i]] = 1;
				V4.push_back(V2[i]);
				std::set<int> ::iterator it;
				for(it=V[C][V2[i]].begin();it!=V[C][V2[i]].end();it++)
				{
					int v;
					if(edge[C][*it].first!=V2[i]) v = edge[C][*it].first;
					else v = edge[C][*it].second;
					check[v] = 1;
					V[C][v].erase(*it);
				}
			}
			else V3.push_back(V2[i]);
		}
		
		long long int sum = 0;
		for(int i=0;i<V4.size();i++)
		{
			sum += power(10,18*V4[i]);
			sum %= MOD;
		}
		ans[C].push_back(sum);
		
		V2.clear();
		V2 = V3;
	}
}

int check1[510][510],check2[510][510],check3[510][510];
int main()
{
	int b,c,d;
	scanf("%d",&a);
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		edge[1][i] = std::make_pair(s,t);
		V[1][s].insert(i);
		V[1][t].insert(i);
	}
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		edge[2][i] = std::make_pair(s,t);
		V[2][s].insert(i);
		V[2][t].insert(i);
	}
	scanf("%d",&d);
	for(int i=1;i<=d;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		edge[3][i] = std::make_pair(s,t);
		V[3][s].insert(i);
		V[3][t].insert(i);
	}
	func(1);
	func(2);
	func(3);
	
	long long int sum = 0;
	for(int i=0;i<ans[1].size()+ans[2].size()-1;i++)
	{
		for(int j=0;j<ans[1].size();j++)
		{
			//j, i-j
			if(i-j<0) continue;
			if(i-j>=ans[2].size()) continue;
			for(int k=0;k<ans[3].size();k++)
			{
				if(check1[j][k]) continue;
				if(check2[i-j][k]) continue;
				long long int s = ans[1][j];
				s *= ans[2][i-j], s%=MOD;
				s *= ans[3][k], s %= MOD;
				sum +=s, sum%=MOD;
				check1[j][k] = check2[i-j][k] = 1;
				break;
			}
		}
	}
	printf("%lld",sum);
}
