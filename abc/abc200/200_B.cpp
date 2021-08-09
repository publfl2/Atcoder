#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	for(int i=1;i<=b;i++)
	{
		if(a%200==0) a/=200;
		else a = 1000*a+200;
	}
	printf("%lld",a);
}