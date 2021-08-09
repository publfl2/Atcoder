#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int b = i;
		int control = 0;
		while(b)
		{
			if(b%10==7) control = 1;
			b/=10;
		}
		b = i;
		while(b)
		{
			if(b%8==7) control = 1;
			b/=8;
		}
		ans += control;
	}
	printf("%d",a-ans);
}
