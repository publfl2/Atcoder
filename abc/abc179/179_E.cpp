#include <stdio.h>
#include <vector>
std::vector<long long int> V;
int check[100010];
int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	
	V.push_back(0);
	V.push_back(b);
	check[b] = 1;
	
	int start,end;
	for(int i=2;;i++)
	{
		b*=b;
		b%=c;
		if(check[b]!=0)
		{
			start = check[b];
			end = i-1;
			break;
		}
		V.push_back(b);
		check[b] = i;
	}
	
	if(a<start)
	{
		long long int ans = 0;
		for(int i=1;i<=a;i++) ans += V[i];
		printf("%lld",ans);
		return 0;
	}
	else
	{
		long long int ans = 0;
		for(int i=1;i<start;i++) ans += V[i];
		long long int S = 0;
		for(int i=start;i<=end;i++) S += V[i];
		ans += S * ((a-start+1)/(end-start+1));
		int k = (a-start+1)%(end-start+1);
		for(int i=start;i<start+k;i++) ans += V[i];
		printf("%lld",ans);
		return 0;
	}
}
