#include <stdio.h>
#include <string.h>

char x[3][110];
int main()
{
	for(int i=1;i<=4;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=4;i++)
	{
		for(int j=i+1;j<=4;j++)
		{
			int s = strlen(x[i]+1);
			int t = strlen(x[j]+1);
			if(s!=t) goto u;
			for(int k=1;k<=s;k++)
			{
				if(x[i][k]!=x[j][k])
				{
					goto u;
				}
			}
			printf("No");
			return 0;
			u:;
		}
	}
	printf("Yes");
}