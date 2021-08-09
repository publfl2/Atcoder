#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	if(a%1000==0) printf("0");
	else printf("%d",(1000-a%1000));
}
