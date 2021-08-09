#include <stdio.h>
#define MAX (long long int)1e18
#define MIN -(long long int)1e18

int a;
long long int check[101][101][101][101];
int x[101];
long long int func(int limit, int s, int t, int k)
{
	if(t>limit) return MIN;
	if(s>a)
	{
		if(t<limit) return MIN;
		if(k!=0) return MIN;
		return 0;
	}
	if(check[limit][s][t][k]!=-2) return check[limit][s][t][k];
	
	long long int s1 = func(limit,s+1,t,k);
	long long int s2 = func(limit,s+1,t+1,(k-x[s]%limit+limit)%limit) + x[s];
	return check[limit][s][t][k] = s1>s2?s1:s2;
}

int main()
{
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) for(int k=0;k<=a;k++) for(int l=0;l<=a;l++) check[i][j][k][l] = -2;
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int ans = MAX;
	for(int i=1;i<=a;i++)
	{
		long long int t = func(i,1,0,b%i);
		if(t>=0) ans = ans<(b-t)/i?ans:(b-t)/i;
	}
	printf("%lld",ans);
}