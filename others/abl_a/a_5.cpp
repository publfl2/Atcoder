#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		b/=2;
		s*=s, s%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int sum[200010];
long long int func(int l, int r)
{
	return (sum[r]-sum[l-1]+MOD)%MOD;
}

struct segTree{
	long long int value[800010];
	int lazy[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			lazy[v] = val;
			value[v] = (func(l,r)*val)%MOD;
		}
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] = (func(l,h)*lazy[v])%MOD;
				value[2*v+1] = (func(h+1,r)*lazy[v])%MOD;
				lazy[2*v] = lazy[v];
				lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			
			
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = (value[2*v] + value[2*v+1])%MOD;
		}
	}
	long long int getSum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] = (func(l,h)*lazy[v])%MOD;
				value[2*v+1] = (func(h+1,r)*lazy[v])%MOD;
				lazy[2*v] = lazy[v];
				lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			
			long long int S1 = getSum(L,R,l,h,2*v);
			long long int S2 = getSum(L,R,h+1,r,2*v+1);
			return (S1+S2)%MOD;
		}
	}
}T;


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++) sum[i] = inv(power(10,i));
	for(int i=1;i<=a;i++) sum[i] = (sum[i]+sum[i-1])%MOD;
	
	T.setValue(1,a,1);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		T.setValue(c,d,e);
		long long int S = T.getSum(1,a);
		printf("%lld\n",(S*power(10,a))%MOD);
	}
}
