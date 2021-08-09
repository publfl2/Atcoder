#include <stdio.h>

int main()
{
	int a,b;
	int sum = 0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		sum += c;
	}
	printf("%d",sum>a?-1:a-sum);
}
