#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",(a/500)*1000 + ((a%500)/5)*5);
}
