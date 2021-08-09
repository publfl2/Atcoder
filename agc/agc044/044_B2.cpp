#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("%d\n",500);
	for(int i=1;i<=500*500;i++) printf("%d ",i);
	
}
