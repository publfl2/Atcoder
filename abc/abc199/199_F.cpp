#include <stdio.h>
#include <vector>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k =a;
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

std::vector< std::vector<long long int> > M;
int a;
std::vector< std::vector<long long int> > func(int k)
{
	if(k%2==0)
	{
		std::vector< std::vector<long long int> > M1 = func(k/2);
		std::vector< std::vector<long long int> > M2;
		M2.resize(a+2);
		for(int i=1;i<=a;i++) M2[i].resize(a+2);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				for(int k=1;k<=a;k++)
				{
					M2[i][j] += M1[i][k]*M1[k][j];
					M2[i][j] %= MOD;
				}
			}
		}
		return M2;
	}
	else if(k==1) return M;
	else
	{
		std::vector< std::vector<long long int> > M1 = func((k-1)/2);
		std::vector< std::vector<long long int> > M2;
		M2.resize(a+2);
		for(int i=1;i<=a;i++) M2[i].resize(a+2);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				for(int k=1;k<=a;k++)
				{
					M2[i][j] += M1[i][k]*M1[k][j];
					M2[i][j] %= MOD;
				}
			}
		}
		
		std::vector< std::vector<long long int> > M3;
		M3.resize(a+2);
		for(int i=1;i<=a;i++) M3[i].resize(a+2);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				for(int k=1;k<=a;k++)
				{
					M3[i][j] += M2[i][k]*M[k][j];
					M3[i][j] %= MOD;
				}
			}
		}
		return M3;
	}
}

std::vector< std::vector<long long int> > M2;
int x[110];
int main()
{
	int b,c;
	scanf("%d%d%d",&a,&b,&c);
	M.resize(a+2);
	for(int i=1;i<=a;i++) M[i].resize(a+2);
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		for(int j=1;j<=a;j++)
		{
			if(j==d) continue;
			if(j==e) continue;
			M[j][j] += inv(b), M[j][j] %= MOD;
		}
		M[d][d] += inv(2*b), M[d][d] %= MOD;
		M[d][e] += inv(2*b), M[d][e] %= MOD;
		M[e][d] += inv(2*b), M[e][d] %= MOD;
		M[e][e] += inv(2*b), M[e][e] %= MOD;
	}
	if(c==0)
	{
		for(int i=1;i<=a;i++) printf("%d\n",x[i]);
		return 0;
	}
	
	M2 = func(c);
	for(int i=1;i<=a;i++)
	{
		long long int sum = 0;
		for(int j=1;j<=a;j++)
		{
			sum += M2[i][j]*x[j];
			sum %= MOD;
		}
		printf("%lld\n",sum);
	}
}