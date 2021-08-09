#include <stdio.h>
#include <vector>
#include <map>

int check[1000010];
std::vector<int> prime;

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

std::map<int,int> count[110];
long long int x[110],y[110];
std::vector<long long int> V;
std::map<int,int> M;
int isUsed[110];
std::vector<int> ans;

int main()
{
	for(int i=2;i<=1000000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=1000000;j+=i) check[j] = 1;
		}
	}
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++)
	{
		long long int t = x[i];
		for(int j=0;j<prime.size();j++)
		{
			while(t%prime[j]==0)
			{
				count[i][j]++;
				t/=prime[j];
			}
		}
		y[i] = t;
	}
	
	
	for(int _=a;_>=1;_--)
	{
		for(int i=1;i<=a;i++)
		{
			if(isUsed[i]==1) continue;
			M.clear();
			V.clear();
			for(int j=1;j<=a;j++)
			{
				if(j==i) continue;
				if(isUsed[j]==1) continue;
				for(std::map<int,int> ::iterator it = count[j].begin();it != count[j].end(); it++)
				{
					int s = (it->second);
					int t = M[it->first];
					M[it->first] = (s>t?s:t);
				}
				V.push_back(y[j]);
			}
			
			for(std::map<int,int> ::iterator it = count[i].begin();it != count[i].end(); it++)
			{
				if(M[it->first] < (it->second))
				{
					ans.push_back(i);
					isUsed[i] = 1;
					goto u1;
				}
			}
			
			long long int p = 0;
			for(int j=0;j<V.size();j++)
			{
				long long int g = gcd(V[j],y[i]);
				if(g==y[i]) goto u2;
				if(g>1)
				{
					if(p==0) p = g;
					else if(p==g);
					else goto u2;
				}
			}
			ans.push_back(i);
			isUsed[i] = 1;
			goto u1;
			
			u2:;
		}
		
		printf("No");
		return 0;
		u1:;
	}
	
	printf("Yes\n");
	for(int i=ans.size()-1;i>=0;i--) printf("%lld ",x[ans[i]]);
}