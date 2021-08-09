#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(2*a>b) printf("0\n");
		else
		{
			int c = (b-2*a+1);
			printf("%lld\n",(long long int)c*(c+1)/2);
		}
	}
}