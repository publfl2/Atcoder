#include <stdio.h>
#define MOD 200003

long long int number[200010],sum[200010];
int x[200010];
long long int check[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		number[b]++;
		x[i] = b;
	}
	for(int i=1;i<MOD;i++)
	{
		sum[i] = sum[i-1] + (long long int)number[i]*i;
		number[i] += number[i-1];
	}
	
	for(int k=1;k*k<MOD;k++)
	{
		long long int C = 0;
		for(int n=0;n<k;n++)
		{
			int L,R;
			L = ((long long int)n*MOD)/k + 1;
			R = ((long long int)(n+1)*MOD)/k;
			long long int s = sum[R] - sum[L-1];
			long long int t = number[R] - number[L-1];
			C += (s-t*n*MOD);
		}
		check[k] = C;
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==0) continue;
		else ans += check[i];
	}
	printf("%lld",ans);
}
