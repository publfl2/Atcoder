#include <stdio.h>

long long int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) x[i]*=2;
	
	long long int min = 1, max = 2000000000;
	long long int ans = 2000000000;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int C = 0;
		for(int i=1;i<=a;i++)
		{
			long long int c = ((x[i]-1)/h)+1;
			C += (c-1);
		}
		if(C>b) min = h+1;
		else
		{
			ans = h;
			max = h-1;
		}
	}
	printf("%lld",(ans+1)/2);
}
