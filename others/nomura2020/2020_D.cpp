#include <stdio.h>
#include <deque>
#include <string.h>

char x[200010];
int sum[200010];
int  y[200010];
int func(int s, int t)
{
	if((t-s)%2==0) return sum[t] - sum[s-2];
	else return sum[t-1] - sum[s-2];
}

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=2;i<=a+1;i++) y[i] = x[i-1] - '0';
	y[0] = y[1] = 0;
	for(int i=2;i<=a+1;i++) sum[i] = sum[i-2] + y[i];
	
	long long int ans = 0;
	for(int i=2;i<=a+2;i++)
	{
		long long int S = 0;
		for(int j=i;j<=a+1;j++) S += func(i,j);
		for(int j=i-1;j>=2;j--) S += func(j,a+1);
		ans = ans>S?ans:S;
	}
	printf("%lld",ans);
}
