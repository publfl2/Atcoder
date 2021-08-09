#include <stdio.h>
#include <algorithm>

long long int x[200010];
std::pair<long long int,int> y[200010];
long long int count[200010];

int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i],i);
	std::sort(y+1,y+a+1);
	long long int s = (b/a);
	long long int t = (b%a);
	for(int i=1;i<=t;i++) count[y[i].second]++;
	for(int i=1;i<=a;i++) printf("%lld\n",s+count[i]);
	
}