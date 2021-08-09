#include <stdio.h>
#include <algorithm>
int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			for(int k=j+1;k<=a;k++)
			{
				if(x[i]==x[j]) continue;
				if(x[j]==x[k]) continue;
				if(x[i]+x[j]>x[k]) count++;
			}
		}
	}
	printf("%d",count);
}
