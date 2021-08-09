#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	if(a==2)
	{
		printf("1");
		return 0;
	}
	
	int count = 2;
	for(long long int i=2;i*i<=a-1;i++)
	{
		if((a-1)%i==0)
		{
			if(i*i==a-1) count++;
			else count +=2;
		}
	}
	
	for(long long int i=2;i*i<=a;i++)
	{
		if(a%i==0)
		{
			long long int b = a;
			while(b%i==0) b/=i;
			if(b%i==1) count++;
			
			if(i*i==a) continue;
			b = a;
			while(b%(a/i)==0) b/=(a/i);
			if(b%(a/i)==1) count++;
		}
	}
	printf("%d",count);
}
