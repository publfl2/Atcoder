#include <stdio.h>
#define MOD 998244353

int a;
int check[102][10001][101];
int x[110];

/*
void func(int k, int S)
{
	if(S<0) return;
	if(check2[k][S]) return;
	check2[k][S] = 1;
	
	if(k>a)
	{
		if(S==0) check[k][S][0] = 1;
		return;
	}
	
	func(k+1,S);
	for(int i=1;i<=a;i++) check[k][S][i] += check[k+1][S][i], check[k][S][i] %= MOD;
	
	if(S-x[k]>=0)
	{
		func(k+1,S-x[k]);
		for(int i=1;i<=a;i++) check[k][S][i] += check[k+1][S-x[k]][i-1], check[k][S][i] %= MOD;
	}

}*/

long long int fact[110];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=100;i++) fact[i] = (i*fact[i-1])%MOD;
	
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int S = 0;
	for(int i=1;i<=a;i++) S += x[i];
	if(S%2==1)
	{
		printf("0");
		return 0;
	}
	S/=2;
	check[a+1][0][0] = 1;
	for(int i=a;i>=1;i--)
	{
		for(int j=0;j<=S;j++)
		{
			for(int k=1;k<=a;k++)
			{
				check[i][j][k] += check[i+1][j][k], check[i][j][k] %= MOD;
				if(j-x[i]>=0) check[i][j][k] += check[i+1][j-x[i]][k-1], check[i][j][k] %= MOD;
			}
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int k = check[1][S][i];
		//printf("%d : %d!!\n",i,k);
		
		long long int val = fact[i] * fact[a-i];
		val %= MOD;
		val *= k, val %= MOD;
		ans += val, ans %= MOD;
	}
	printf("%lld",(ans*2)%MOD);
}