#include <stdio.h>
#include <vector>

std::vector< std::vector<long long int> > check[9][70010];

int a,b;
long long int func(int s, int t, int bit, int k)
{
	if(k<0) return 0;
	if(t==b+1) return func(s+1,1,bit,k);
	if(s==a+1)
	{
		if(k==0 && bit==0) return 1;
		else return 0;
	}
	if(check[k][bit][s][t]!=-1) return check[k][bit][s][t];
	
	if((bit&(1<<(t-1)))!=0) return func(s,t+1,bit-(1<<(t-1)),k);
	else
	{
		long long int s1 = 0, s2 = 0, s3 = 0;
		s1 = func(s,t+1,bit+(1<<(t-1)),k-1);
		s2 = func(s,t+1,bit,k);
		if(t<b && (bit&(1<<t))==0) s3 = func(s,t+1,bit+(1<<t),k-1);
		return check[k][bit][s][t] = s1+s2+s3;
	}
}

int main()
{
	int c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	for(int i=0;i<=c;i++) for(int j=0;j<=65535;j++) check[i][j].resize(a+1);
	for(int i=0;i<=c;i++) for(int j=0;j<=65535;j++) for(int k=0;k<=a;k++) for(int l=0;l<=b;l++) check[i][j][k].push_back(-1);
	
	printf("%lld",func(1,1,0,c));
}