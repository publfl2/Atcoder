#include <stdio.h>
#define MOD 998244353

int check[1010];
int sum[1010];
char x[10];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%s",x+1);
		int c;
		scanf("%d",&c);
		if(x[1]=='L')
		{
			check[c] = 1;
			sum[c]++, sum[a+1]--;
		}
		else
		{
			check[c] = 1;
			sum[1]++, sum[c+1]--;
		}
	}
	
	int S = 0;
	long long int ans = 1;
	for(int i=1;i<=a;i++)
	{
		S += sum[i];
		if(check[i]==1) continue;
		ans *= S, ans %= MOD;
	}
	printf("%lld",ans);
}