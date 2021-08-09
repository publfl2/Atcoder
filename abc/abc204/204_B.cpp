#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b>=10) ans +=(b-10); 
	}
	printf("%d",ans);
}