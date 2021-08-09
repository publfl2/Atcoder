#include <stdio.h>

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	long long int pos = 0, ans = 0;
	long long int sum = 0, max = 0;
	for(int i=1;i<=a;i++)
	{
		sum += x[i];
		max = max>sum?max:sum;
		ans = ans>pos+max?ans:pos+max;
		pos += sum;
	}
	printf("%lld",ans);
}
