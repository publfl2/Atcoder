#include <stdio.h>
#define MOD 998244353
int a,b;
int x[3010];
long long int check[3010][3010];
long long int func(int s, int t)
{
	if(t>b) return 0;
	if(t==b) return (a-s+2);
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s1 = func(s+1,t+x[s]);
	long long int s2 = func(s+1,t);
	return check[s][t] = (s1+s2)%MOD;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int s = func(i+1,x[i]);
		ans += (s*i)%MOD;
		ans %= MOD;
	}
	printf("%lld",ans);
}
