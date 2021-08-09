#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> prime;
std::vector<long long int> V;
int check[110];

void func(int s, long long int t)
{
	if(s==prime.size()) V.push_back(t);
	else
	{
		func(s+1,t);
		func(s+1,t*prime[s]);
	}
}

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

int x[110];
int main()
{
	for(int i=2;i<=50;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=50;j+=i) check[j] = 1;
		}
	}
	
	func(0,1);
	std::sort(V.begin(),V.end());
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=0;i<V.size();i++)
	{
		for(int j=1;j<=a;j++) if(gcd(x[j],V[i])==1) goto u;
		printf("%lld",V[i]);
		return 0;
		
		u:;
	}
}