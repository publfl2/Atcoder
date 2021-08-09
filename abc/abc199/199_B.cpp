#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	int max = 1000, min = 1;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		min = min>b?min:b;
	}
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		max = max<b?max:b;
	}
	if(min>max) printf("0");
	else printf("%d",max-min+1);
}