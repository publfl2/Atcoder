#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 12345678

struct segTree{
	int value[800010];
	int lazy[800010];
	void addValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] += val;
			lazy[v] += val;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

std::vector< std::pair<int,int> > V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V.push_back({b,a-i+1});
	}
	for(int i=a+1;i<=2*a;i++)
	{
		int b;
		scanf("%d",&b);
		V.push_back({b,i-a});
	}
	std::sort(V.begin(),V.end());
	
	for(int i=1;i<=a;i++) T.addValue(i,a,1);
	
	long long int ans = 0;
	for(int i=V.size()-1;i>=0;i--)
	{
		if(T.getMin(V[i].second,a)>0)
		{
			T.addValue(V[i].second,a,-1);
			ans += V[i].first; 
		}
	}
	printf("%lld",ans);
}