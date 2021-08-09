#include <stdio.h>
#include <algorithm>

int x[100010];
long long int sum[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
	
	long long int ans = 2*sum[a];
	for(int i=1;i<=a;i++)
	{
		long long int t = (long long int)(2*i-a) * x[i] + 2*(sum[a]-sum[i]);
		ans = ans<t?ans:t;
	}
	printf("%.12lf",(double)ans/(2*a));
}