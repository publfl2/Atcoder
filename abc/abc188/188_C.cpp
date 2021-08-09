#include <stdio.h>

int x[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=(1<<a);i++) scanf("%d",&x[i]);
	int max1 = 0, max2 = 0;
	for(int j=1;j<=(1<<a);j++) max1 = max1>x[j]?max1:x[j];
	int p;
	for(int j=1;j<=(1<<a);j++) if(x[j]==max1) p = j;
	if(p<=(1<<(a-1)))
	{
		int max2 = 0;
		for(int j=(1<<(a-1))+1;j<=(1<<a);j++) max2 = max2>x[j]?max2:x[j];
		for(int j=(1<<(a-1))+1;j<=(1<<a);j++)
		{
			if(max2==x[j])
			{
				printf("%d",j);
				return 0;
			}
		}
	}
	else
	{
		int max2 = 0;
		for(int j=1;j<=(1<<(a-1));j++) max2 = max2>x[j]?max2:x[j];
		for(int j=1;j<=(1<<(a-1));j++)
		{
			if(max2==x[j])
			{
				printf("%d",j);
				return 0;
			}
		}
	}
}
