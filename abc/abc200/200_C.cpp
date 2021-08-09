#include <stdio.h>

int count[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		count[b%200]++;
	}
	
	long long int ans = 0;
	for(int i=0;i<200;i++) ans += (long long int)count[i]*(count[i]-1)/2;
	printf("%lld",ans);
}