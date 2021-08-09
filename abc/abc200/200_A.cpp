#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	if(a%100==0) printf("%d",a/100);
	else printf("%d",a/100+1);
}