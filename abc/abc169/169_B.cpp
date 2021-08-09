#include <stdio.h>

long long int MAX = 1;
long long int x[100010];

int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]==0)
		{
			printf("0");
			return 0;
		}
	}
	
	long long int s =1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>=(MAX/s)+1)
		{
			printf("-1");
			return 0;
		}
		s*=x[i];
	}
	printf("%lld",s);
}
