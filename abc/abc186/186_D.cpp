#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		ans += (long long int )(2*i-a-1)*x[i];
	}
	printf("%lld",ans);
}
