#include <stdio.h>
#include <vector>

struct segTree{
	long long int value[800010];
	long long int lazy[800010];
	void addValue(int L, int R, long long int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += (r-l+1)*val, lazy[v] += val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v+1] += (r-h)*lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v+1] += (r-h)*lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

int C = 1;
int left[200010],right[200010];
int height[200010];
std::vector<int> V[200010];

int func(int k, int prev, int h)
{
	height[k] = h;
	left[k] = C++;
	right[k] = left[k];
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int s = func(V[k][i],k,h+1);
		right[k] = s;
	}
	return right[k];
}

std::vector< std::pair<int,int> > edge;

int main()
{
	int a;
	scanf("%d",&a);
	edge.push_back(std::make_pair(0,0));
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
		edge.push_back(std::make_pair(b,c));
	}
	func(1,0,1);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		int s,t;
		if(c==1) s = edge[d].first, t = edge[d].second;
		else s = edge[d].second, t = edge[d].first;
		if(height[s]>height[t]) T.addValue(left[s],right[s],e);
		else
		{
			T.addValue(1,a,e);
			T.addValue(left[t],right[t],-e);
		}
	}
	
	for(int i=1;i<=a;i++) printf("%lld\n",T.getSum(left[i],left[i]));
}
