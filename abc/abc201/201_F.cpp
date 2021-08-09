#include <stdio.h>
#include <vector>
#define MAX (long long int)1e15
#define MAX2 (long long int)3e15
struct segTree{
	long long int value[800010];
	long long int lazy[800010];
	void addValue(int L, int R, long long int val, int l=1 ,int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
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
	long long int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX2;
		else if(R<l) return MAX2;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

struct str{
	int first;
	int second;
	int third;
}y[200010];

int x[200010];
long long int sum1[200010],sum2[200010],value1[200010];
int index[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) index[x[i]] = i;
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		y[i] = {b,b<c?b:c,b<d?b:d};
	}
	for(int i=1;i<=a;i++) sum1[i] = sum1[i-1] + y[i].second;
	for(int i=a;i>=1;i--) sum2[i] = sum2[i+1] + y[i].third;
	
	T.addValue(1,a,MAX);
	for(int i=a;i>=1;i--)
	{
		long long int t1 = T.getMin(index[i]+1,a);
		long long int t2 = sum2[i+1];
		T.addValue(1,a,y[i].first);
		
		long long int t3 = T.getMin(index[i],index[i]);
		T.addValue(index[i],index[i],-t3);
		
		T.addValue(index[i],index[i],t1<t2?t1:t2);
		
		value1[i] = T.getMin(1,a);
	}
	
	
	
	long long int ans = MAX;
	for(int i=1;i<=a+1;i++)
	{
		long long int t = value1[i] + sum1[i-1];
		ans = ans<t?ans:t;
	}
	printf("%lld",ans);
}