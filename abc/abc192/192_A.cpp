#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	a%=100;
	printf("%d",100-a);
}