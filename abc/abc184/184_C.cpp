#include <stdio.h>

long long int abs(long long int k)
{
	return k>0?k:-k;
}
int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if(a==c&&b==d) printf("0");
	else
	{
		if(a+b==c+d) printf("1");
		else if(a-b==c-d) printf("1");
		else if(abs(a-c)+abs(b-d)<=3) printf("1");
		else
		{
			if((a+b)%2==(c+d)%2) printf("2");
			else if(abs(a-c)+abs(b-c)<=6) printf("2");
			else if(abs(d-(a+b-c))<=3) printf("2");
			else if(abs(d-(b+c-a))<=3) printf("2");
			else printf("3");
		}
	}
}
