#include <stdio.h>

int main()
{
	int a;
	freopen("input.txt","w",stdout);
	scanf("%d",&a);
	printf("%d\n",a);
	for(int i=1;i<=a;i++) printf("1 ");
}
