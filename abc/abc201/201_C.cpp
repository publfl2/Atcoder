#include <stdio.h>
#include <string.h>

int count[110];
char x[110];
int main()
{
	scanf("%s",x);
	int a = strlen(x);
	
	int ans = 0;
	for(int i=0;i<=9999;i++)
	{
		int s1 = i/1000;
		int s2 = (i/100)%10;
		int s3 = (i/10)%10;
		int s4 = i%10;
		for(int j=0;j<=9;j++) count[j] = 0;
		count[s1]++, count[s2]++, count[s3]++, count[s4]++;
		for(int j=0;j<=9;j++)
		{
			if(x[j]=='x'&&count[j]>=1) goto u;
			if(x[j]=='o'&&count[j]==0) goto u;
		}
		ans++;
		u:;
	}
	printf("%d",ans);
}