#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(i%2==1&&b%2==1) count++;
	}
	printf("%d",count);
}
