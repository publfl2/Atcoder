#include <stdio.h>
#define MOD 1000000007

int a,b;
char x[2020][2020];
long long int check[2020][2020][4];
long long int func(int s, int t, int type)
{
	if(s>a) return 0;
	if(t>b) return 0;
	if(x[s][t]=='#') return 0;
	if(s==a&&t==b) return 1;
	if(check[s][t][type]!=-1) return check[s][t][type];
	
	if(type==0) return check[s][t][type] = (func(s+1,t,1)+func(s,t+1,2)+func(s+1,t+1,3))%MOD;
	if(type==1) return check[s][t][type] = (func(s+1,t,1)+func(s,t,0))%MOD;
	if(type==2) return check[s][t][type] = (func(s,t+1,2)+func(s,t,0))%MOD;
	if(type==3) return check[s][t][type] = (func(s+1,t+1,3)+func(s,t,0))%MOD;
	
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=0;k<=3;k++) check[i][j][k] = -1;
		}
	}
	
	printf("%lld",func(1,1,0));
}
