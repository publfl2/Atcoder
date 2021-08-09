#include <stdio.h>

char x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	
	int C = b;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='o') C++;
		else
		{
			C--;
			if(C<0) C = 0;
		}
	}
	printf("%d",C);
}
