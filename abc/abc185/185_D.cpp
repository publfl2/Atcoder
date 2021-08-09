#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 1234567890

std::vector<int> V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		V.push_back(c);
	}
	V.push_back(0);
	V.push_back(a+1);
	std::sort(V.begin(),V.end());
	int min = MAX;
	for(int i=0;i+1<V.size();i++)
	{
		int d = V[i+1]-V[i]-1;
		if(d>0) min = min<d?min:d;
	}
	if(min==MAX) printf("0");
	else
	{
		long long int ans = 0;
		for(int i=0;i+1<V.size();i++)
		{
			int d = V[i+1]-V[i]-1;
			if(d>0) ans += (d-1)/min+1;
		}
		printf("%lld",ans);
	}
}
