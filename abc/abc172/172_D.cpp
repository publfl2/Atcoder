#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	long long int s = 0;
	for(int i=1;i<=a;i++)
	{
		long long int c = (a/i);
		s += i*c*(c+1)/2;
	}
	printf("%lld",s);
}
