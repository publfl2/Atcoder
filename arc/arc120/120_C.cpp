#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

struct segTree{
	int value[800010];
	void setValue(int ind ,int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L>R) return 0;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;


std::vector<int> index;
std::map<int,int> hash;

std::vector<int> V[200010];
int x[200010],y[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) x[i] += i;
	for(int i=1;i<=a;i++) y[i] += i;
	
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	for(int i=a;i>=1;i--) V[hash[x[i]]].push_back(i);
	
	for(int i=1;i<=a;i++) T.setValue(i,1);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(hash.find(y[i])==hash.end())
		{
			printf("-1");
			return 0;
		}
		if(V[hash[y[i]]].size()==0)
		{
			printf("-1");
			return 0;
		}
		
		int t = V[hash[y[i]]].back();
		V[hash[y[i]]].pop_back();
		
		ans += T.getSum(1,t-1);
		T.setValue(t,0);
	}
	printf("%lld",ans);
}