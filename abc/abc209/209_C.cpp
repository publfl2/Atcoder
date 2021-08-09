#include <stdio.h>
#include <algorithm>
#define MOD 1000000007

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	long long int ans = 1;
	for(int i=1;i<=a;i++)
	{
		ans *= (x[i]-i+1);
		ans %= MOD;
	}
	printf("%lld",ans);
}