#include <stdio.h>

int a;
long long int func(int s, int t)
{
	if(t<0) return 0;
	if(s*(s+1)>t || s>=a)
	{
		if(t==0) return 1;
		else return 0;
	}
	
	long long int s1 = func(s+1,t);
	long long int s2 = func(s,t-s*(s+1));
	return s1+s2;
}
int main()
{
	int b;
	scanf("%d%d",&a,&b);
	printf("%lld",func(1,2*b));
}
