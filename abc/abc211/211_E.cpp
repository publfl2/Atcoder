#include <stdio.h>

int a,b;
int func(int s, int t, int bit, int p2, int p3, int left, int k)
{
	int b = (bit/power[t-1])%3;
	if(x[s][t]=='#'||k==0) return func(s,t+1,bit-b*power[t-1],p2,p3,0,k);
	else
	{
		int s1 = func(s,t+1,bit-b*power[t-1],p,0,k);
		if(left==0)
		{
			if(b==0)
			{
				int s2;
				if(p==0) s2 = func(s,t+1,bit+2*power[t-1],1,2,k-1);
				else 
				
			}
		}
	}
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	printf("%lld",func(1,1,0,0,b));
}