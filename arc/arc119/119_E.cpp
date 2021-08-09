#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

#define MAX 1234567890
#define MIN 0

//max
struct segTree1{
	int value[1200010];
	void setValue(int ind, int val, int l=1, int r=300000, int v=1)
	{
		if(l==r) value[v] = value[v]>val?value[v]:val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
	void clear(int l=1, int r=300000, int v=1)
	{
		value[v] = MIN;
		if(l==r) return;
		int h = (l+r)/2;
		clear(l,h,2*v);
		clear(h+1,r,2*v+1);
	}
}T1,T4;

struct segTree2{
	int value[1200010];
	void setValue(int ind, int val, int l=1, int r=300000, int v=1)
	{
		if(l==r) value[v] = value[v]<val?value[v]:val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
	void clear(int l=1, int r=300000, int v=1)
	{
		value[v] = MAX;
		if(l==r) return;
		int h = (l+r)/2;
		clear(l,h,2*v);
		clear(h+1,r,2*v+1);
	}
}T2,T3;


std::vector<int> index;
std::map<int,int> hash;
int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	long long int ans = 0;
	
	T1.clear();
	T2.clear();
	T3.clear();
	T4.clear();
	for(int i=a-2;i>=2;i--)
	{
		if(x[i]<x[i+1])
		{
			int t1 = T1.getMax(1,hash[x[i]]);
			int t2 = T2.getMin(hash[x[i+1]],a);
			
			if(t1>=x[i+1]) ans = ans>x[i+1]-x[i]?ans:x[i+1]-x[i];
			else ans = ans>t1-x[i]?ans:t1-x[i];
			
			if(t2<=x[i]) ans = ans>x[i+1]-x[i]?ans:x[i+1]-x[i];
			else ans = ans>x[i+1]-t2?ans:x[i+1]-t2;
			
			T3.setValue(hash[x[i+1]],x[i]);
			T4.setValue(hash[x[i]],x[i+1]);
		}
		else
		{
			int t1 = T3.getMin(hash[x[i]],a);
			int t2 = T4.getMax(1,hash[x[i+1]]);
			
			if(t1<=x[i+1]) ans = ans>x[i]-x[i+1]?ans:x[i]-x[i+1];
			else ans = ans>x[i]-t1?ans:x[i]-t1;
			
			if(t2>=x[i]) ans = ans>x[i]-x[i+1]?ans:x[i]-x[i+1];
			else ans = ans>t2-x[i+1]?ans:t2-x[i+1];
			
			T1.setValue(hash[x[i+1]],x[i]);
			T2.setValue(hash[x[i]],x[i+1]);
		}
	}
	
	T1.clear();
	T2.clear();
	T3.clear();
	T4.clear();
	for(int i=2;i<a-1;i++)
	{
		if(x[i]<x[i+1])
		{
			int t1 = T1.getMax(1,hash[x[i]]);
			int t2 = T2.getMin(hash[x[i+1]],a);
			
			if(t1>=x[i+1]) ans = ans>x[i+1]-x[i]?ans:x[i+1]-x[i];
			else ans = ans>t1-x[i]?ans:t1-x[i];
			
			if(t2<=x[i]) ans = ans>x[i+1]-x[i]?ans:x[i+1]-x[i];
			else ans = ans>x[i+1]-t2?ans:x[i+1]-t2;
			
			T3.setValue(hash[x[i+1]],x[i]);
			T4.setValue(hash[x[i]],x[i+1]);
		}
		else
		{
			int t1 = T3.getMin(hash[x[i]],a);
			int t2 = T4.getMax(1,hash[x[i+1]]);
			
			if(t1<=x[i+1]) ans = ans>x[i]-x[i+1]?ans:x[i]-x[i+1];
			else ans = ans>x[i]-t1?ans:x[i]-t1;
			
			if(t2>=x[i]) ans = ans>x[i]-x[i+1]?ans:x[i]-x[i+1];
			else ans = ans>t2-x[i+1]?ans:t2-x[i+1];
			
			T1.setValue(hash[x[i+1]],x[i]);
			T2.setValue(hash[x[i]],x[i+1]);
		}
	}
	
	long long int sum = 0;
	for(int i=1;i<a;i++)
	{
		if(x[i]<x[i+1]) sum += x[i+1]-x[i];
		else sum += x[i]-x[i+1];
	}
	printf("%lld",sum);
	printf("%lld",sum-2*ans);
}