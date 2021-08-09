#include <stdio.h>
#include <algorithm>
#include <atcoder/convolution>
#include <atcoder/modint>

using mint = atcoder::modint998244353;

int a,b;
long long int x[200010];
std::pair< std::vector<mint>, std::vector<mint> > func(int L, int R)
{
	if(L==R)
	{
		std::vector<mint> V1,V2;
		V1.push_back((mint)1 / x[L]), V1.push_back(1);
		V2.push_back((mint)(L-1)/x[L]), V2.push_back(1);
		return {V1,V2};
	}
	
	int h = (L+R)/2;
	auto P1 = func(L,h);
	auto P2 = func(h+1,R);
	std::vector<mint> V1 = atcoder::convolution(P1.first,P2.first);
	std::vector<mint> V2 = atcoder::convolution(P1.second,P2.first);
	for(int i=0;i<P2.second.size();i++) V2[h-L+1+i] += P2.second[i];
	
	//while(V1.size()>=b) V1.pop_back();
	//while(V2.size()>=b) V2.pop_back();
	return {V1,V2};
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	if(b==1)
	{
		printf("1");
		return 0;
	}
	std::sort(x+1,x+a+1);
	
	mint t = func(1,a).second[a-b+1];
	for(int i=1;i<=a;i++) t/=i;
	for(int i=1;i<=b;i++) t*=i;
	for(int i=1;i<=a-b;i++) t*=i;
	printf("%lld",t/2);
}