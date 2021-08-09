#include <stdio.h>
#include <map>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int a;
std::map< std::pair<int,int> , long long int > check[110];
std::pair<int,int> P[110];
long long int func(int k, int t1, int t2)
{
	if(k>a) return (long long int)t1*t2;
	
	if(check[k].find(std::make_pair(t1,t2))!=check[k].end()) return check[k][std::make_pair(t1,t2)];
	long long int s1 = func(k+1,gcd(t1,P[k].first),gcd(t2,P[k].second));
	long long int s2 = func(k+1,gcd(t1,P[k].second),gcd(t2,P[k].first));
	
	return check[k][std::make_pair(t1,t2)] = s1>s2?s1:s2;
}

int main()
{
	scanf("%d",&a);
	int g = 0;
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		g = gcd(g,b);
		g = gcd(g,c);
		P[i] = std::make_pair(b,c);
	}
	long long int t = func(2,P[1].first,P[1].second);
	printf("%lld",t/g);
}