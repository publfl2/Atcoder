#include <stdio.h>
#define MOD 998244353

int x[5010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int ans = 1;
	for(int i=1;i<=a;i++)
	{
		int count = 0;
		for(int j=1;j<i;j++) if(x[j]>x[i]) count++;
		if(count==b)
		{
			int count2 = 1;
			for(int j=i+1;j<=a;j++)
			{
				if(x[j]>x[i]) count2++;
				else break;
			}
			ans *= count2, ans %= MOD;
		}
	}
	printf("%lld",ans);
}