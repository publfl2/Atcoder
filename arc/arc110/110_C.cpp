#include <stdio.h>
#include <vector>

struct segTree{
	int value[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(value[v]!=0)
			{
				value[2*v] = value[v], value[2*v+1] = value[v];
				value[v] = 0;
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
			if(value[v]!=0)
			{
				value[2*v] = value[v], value[2*v+1] = value[v];
				value[v] = 0;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T;

std::vector<int> V[200010];
std::vector<int> St;
int check[200010];

void func(int k)
{
	if(check[k]) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) func(V[k][i]);
	St.push_back(k);
}

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]<i) T.setValue(x[i],i-2,1);
		if(x[i]>i) T.setValue(i,x[i]-2,-1);
	}
	for(int i=1;i<=a-2;i++)
	{
		int k = T.getValue(i);
		if(k==1) V[i+1].push_back(i);
		if(k==-1) V[i].push_back(i+1);
	}
	
	for(int i=1;i<=a-1;i++) func(i);
	
	for(int i=St.size()-1;i>=0;i--)
	{
		int t = x[St[i]];
		x[St[i]] = x[St[i]+1];
		x[St[i]+1] = t;
	}
	
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=i)
		{
			printf("-1");
			return 0;
		}
	}
	
	for(int i=St.size()-1;i>=0;i--) printf("%d\n",St[i]);
}
