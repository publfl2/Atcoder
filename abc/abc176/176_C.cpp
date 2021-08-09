#include <stdio.h>

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int s = 0;
	for(int i=2;i<=a;i++)
	{
		if(x[i]<x[i-1])
		{
			s += (x[i-1]-x[i]);
			x[i] = x[i-1];
		}
	}
	printf("%lld",s);
}
