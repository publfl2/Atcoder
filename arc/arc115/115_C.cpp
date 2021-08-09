#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int C = 1;
		int b = i;
		for(int j=2;j*j<=i;j++)
		{
			while(b%j==0) b/=j, C++;
		}
		if(b>1) C++;
		printf("%d ",C);
	}
}