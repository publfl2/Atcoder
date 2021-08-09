#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c==0)
	{
		if(a>b) printf("Takahashi");
		else printf("Aoki");
	}
	else
	{
		if(b>a) printf("Aoki");
		else printf("Takahashi");
	}
}
