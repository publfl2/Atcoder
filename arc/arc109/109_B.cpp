#include <stdio.h>
#include <math.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	long long int b = (long long int)sqrt(2*a);
	while(b*(b+1)<=2*(a+1)) b++;
	b--;
	
	printf("%lld",a-b+1);
}
