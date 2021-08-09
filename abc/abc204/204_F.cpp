#include <stdio.h>
#include <vector>
#define MOD 998244353

int a;
std::vector< std::vector<long long int> > M,M2;
int DP[10] = {1,1,2,3,5,8,13};
void init(int s, int t, int k)
{
	if(k<0)
	{
		int val = 1;
		int count = 0;
		for(int i=0;i<a;i++)
		{
			if((s>>i)%2==0 && (t>>i)%2==0) count++;
			else
			{
				val *= DP[count];
				count = 0;
			}
		}
		val *= DP[count];
		
		M[s][t] = val;
		return;
	}
	
	if((t>>k)%2==0) init(s,t,k-1);
	else
	{
		init(s,t,k-1);
		init(s,t-(1<<k),k-1);
	}
}

std::vector< std::vector<long long int> > func(long long int k)
{
	if(k==1) return M;
	else
	{
		if(k%2==0)
		{
			std::vector< std::vector<long long int> > M2 = func(k/2);
			std::vector< std::vector<long long int> > M3;
			M3.resize((1<<a));
			for(int i=0;i<(1<<a);i++) M3[i].resize((1<<a));
			for(int i=0;i<(1<<a);i++)
			{
				for(int j=0;j<(1<<a);j++)
				{
					for(int k=0;k<(1<<a);k++)
					{
						M3[i][j] += M2[i][k]*M2[k][j];
						M3[i][j] %= MOD;
					}
				}
			}
			return M3;
		}
		else
		{
			std::vector< std::vector<long long int> > M2 = func(k-1);
			std::vector< std::vector<long long int> > M3;
			M3.resize((1<<a));
			for(int i=0;i<(1<<a);i++) M3[i].resize((1<<a));
			for(int i=0;i<(1<<a);i++)
			{
				for(int j=0;j<(1<<a);j++)
				{
					for(int k=0;k<(1<<a);k++)
					{
						M3[i][j] += M2[i][k]*M[k][j];
						M3[i][j] %= MOD;
					}
				}
			}
			return M3;
		}
	}
}

int main()
{
	long long int b;
	scanf("%d%lld",&a,&b);
	M.resize((1<<a));
	for(int i=0;i<(1<<a);i++) M[i].resize((1<<a));
	
	for(int i=0;i<(1<<a);i++) init(i,(1<<a)-1-i,a-1);
	
	M2 = func(b);
	printf("%lld",M2[0][0]);
}