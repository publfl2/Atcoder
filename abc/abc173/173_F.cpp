#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) ans += (long long int)i*(a-i+1);
	
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		if(b>c)
		{
			int k = b;
			b = c;
			c = k;
		}
		ans -= (long long int)(b-1+1)*(a-c+1);
	}
	printf("%lld",ans);
}
