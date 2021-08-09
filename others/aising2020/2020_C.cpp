#include <stdio.h>

int count[10010];
int main()
{
	int a;
	scanf("%d",&a);
	
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			for(int k=1;k<=100;k++)
			{
				int C = i*i+j*j+k*k+i*j+j*k+k*i;
				if(C<=a) count[C]++;
			}
		}
	}
	for(int i=1;i<=a;i++) printf("%d\n",count[i]);
}
