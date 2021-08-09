#include <stdio.h>
#include <map>

int x[300010];
long long int sum[300010];
std::map<long long int, long long int> M;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(i%2==1) sum[i] = sum[i-1] + x[i];
		else sum[i] = sum[i-1] - x[i];
	}
	
	for(int i=0;i<=a;i++) M[sum[i]]++;
	
	long long int ans = 0;
	for(std::map<long long int,long long int> ::iterator it = M.begin();it!=M.end();it++)
	{
		long long int t = (it->second);
		ans += t*(t-1)/2;
	}
	printf("%lld",ans);
}