#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	for(long long int i=1;;i*=10)
	{
		if((i*i)>=a)
		{
			if(a>=(i*i/10))
			{
				long long int s = (a/i);
				long long int t = (a%i);
				if(s<=t) printf("%lld",s);
				else printf("%lld",s-1);
				break;
			}
			else
			{
				printf("%lld",i/10-1);
				break;
			}
		}
	}
}