#include <stdio.h>
#define MOD 1000000007
long long int check[5010][5010];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(t==s) return 1;
	if(check[s][t]) return check[s][t];
	return check[s][t] = (comb(s-1,t)+comb(s-1,t-1))%MOD;
}

int main()
{
	int a;
	scanf("%d",&a);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(i*3<=a)
		{
			//(a-3i)Hi
			ans += comb(i+a-3*i-1,a-3*i);
			ans %= MOD;
		}
	}
	printf("%lld",ans);
}
