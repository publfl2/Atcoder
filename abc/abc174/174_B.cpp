#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		long long int c,d;
		scanf("%lld%lld",&c,&d);
		if(c*c+d*d<=b*b) count++;
	}
	printf("%d",count);
}
