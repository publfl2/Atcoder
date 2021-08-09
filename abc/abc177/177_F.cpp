#include <stdio.h>
#include <vector>

#define MAX 1234567
struct segTree1{
	int value[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1)
			{
				value[2*v] = value[v];
				value[2*v+1] = value[v];
				value[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	int getValue(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) return value[v];
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1)
			{
				value[2*v] = value[v];
				value[2*v+1] = value[v];
				value[v] = -1;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T1;

struct segTree2{
	int value[800010];
	void setValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T2;

struct segTree3{
	int value[800010];
	int lazy[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val, lazy[v] = val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return MAX;
		else if(r<L) return MAX;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T3;

int left[200010],right[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d%d",&left[i],&right[i]);
	for(int i=1;i<=b;i++) T1.setValue(i,i,i);
	T3.setValue(1,b,0);
	
	for(int i=1;i<=a;i++)
	{
		int min = 1, max = b;
		int L = b+1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T1.getValue(h)>=left[i])
			{
				L = h;
				max = h-1;
			}
			else min = h+1;
		}
		
		min = 1, max = b;
		int R = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T1.getValue(h)<=right[i])
			{
				R = h;
				min = h+1;
			}
			else max = h-1;
		}
		
		if(L>R)
		{
			int S = T3.getMin(1,b);
			if(S>=MAX) printf("-1\n");
			else printf("%d\n",i+S);
		}
		else
		{
			T1.setValue(L,R,right[i]+1);
			if(right[i]==b) T3.setValue(L,R,MAX);
			else T3.setValue(L,R,right[i]+1-R);
			
			int S = T3.getMin(1,b);
			if(S>=MAX) printf("-1\n");
			else printf("%d\n",i+S);
		}
	}
}
