#include <stdio.h>
#include <vector>
#include <algorithm>

struct segTree{
	int value[1200010];
	int lazy[1200010];
	void addValue(int L, int R, int val, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int x[300010];
std::pair<int,int> y[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=2*a;i++) y[i] = {x[i],i};
	std::sort(y+1,y+2*a+1);
	
	long long int sum = 0;
	double ans = 0;
	for(int i=2*a;i>=1;i--)
	{
		sum += y[i].first;
		if(y[i].second<=a) T.addValue(y[i].second,y[i].second+a-1,1);
		else
		{
			T.addValue(y[i].second,2*a,1);
			T.addValue(1,y[i].second-a-1,1);
		}
		int t = T.getMax(1,2*a);
		double s = (double)sum/t;
		ans = ans>s?ans:s;
		
		if(y[i].second>a) sum += x[y[i].second-a],T.addValue(y[i].second-a,y[i].second-1,1);
		else
		{
			sum += x[y[i].second+a];
			T.addValue(y[i].second+a,2*a,1);
			T.addValue(1,y[i].second-1,1);
		}
		t = T.getMax(1,2*a);
		s = (double)sum/t;
		ans = ans>s?ans:s;
		if(y[i].second>a) sum -= x[y[i].second-a],T.addValue(y[i].second-a,y[i].second-1,-1);
		else
		{
			sum -= x[y[i].second+a];
			T.addValue(y[i].second+a,2*a,-1);
			T.addValue(1,y[i].second-1,-1);
		}
	}
	
	if(ans==(long long int)ans) printf("%lld",(long long int)ans);
	else printf("%lld",(long long int)ans+1);
}