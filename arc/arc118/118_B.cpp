#include <stdio.h>
#include <vector>
#define MAX (long long int)1e18

std::pair<long long int, long long int> P[100010],P2[100010];
long long int x[100010];
long long int value[100010];
int main()
{
	int a;
	long long int b,c;
	scanf("%d%lld%lld",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	long long int min = 0, max = MAX;
	long long int ans = MAX;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		
		for(int i=1;i<=a;i++)
		{
			long long int L,R;
			if(c*x[i]-h < 0) L = 0;
			else if((c*x[i]-h)%b==0) L = (c*x[i]-h)/b;
			else L = (c*x[i]-h)/b + 1;
			
			R = (c*x[i]+h)/b;
			if(L>R)
			{
				min = h+1;
				goto u;
			}
			P[i] = std::make_pair(L,R);
		}
		
		P2[a] = P[a];
		for(int i=a-1;i>=1;i--) P2[i] = {P2[i+1].first+P[i].first,P2[i+1].second+P[i].second};
		
		if(P2[1].first <= c && c <= P2[1].second)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
		u:;
	}
	
	//printf("%lld??\n",ans);
	
	long long int h = ans;
	for(int i=1;i<=a;i++)
	{
		long long int L,R;
		if(c*x[i]-h < 0) L = 0;
		else if((c*x[i]-h)%b==0) L = (c*x[i]-h)/b;
		else L = (c*x[i]-h)/b + 1;
		
		R = (c*x[i]+h)/b;
		P[i] = std::make_pair(L,R);
	}
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += P[i].first;
	for(int i=1;i<=a;i++) value[i] = P[i].first;
	for(int i=1;i<=a;i++)
	{
		int t = (c-sum)<(P[i].second-P[i].first)?(c-sum):(P[i].second-P[i].first);
		value[i] += t;
		sum += t;
	}
	
	for(int i=1;i<=a;i++) printf("%lld ",value[i]);
}