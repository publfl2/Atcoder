#include <stdio.h>

long long int x[200010];
long long int sum[200010],sum2[200010],max[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
	for(int i=1;i<=a;i++) sum2[i] = sum2[i-1] + sum[i];
	
	max[1] = x[1];
	for(int i=1;i<=a;i++) max[i] = max[i-1]>x[i]?max[i-1]:x[i];
	
	for(int i=1;i<=a;i++)
	{
		long long int S = sum[i] + sum2[i-1] + i*max[i];
		printf("%lld\n",S);
	}
}