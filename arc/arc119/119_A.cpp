#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	
	long long int s = 1;
	long long int ans = a;
	for(int i=0;;i++)
	{
		if(s>a) break;
		long long int t1 = a/s, t2 = a%s;
		ans = ans<t1+t2+i?ans:t1+t2+i;
		s*=2;
	}
	printf("%lld",ans);
}