#include <stdio.h>

int count[10];
int main()
{
	long long int a;
	scanf("%lld",&a);
	int sum = 0,digit = 0;
	while(a)
	{
		sum += (a%10);
		digit++;
		count[(a%10)%3]++;
		a/=10;
	}
	if(sum%3==0) printf("0");
	else if(sum%3==1)
	{
		if(digit>=2&&count[1]>=1) printf("1");
		else if(digit>=3&&count[2]>=2) printf("2");
		else printf("-1");
	}
	else
	{
		if(digit>=2&&count[2]>=1) printf("1");
		else if(digit>=3&&count[1]>=2) printf("2");
		else printf("-1");
	}
}
