#include <stdio.h>

char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i+=2)
	{
		if(x[i]=='1')
		{
			printf("Takahashi");
			return 0;
		}
		if(x[i+1]=='1')
		{
			printf("Aoki");
			return 0;
		}
	}
}