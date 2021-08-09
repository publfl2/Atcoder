#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	long long int S = 1;
	for(int i=1;i<=100;i++)
	{
		S*=3;
		if(S>a) break;
		long long int T = a-S;
		int count = 0;
		if(T<5) continue;
		
		while(T%5==0)
		{
			count++;
			T/=5;
		}
		if(T==1)
		{
			printf("%d %d",i,count);
			return 0;
		}
	}
	printf("-1");
}
