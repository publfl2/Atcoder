#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	int count = 0;
	for(long long int i=1;i*i<=2*a;i++)
	{
		if((2*a)%i==0)
		{
			if((i-1)%2==0) count++;
			if(i*i==2*a) continue;
			if((2*a/i-1)%2==0) count++;
		}
	}
	printf("%d",2*count);
}
