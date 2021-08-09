#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a<0) a*=-1;
	
	long long int d = a/c;
	if(b<=d) printf("%lld",a-b*c);
	else
	{
		long long int s1 = a%c;
		long long int s2 = c-s1;
		if((b-d)%2==0) printf("%lld",s1);
		else printf("%lld",s2);
	}
}
