#include <stdio.h>
#include <string.h>
#define MOD 1000000007

char type[10] = {0,'c','h','o','k','u','d','a','i'};
long long int sum[10][100010];
char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	for(int i=0;i<=a;i++) sum[0][i] = 1;
	for(int j=1;j<=8;j++)
	{
		for(int i=1;i<=a;i++)
		{
			if(x[i]==type[j]) sum[j][i] = sum[j-1][i-1];
			else sum[j][i] = 0;
		}
		for(int i=1;i<=a;i++) sum[j][i] += sum[j][i-1], sum[j][i] %= MOD;
	}
	
	printf("%lld",sum[8][a]);
}