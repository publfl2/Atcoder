#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#define MOD 998244353

struct segTree{
	long long int lazy[2000010];
	long long int sum1[2000010],sum2[2000010];
	void setValue1(int L, int R, long long int val, int l=1, int r=500001, int v=1)
	{
		if(L<=l&&r<=R)
		{
			lazy[v] = val;
			sum1[v] = val*sum2[v], sum1[v] %= MOD;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				sum1[2*v] = lazy[v]*sum2[2*v], sum1[2*v+1] = lazy[v]*sum2[2*v+1];
				sum1[2*v] %= MOD, sum1[2*v+1] %= MOD;
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			setValue1(L,R,val,l,h,2*v);
			setValue1(L,R,val,h+1,r,2*v+1);
			sum1[v] = sum1[2*v] + sum1[2*v+1], sum1[v] %= MOD;
		}
	}
	void setValue2(int ind, long long int val1, long long int val2, int l=1, int r=500001, int v=1)
	{
		if(l==r)
		{
			if(ind%2==1)
			{
				sum1[v] = -val1*val2, sum1[v] %= MOD, sum1[v] += MOD, sum1[v] %= MOD;
				sum2[v] = -val2, sum2[v] += MOD, sum2[v] %= MOD;
			}
			else
			{
				sum1[v] = val1*val2, sum1[v] %= MOD;
				sum2[v] = val2;
			}
		}
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				sum1[2*v] = lazy[v]*sum2[2*v], sum1[2*v+1] = lazy[v]*sum2[2*v+1];
				sum1[2*v] %= MOD, sum1[2*v+1] %= MOD;
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			if(ind<=h) setValue2(ind,val1,val2,l,h,2*v);
			else setValue2(ind,val1,val2,h+1,r,2*v+1);
			sum1[v] = sum1[2*v] + sum1[2*v+1], sum1[v] %= MOD;
			sum2[v] = sum2[2*v] + sum2[2*v+1], sum2[v] %= MOD;
		}
	}
	
	long long int getSum(int L, int R, int l=1, int r=500001, int v=1)
	{
		if(L<=l&&r<=R) return sum1[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				sum1[2*v] = lazy[v]*sum2[2*v], sum1[2*v+1] = lazy[v]*sum2[2*v+1];
				sum1[2*v] %= MOD, sum1[2*v+1] %= MOD;
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return (s1+s2)%MOD;
		}
	}
}T;

int x[500010];
long long int ans[500010];
std::pair<int,int> y[500010];
std::set<int> S;
int next[500010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i],i);
	std::sort(y+1,y+a+1);
	
	S.insert(a+1);
	for(int i=1;i<=a;i++)
	{
		std::set<int> ::iterator it = S.lower_bound(y[i].second);
		next[y[i].second] = (*it);
		S.insert(y[i].second);
	}
	
	ans[a+1] = 1;
	for(int i=a;i>=1;i--)
	{
		T.setValue2(i,x[i],ans[i+1]);
		T.setValue1(i,next[i]-1,x[i]);
		if(i%2==1) ans[i] = (MOD-T.getSum(i,a))%MOD;
		else ans[i] = T.getSum(i,a);
	}
	
	printf("%lld",ans[1]);
}