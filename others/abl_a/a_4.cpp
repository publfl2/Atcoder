#include <stdio.h>
struct segTree{
	int value[1200010];
	void setValue(int ind, int val, int l=0, int r=300000, int v=1)
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
	int getMax(int L, int R, int l=0, int r=300000, int v=1)
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
}T;

int x[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		int L = x[i]-b>=0?x[i]-b:0;
		int R = x[i]+b<=300000?x[i]+b:300000;
		int value = T.getMax(L,R);
		T.setValue(x[i],value+1);
	}
	printf("%d",T.getMax(0,300000));
}
