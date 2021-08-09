#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(a%2==0)
		{
			std::sort(x+1,x+a+1);
			for(int i=1;i<=a;i+=2)
			{
				if(x[i]!=x[i+1])
				{
					printf("First\n");
					goto u;
				}
			}
			printf("Second\n");
			u:;
		}
		else printf("Second\n");
	}
}
