#include <stdio.h>

int main()
{
	long long int a;
	scanf("%lld",&a);
	long long int b = a;
	int ans = 0;
	
	for(int i=2;(long long int)i*i<=a;i++)
	{
		if(b%i==0)
		{
			int count = 0;
			while(b%i==0) count++,b/=i;
			
			int C = 0;
			for(int j=1;;j++)
			{
				if(C+j<=count) ans++,C+=j;
				else break;
			}
		}
	}
	if(b>1) ans++;
	printf("%d",ans);
}
