#include <stdio.h>
#include <algorithm>
#include <string.h>
char s[1000010];
int SA[1000010],tmp[1000010],order[1000010],n;
int rank[1000010],LCP[1000010];
int gap;
bool cmp(int a, int b)
{
    if(order[a] != order[b]) return order[a] < order[b];
    int x = a + gap;
    int y = b + gap;
    return ((x < n && y < n) ? order[x] < order[y] : x > y);
}
void makeSA()
{
    for(int i=0; i<n; i++) order[i] = s[i]-'a'+1, SA[i] = i;
    for(gap=1;;gap*=2)
    {
        std::sort(SA, SA+n, cmp);
        tmp[0] = 0;
        for(int i=0;i<n-1;i++) tmp[i+1] = tmp[i] + cmp(SA[i], SA[i+1]);
        if(tmp[n-1] == n-1) break;
        for(int i=0;i<n;i++) order[SA[i]] = tmp[i];
    }
}
void makeLCP()
{
    int j,k = 0;
    for(int i=0;i<n;i++) rank[SA[i]] = i;
    for(int i=0;i<n;i++)
    {
        if(k>0) k--;
        if(rank[i]==n-1)
        {
            k = 0;
            LCP[rank[i]] = 0;
            continue;
        }
        int j = SA[rank[i]+1];
        while( (i+k)<n && (j+k)<n && s[i+k]==s[j+k]) k++;
        LCP[rank[i]] = k;
    }
}

struct segTree{
	long long int value[4000010];
	long long int lazy[4000010];
	long long int min[4000010];
	void setValue(int L, int R, long long int val, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) min[v] = val, value[v] = (r-l+1)*val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				min[2*v] = lazy[v], min[2*v+1] = lazy[v];
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
			min[v] = min[2*v]<min[2*v+1]?min[2*v]:min[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				min[2*v] = lazy[v], min[2*v+1] = lazy[v];
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
	
	int binarySearch(int val, int l=1, int r=1000000, int v=1)
	{
		if(l==r)
		{
			if(min[v]>=val) return r;
			else return r+1;
		}
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				min[2*v] = lazy[v], min[2*v+1] = lazy[v];
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			
			if(min[2*v+1]>=val) return binarySearch(val,l,h,2*v);
			else return binarySearch(val,h+1,r,2*v+1);
		}
		// T[h]>=val
	}
}T1,T2;

long long int ans[1000010];
int main()
{
	scanf("%d",&n);
    scanf("%s",s);
    makeSA();
    makeLCP();
    
    for(int i=n-1;i>=1;i--) LCP[i] = LCP[i-1];
    LCP[0] = 0;
    
    T1.setValue(1,1000000,12345678);
    T2.setValue(1,1000000,12345678);
    
    for(int i=n-2;i>=0;i--)
	{
		int p = T1.binarySearch(LCP[i+1]);
		T1.setValue(p,(n-2)-i+1,LCP[i+1]);
		ans[SA[i]] += T1.getSum(1,(n-2)-i+1);
	}
	
	for(int i=1;i<n;i++)
	{
		int p = T2.binarySearch(LCP[i]);
		T2.setValue(p,i,LCP[i]);
		ans[SA[i]] += T2.getSum(1,i);
	}
	
	for(int i=0;i<n;i++) ans[i] += (n-i);
	
	for(int i=0;i<n;i++) printf("%lld\n",ans[i]);
}