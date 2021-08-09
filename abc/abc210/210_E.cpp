#include <stdio.h>
#include <algorithm>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

std::pair<int,int> P[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i] = std::make_pair(d,c);
	}
	std::sort(P+1,P+b+1);
	
	long long int N = a;
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		long long int g = gcd(N,P[i].second);
		ans += g*(N/g-1)*P[i].first;
		N = g;
	}
	if(N==1) printf("%lld",ans);
	else printf("-1");
}