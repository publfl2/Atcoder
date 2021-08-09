#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	long long int sum = 3;
	for(long long int i=3;i<=3*a;i++)
	{
		long long int s = (i-2)*(i-1)/2;
		if(i>=a+3) s -= 3*(i-a-1)*(i-a-2)/2;
		if(i>=2*a+3) s+= 3*(i-2*a-1)*(i-2*a-2)/2;
		
		if(s>=b)
		{
			sum = i;
			break;
		}
		else b -= s;
	}
	
	long long int ans1 = -1;
	for(long long int i=1;i<=sum-2;i++)
	{
		long long int s = sum-i-1;
		if(sum-i>=a+2) s -= 2*(sum-i-a-1);
		if(sum-i>=2*a+2) s += (sum-i-2*a-1);
		
		if(s>=b)
		{
			ans1 = i;
			break;
		}
		else b -= s;
	}
	
	long long int start = 1>sum-ans1-a?1:sum-ans1-a;
	printf("%lld %lld %lld",ans1,start+b-1,sum-ans1-start-b+1);
}