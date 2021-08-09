#include <stdio.h>


int main()
{
	long long int a;
	scanf("%lld",&a);
	long long int b = 100;
	for(int i=1;;i++)
	{
		b += (b/100);
		if(b>=a)
		{
			printf("%d",i);
			return 0;
		}
	}
}
