#include <stdio.h>
#define MAX (long long int)1e16

int x[1010][1010];
long long int y[1010][1010];
int main()
{
	int a,b;
	long long int c;
	scanf("%d%d%lld",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	
	for(int i=1;i<=a+1;i++) for(int j=1;j<=b+1;j++) y[i][j] = MAX;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = x[i][j] + c*(i+j);
	
	for(int i=a;i>=1;i--)
	{
		for(int j=b;j>=1;j--)
		{
			y[i][j] = y[i][j] < y[i][j+1]?y[i][j]:y[i][j+1];
			y[i][j] = y[i][j] < y[i+1][j]?y[i][j]:y[i+1][j];
		}
	}
	
	long long int ans = MAX;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			long long int t = y[i+1][j]<y[i][j+1]?y[i+1][j]:y[i][j+1];
			long long int s = t - c*(i+j) + x[i][j];
			ans = ans<s?ans:s;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int k = a-i+1;
		if(k<=i) break;
		for(int j=1;j<=b;j++)
		{
			int temp = x[i][j];
			x[i][j] = x[k][j];
			x[k][j] = temp;
		}
	}
	
	for(int i=1;i<=a+1;i++) for(int j=1;j<=b+1;j++) y[i][j] = MAX;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = x[i][j] + c*(i+j);
	
	for(int i=a;i>=1;i--)
	{
		for(int j=b;j>=1;j--)
		{
			y[i][j] = y[i][j] < y[i][j+1]?y[i][j]:y[i][j+1];
			y[i][j] = y[i][j] < y[i+1][j]?y[i][j]:y[i+1][j];
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			long long int t = y[i+1][j]<y[i][j+1]?y[i+1][j]:y[i][j+1];
			long long int s = t - c*(i+j) + x[i][j];
			ans = ans<s?ans:s;
		}
	}
	
	printf("%lld",ans);
}