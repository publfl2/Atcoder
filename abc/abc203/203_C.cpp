#include <stdio.h>
#include <algorithm>
#define MAX (long long int)1e16

std::pair<long long int,long long int> x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		long long int c,d;
		scanf("%lld%lld",&c,&d);
		x[i]={c,d};
	}
	std::sort(x+1,x+a+1);
	x[a+1] = {MAX,0};
	
	long long int s = b;
	for(int i=1;i<=a+1;i++)
	{
		if(s<x[i].first)
		{
			printf("%lld",s);
			return 0;
		}
		else s += x[i].second;
	}
}