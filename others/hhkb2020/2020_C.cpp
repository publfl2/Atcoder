#include <stdio.h>

int x[200010],check[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		check[x[i]] = 1;
		while(check[p]==1) p++;
		printf("%d\n",p);
	}
}
