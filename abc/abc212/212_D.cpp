#include <stdio.h>
#include <vector>
#include <queue>

std::priority_queue< long long int, std::vector<long long int> , std::greater<long long int> > Q;
int main()
{
	int a;
	scanf("%d",&a);
	
	long long int sum = 0;
	while(a--)
	{
		int b;
		long long int c;
		scanf("%d",&b);
		if(b==1)
		{
			scanf("%lld",&c);
			Q.push(c-sum);
		}
		if(b==2)
		{
			scanf("%lld",&c);
			sum += c;
		}
		if(b==3)
		{
			long long int t = Q.top();
			Q.pop();
			printf("%lld\n",t+sum);
		}
	}
}