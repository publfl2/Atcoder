#include <stdio.h>

long long int MAX = 1;
int x[200010],y[200010];
int check[200010];
long long int cost[200010];

int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	long long int p = MAX;
	for(int i=a;i>=1;i--)
	{
		if(x[i]-y[i]<=0)
		{
			check[i] = 1;
			if(x[i]<p) cost[i] = 1;
		}
		else p = p<x[i]-y[i]?p:x[i]-y[i];
	}
	for(int i=a;i>=1;i--) cost[i] += cost[i+1];
	
	
	long long int min = 0, max = MAX;
	long long int ans = MAX;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		int control = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==1)
			{
				long long int k1 = (y[i]-x[i]+1);
				long long int k2 = cost[i+1];
				long long int k = k1>k2?k1:k2;
				if(k<=h) control = 1;
			}
		}
		if(cost[1]<=h) control = 1;
		
		if(control==1)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	printf("%lld",ans);
}
