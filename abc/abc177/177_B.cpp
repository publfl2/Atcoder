#include <stdio.h>
#include <string.h>

char x[1010],y[1010];
int main()
{
	scanf("%s%s",x+1,y+1);
	int a = strlen(x+1);
	int b = strlen(y+1);
	
	int ans = 12345;
	for(int i=1;i<=a-b+1;i++)
	{
		int count = 0;
		for(int j=i;j<=i+b-1;j++)
		{
			if(x[j]!=y[j-i+1]) count++;
		}
		ans = ans<count?ans:count;
	}
	printf("%d",ans);
}
