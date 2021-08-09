#include <stdio.h>
#define MOD 998244353
int a,b;
int x[3010];

long long int check[3010][3010];
long long int func(int s, int t)
{
	if(s>a)
	{
		if(t==b) return 1;
		else return 0;
	}
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s1 = 0, s2 = 0;
	if(t+x[s]<=b) s1 = func(s+1,t+x[s]);
	s2 = func(s+1,t);
	return check[s][t] = (s1+2*s2)%MOD;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) check[i][j] = -1;
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	printf("%lld",func(1,0));
}
