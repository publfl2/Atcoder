#include <stdio.h>

int power(int a, int b, int MOD)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(b==1) printf("%d",a%10);
	else
	{
		int d = power(b,c,4);
		d+=4;
		printf("%d",power(a,d,10));
	}
}