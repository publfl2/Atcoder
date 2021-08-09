#include <stdio.h>
#include <vector>
#include <algorithm>

struct segTree{
	std::pair<long long int, long long int> lazy[800010];
	void update(std::pair<long long int, long long int> val, int v)
	{
		long long int s = val.first * lazy[v].first;
		long long int t = val.first * lazy[v].second + val.second;
		lazy[v] = std::make_pair(s,t);
	}
	void setValue(int L, int R, std::pair<long long int, long long int> val, int l=1, int r=200000, int v=1)
	{
		
		if(L<=l&&r<=R) update(val,v);
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			update(lazy[v],2*v);
			update(lazy[v],2*v+1);
			lazy[v] = std::make_pair(1,0);
			
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	
	long long int getValue(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) return lazy[v].second;
		else
		{
			int h = (l+r)/2;
			update(lazy[v],2*v);
			update(lazy[v],2*v+1);
			lazy[v] = std::make_pair(1,0);
			
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T;

std::pair<long long int, long long int> query[200010],x[200010];

long long int ans[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		query[i] = std::make_pair(b,c);
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++) scanf("%lld",&x[i].first);
	for(int i=1;i<=b;i++) x[i].second = i;
	std::sort(x+1,x+b+1);
	
	for(int i=1;i<=b;i++) T.setValue(i,i,{0,x[i].first});
	
	for(int i=1;i<=a;i++)
	{
		if(query[i].second==1) T.setValue(1,b,{1,query[i].first});
		if(query[i].second==2)
		{
			int min = 1, max = b;
			int ans = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getValue(h)<=query[i].first)
				{
					ans = h;
					min = h+1;
				}
				else max = h-1;
			}
			
			T.setValue(1,ans,{0,query[i].first});
		}
		if(query[i].second==3)
		{
			int min = 1, max = b;
			int ans = b+1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getValue(h)>=query[i].first)
				{
					ans = h;
					max = h-1;
				}
				else min = h+1;
			}
			T.setValue(ans,b,{0,query[i].first});
		}
	}
	
	for(int i=1;i<=b;i++) ans[x[i].second] = T.getValue(i);
	for(int i=1;i<=b;i++) printf("%lld\n",ans[i]);
}