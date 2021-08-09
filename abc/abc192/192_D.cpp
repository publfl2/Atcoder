#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

char x[110];
std::vector<int> V;

int main()
{
	long long int b;
	scanf("%s",x+1);
	scanf("%lld",&b);
	int a = strlen(x+1);
	if(a==1)
	{
		if(x[1]-'0'<=b) printf("1");
		else printf("0");
		return 0;
	}
	
	for(int i=1;i<=a;i++) V.push_back(x[i]-'0');
	
	long long int min = 2;
	for(int i=0;i<V.size();i++) min = min>V[i]+1?min:V[i]+1;
	long long int C = min;
	long long int ans = min-1;
	long long int max = (long long int)1e18;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int sum = 0;
		for(int i=0;i<V.size();i++)
		{
			if(sum  > (double)(b-V[i])/h)
			{
				max = h-1;
				goto u;
			}
			sum *= h;
			sum += V[i];
		}
		ans = h;
		min = h+1;
		u:;
	}
	//printf("%lld %lld!!\n",ans,C);
	printf("%lld",ans-C+1);
}