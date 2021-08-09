#include <stdio.h>

int check[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	int d = 7%a;
	
	for(int i=1;;i++)
	{
		if(d==0)
		{
			printf("%d",i);
			return 0;
		}
		check[d] = 1;
		d*=10;
		d+=7;
		d%=a;
		if(check[d]==1)
		{
			printf("-1");
			return 0;
		}
	}
}
