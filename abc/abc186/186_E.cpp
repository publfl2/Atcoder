#include <stdio.h>
#include <vector>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
int control = 0;
std::pair<long long int, long long int> func(int N, int S, int K)
{
	if(N==0)
	{
		if(S%K==0) return std::make_pair(S/K,0);
		else
		{
			control = 1;
			return std::make_pair(0,0);
		}
	}
	if(K==0)
	{
		long long int g = gcd(N,K);
		if(S%N==0) return std::make_pair((long long int)S*(N/g),(long long int)S*(K/g)-(S/N));
		else
		{
			control = 1;
			return std::make_pair(0,0);
		}
	}
	
	if(K>N)
	{
		int c = K/N;
		int d = K%N;
		std::pair<long long int,long long int> P = func(N,S,d);
		long long int g = gcd(N,K);
		
		long long int e = P.first/(N/g);
		long long int f = (P.second+P.first*c)/(K/g);
		long long int k = e<f?e:f;
		return std::make_pair(P.first-k*(N/g),(P.second+P.first*c)-k*(K/g));
	}
	else
	{
		int c = N/K;
		int d = N%K;
		std::pair<long long int, long long int> P = func(d,S,K);
		long long int g = gcd(N,K);
		
		long long int e = P.second/(K/g);
		long long int f = (P.first+P.second*c)/(N/g);
		long long int k = e<f?e:f;
		return std::make_pair((P.first+P.second*c)-k*(N/g),P.second-k*(K/g));
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		control = 0;
		int N,S,K;
		scanf("%d%d%d",&N,&S,&K);
		std::pair<long long int, long long int> P = func(N,S,K);
		if(control) printf("-1\n");
		else
		{
			long long int g = gcd(N,K);
		
			long long int e = P.second/(K/g);
			long long int f = P.second/(N/g);
			long long int k = e<f?e:f;
			printf("%lld\n",P.second-f*(N/g));
		}
	}
}
