#include <stdio.h>
#include <vector>
#include <algorithm>

long long int func(long long int k)
{
	if(k==0) return 0;
	std::vector<int> V1,V2;
	while(k)
	{
		V1.push_back(k%10);
		k/=10;
	}
	std::sort(V1.begin(),V1.end());
	V2 = V1;
	std::reverse(V2.begin(),V2.end());
	
	long long int s1 = 0;
	for(int i=0;i<V1.size();i++)
	{
		s1*=10;
		s1+=V1[i];
	}
	long long int s2 = 0;
	for(int i=0;i<V2.size();i++)
	{
		s2*=10;
		s2+=V2[i];
	}
	return s2-s1;
}

long long int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	x[0] = a;
	for(int i=1;i<=b;i++) x[i] = func(x[i-1]);
	printf("%lld",x[b]);
}