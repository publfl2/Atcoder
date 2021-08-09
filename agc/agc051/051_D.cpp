#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if((a+d)%2==1)
	{
		printf("0");
		return 0;
	}
	if((b+c)%2==1)
	{
		printf("0");
		return 0;
	}
	
	for(int A=0;A<=a&&A<=b;A++)
	{
		if((a-A)%2==0&&(b-A)%2==0)
		{
			long long int S = fact[(a+d)/2];
			S *= inv(fact[(a-A)/2]), S %= MOD;
			S *= inv(fact[(b-A)/2]), S %= MOD;
			V1.push_back(S);
		}
		else V1.push_back(0);
	}
	
	for(int B=0;B<=c&&B<=d;B++)
	{
		if((c-B)%2==0&&(d-B)%2==0)
		{
			long long int S = fact[(b+c)/2];
			S *= inv(fact[(c-B)/2]), S %= MOD;
			S *= inv(fact[(d-A)/2]), S %= MOD;
			V2.push_back(S);
		}
		else V2.push_back(0);
	}
	
	FFT(V1,V2);
}
