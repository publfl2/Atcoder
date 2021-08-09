#include <stdio.h>
#include <string.h>

char x[10];
int main()
{
	long long int a;
	scanf("%lld",&a);
	scanf("%s",x+1);
	int b = strlen(x+1);
	
	long long int c = a*(x[1]-'0');
	long long int d = a*(10*(x[3]-'0')+(x[4]-'0'));
	
	printf("%lld",c+(d/100));
}
