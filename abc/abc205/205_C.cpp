#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c%2==1)
	{
		if(a>=0&&b>=0)
		{
			if(a>b) printf(">");
			else if(a<b) printf("<");
			else printf("=");
		}
		else if(a<0&&b>=0) printf("<");
		else if(a>=0&&b<0) printf(">");
		else
		{
			if(a>b) printf(">");
			else if(a<b) printf("<");
			else printf("=");
		}
	}
	else
	{
		a = abs(a);
		b = abs(b);
		if(a>b) printf(">");
		else if(a<b) printf("<");
		else printf("=");
	}
}