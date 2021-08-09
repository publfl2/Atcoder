#include <stdio.h>
#include <queue>

std::priority_queue<long long int> Q;

int main()
{
	int a;
	scanf("%d",&a);
	long long int limit = 0;
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		Q.push(2*b+c);
		limit += b;
	}
	int count = 0;
	while(!Q.empty())
	{
		long long int k = Q.top();
		Q.pop();
		limit -= k;
		count++;
		if(limit<0)
		{
			printf("%d",count);
			return 0;
		}
	}
}
