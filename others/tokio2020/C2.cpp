#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("%d\n",252143);
	for(int i=1;i<=252143;i++) printf("%d 100000\n",i);
	printf("%d\n",100000);
	for(int i=1;i<=100000;i++)
	{
		printf("%d %d\n",i,100000);
	}
}
