#include <stdio.h>

int check[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(check[b]==1)
		{
			printf("No");
			return 0;
		}
		check[b] = 1;
	}
	printf("Yes");
}