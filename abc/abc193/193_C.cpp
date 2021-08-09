#include <stdio.h>
#include <set>

std::set<long long int> S;
int main()
{
	long long int a;
	scanf("%lld",&a);
	for(int i=100000;i>=2;i--)
	{
		long long int s = i;
		while(1)
		{
			s*=i;
			if(s>a) break;
			S.insert(s);
		}
	}
	printf("%lld\n",a-S.size());
}