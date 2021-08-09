#include <stdio.h>

long long int x[100010],sum[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + (x[i]-x[i-1]-1);
	
	for(int i=1;i<=b;i++)
	{
		long long int c;
		scanf("%lld",&c);
		int min = 1, max = a;
		int p = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(sum[h]<c)
			{
				p = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%lld\n",(c-sum[p])+x[p]);
	}

}