#include <stdio.h>
#define MOD 998244353
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int x[10][10],y[10];
int main()
{
	for(int i=0;i<=6;i++) x[1][i] = power(6,i);
	y[1] = 1;
	for(int i=0;i<=6;i++) x[2][i] = power(7,i);
	y[2] = 1;
	for(int i=0;i<=6;i++) x[3][i] = power(8,i);
	y[3] = 3;
	for(int i=0;i<=6;i++) x[4][i] = power(9,i);
	y[4] = 5;
	for(int i=0;i<=6;i++) x[5][i] = power(50,i);
	y[5] = 80132;
	for(int i=0;i<=6;i++) x[6][i] = power(10000000000,i);
	y[6] = 2239716;
	for(int i=0;i<=6;i++) x[7][i] = power(10,i);
	y[7] = 10;
	
	for(int i=1;i<=7;i++)
	{
		long long int t = inv(x[i][7-i]);
		for(int j=0;j<=6;j++) x[i][j] *= t, x[i][j] %= MOD;
		y[i] *=t, y[i] %= MOD;
		
		for(int k=1;k<=7;k++)
		{
			if(i==k) continue;
			t = x[k][7-i];
			for(int j=0;j<=6;j++) x[k][j] += t*(MOD-x[i][j]), x[k][j]%=MOD;
			y[k] += t*(MOD-y[i]), y[k] %= MOD;
		}
	}
	
	
	long long int a;
	scanf("%lld",&a);
	
	long long int ans = 0;
	for(int i=1;i<=7;i++)
	{
		ans += power(a,7-i)*y[i];
		ans %= MOD;
	}
	printf("%lld",ans);
}