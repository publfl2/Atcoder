#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	long long int d = (b*b+c*c);
	long long int t;
	if(d%(a*a)==0) t = d/(a*a);
	else t = d/(a*a)+1;
	
	long long int s;
	for(long long int i=1;;i++)
	{
		if(i*i>=t)
		{
			s = i;
			break;
		}
	}
	if(s==1)
	{
		if(d==a*a) printf("1");
		else printf("2");
	}
	else printf("%lld",s);
}