#include <stdio.h>

char x[100010][30];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	int count1 = 1, count2 = 0;
	for(int i=2;i<=a;i++)
	{
		int C = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]!=x[1][j]) C++;
		}
		if(C%2==1) count2++;
		else count1++;
	}
	printf("%lld",(long long int)count1*count2);
}