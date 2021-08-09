#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%1d%1d%1d%1d",&a,&b,&c,&d);
	if(a==b&&b==c&&c==d) printf("Weak");
	else if(b==(a+1)%10 && c==(b+1)%10 && d==(c+1)%10) printf("Weak");
	else printf("Strong");
}