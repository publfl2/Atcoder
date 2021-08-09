#include <stdio.h>
#include <vector>

std::pair<long long int, long long int> ans,p;
long long int b;
std::pair<long long int,long long int> mul(std::pair<long long int, long long int> A, std::pair<long long int, long long int> B)
{
	long long int s = (A.first*B.second+A.second*B.first+(A.second*B.second)/b)%b;
	long long int t = (A.second*B.second)%b;
	return std::make_pair(s,t);
}

int main()
{
	long long int a;
	scanf("%lld%lld",&a,&b);
	ans = std::make_pair(0,1);
	p = std::make_pair(10/b,10%b);
	
	while(a)
	{
		if(a%2==1) ans = mul(ans,p);
		a/=2;
		p = mul(p,p);
	}
	printf("%lld",ans.first);
}
