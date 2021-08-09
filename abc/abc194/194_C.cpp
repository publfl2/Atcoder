#include <stdio.h>

int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int sum1 = 0, sum2 = 0;
	for(int i=1;i<=a;i++) sum1 += x[i];
	for(int i=1;i<=a;i++) sum2 += (x[i]*x[i]);
	sum1 *= sum1;
	sum2 *= a;
	printf("%lld",sum2-sum1);
}