#include <stdio.h>
#include <vector>
#include <algorithm>

struct segTree{
	int value[800010];
	void setValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 200001;
		else if(R<l) return 200001;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T1,T2;

struct str{
	int first;
	int second;
	int index;
	int max;
	int min;
}x[200010];
bool cmp1(str a, str b)
{
	return a.first<b.first;
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}

std::vector<int> V;
int next[200010],size[200010],maxHeight[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i]={b,c,i};
	}
	std::sort(x+1,x+a+1,cmp1);
	for(int i=1;i<=a;i++)
	{
		size[i] = 1;
		next[i] = i;
		maxHeight[x[i].index] = x[i].second;
	}
	
	for(int i=a;i>=1;i--)
	{
		if(V.empty() || maxHeight[V.back()]<x[i].second) V.push_back(x[i].index);
		else
		{
			while(!V.empty())
			{
				int k = V.back();
				if(maxHeight[k]>x[i].second)
				{
					int s = x[i].index;
					while(s!=next[s]) s = next[s];
					if(size[s]<size[k])
					{
						size[k] += size[s];
						next[s] = k;
						maxHeight[k] = maxHeight[k]>maxHeight[s]?maxHeight[k]:maxHeight[s];
					}
					else
					{
						size[s] += size[k];
						next[k] = s;
						maxHeight[s] = maxHeight[k]>maxHeight[s]?maxHeight[k]:maxHeight[s];
					}
					V.pop_back();
				}
				else break;
			}
			int s = x[i].index;
			while(s!=next[s]) s = next[s];
			V.push_back(s);
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int s = i;
		while(s!=next[s]) s = next[s];
		printf("%d\n",size[s]);
	}
}
