#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	long long int ans = 0;
	for(int i=1;i<a;i++)
	{
		int s = 1;
		int t = (a-1)/i;
		ans += (t-s+1);
	}
	printf("%lld",ans);
}
