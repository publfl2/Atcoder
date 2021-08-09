#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX 123456789

std::pair<int,int> x[1000010];
struct segTree{
	int value[4000010];
	int index[4000010];
	void update(int k)
	{
		if(value[2*k]>value[2*k+1])
		{
			value[k] = value[2*k];
			index[k] = index[2*k];
		}
		else
		{
			value[k] = value[2*k+1];
			index[k] = index[2*k+1];
		}
	}
	void insert(int ind, int val, int l=1, int r=1000000, int v=1)
	{
		if(l==r)
		{
			value[v] = val;
			index[v] = ind;
		}
		else
		{
			int h = (l+r)/2;
			if(ind<=h) insert(ind,val,l,h,2*v);
			else insert(ind,val,h+1,r,2*v+1);
		}
		update(v);
	}
	int getMax(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return index[v];
		else if(r<L) return -1;
		else if(R<l) return -1;
		else
		{
			int h = (l+r)/2;
			
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			if(s1==-1) return s2;
			else if(s2==-1) return s1;
			else
			{
				if(x[s1].second < x[s2].second) return s2;
				else return s1;
			}
		}
	}
}T;

char y[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		int b = strlen(y+1);
		
		int t = 0;
		int s = 0;
		for(int j=1;j<=b;j++)
		{
			if(y[j]=='(') s--;
			else s++;
			t = t>s?t:s;
		}
		x[i] = std::make_pair(t,-s);
	}
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) T.insert(i,x[i].second);
	
	int limit = 0;
	for(int i=1;i<=a;i++)
	{
		int ans = 0;
		int min = 1, max = a;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h].first<=limit)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		
		int ind = T.getMax(1,ans);
		if(ind==-1)
		{
			printf("No");
			return 0;
		}
		T.insert(ind,-MAX);
		limit += x[ind].second;
	}
	printf("Yes");
}
