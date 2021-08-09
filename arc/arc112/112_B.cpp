#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	//1
	long long int L1 = a-(b/2);
	long long int R1 = a;
	if(b==0)
	{
		printf("%lld",R1-L1+1);
		return 0;
	}
	//2
	long long int L2 = -a-(b-1)/2;
	long long int R2 = -(a-(b-1)/2);
	if(b>=2) R1 = -(-a-(b-2)/2);
	if(L1<L2)
	{
		long long int ans = (R1-L1+1);
		long long int p = R1+1>L2?R1+1:L2;
		if(p<=R2) ans += (R2-p+1);
		printf("%lld",ans);
	}
	else
	{
		long long int ans = (R2-L2+1);
		long long int p = R2+1>L1?R2+1:L1;
		if(p<=R1) ans += (R1-p+1);
		printf("%lld",ans);
	}
}