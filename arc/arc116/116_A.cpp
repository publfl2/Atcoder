#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		if(a%2==1) printf("Odd\n");
		else
		{
			long long int b = a/2;
			if(b%2==1) printf("Same\n");
			else printf("Even\n");
		}
	}
}