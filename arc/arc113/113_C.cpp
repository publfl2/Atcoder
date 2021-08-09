#include <stdio.h>
#include <string.h>

struct segTree{
	int value[800010];
	void setValue(int ind ,int val, int l=1, int r=200001, int v=1)
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
	int getMax(int L, int R, int l=1, int r=200001, int v=1)
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
}T[30];

int DP[30][200010];
int sum[30][200010];
char x[200010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) sum[x[i]-'a'][i]++;
	for(int j=0;j<26;j++) for(int i=1;i<=a;i++) sum[j][i] += sum[j][i-1];
	
	int last = a;
	long long int ans = 0;
	for(int i=a-2;i>=1;i--)
	{
		if(x[i]==x[i+1])
		{
			for(int j=i+2;j<=last;j++) if(x[j]!=x[i]) ans++;
			if(x[last+1]!=x[i]) ans += (a-last);
			last = i;
		}
	}
	printf("%lld",ans);
}