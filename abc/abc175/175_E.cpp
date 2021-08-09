#include <stdio.h>

int a,b;
long long int MIN = -1;

int x[3010][3010];
long long int check[3010][3010][6];
long long int func(int s, int t, int k)
{
	if(s>a) return MIN;
	if(t>b) return MIN;
	if(k>4) return MIN;
	if(s==a&&t==b) return 0;
	if(check[s][t][k]!=-1) return check[s][t][k];
	
	long long int s1 = func(s+1,t,1);
	long long int s2 = func(s,t+1,k);
	long long int s3 = 0;
	if(x[s][t+1]>0) s3 = func(s,t+1,k+1)+x[s][t+1];
	long long int s4 = 0;
	if(x[s+1][t]>0) s4 = func(s+1,t,2) + x[s+1][t];
	
	long long int M = s1;
	M = M>s2?M:s2;
	M = M>s3?M:s3;
	M = M>s4?M:s4;
	return check[s][t][k] = M;
}
int main()
{
	for(int i=1;i<=17;i++) MIN*=10;
	
	int c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=5;k++) check[i][j][k] = -1;
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		x[d][e] = f;
	}
	long long int s1 = func(1,1,1);
	long long int s2 = 0;
	if(x[1][1]>0) s2 = func(1,1,2) + x[1][1];
	printf("%lld",s1>s2?s1:s2);
}
