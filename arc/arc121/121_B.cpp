#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX (long long int)1e16

long long int abs(long long int k)
{
	return k>0?k:-k;
}

std::vector<long long int> V[5];
long long int func(int s, int t)
{
	int p = 0;
	long long int ans = MAX;
	for(int i=0;i<V[s].size();i++)
	{
		while(p<V[t].size()&&V[t][p]<V[s][i]) p++;
		if(p<V[t].size()) ans = ans<abs(V[t][p]-V[s][i])?ans:abs(V[t][p]-V[s][i]);
	}
	p = 0;
	for(int i=0;i<V[t].size();i++)
	{
		while(p<V[s].size()&&V[s][p]<V[t][i]) p++;
		if(p<V[s].size()) ans = ans<abs(V[s][p]-V[t][i])?ans:abs(V[s][p]-V[t][i]);
	}
	return ans;
}

char x[5];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		scanf("%s",x+1);
		if(x[1]=='R') V[1].push_back(b);
		if(x[1]=='G') V[2].push_back(b);
		if(x[1]=='B') V[3].push_back(b);	
	}
	std::sort(V[1].begin(),V[1].end());
	std::sort(V[2].begin(),V[2].end());
	std::sort(V[3].begin(),V[3].end());
	
	if(V[1].size()%2==0 && V[2].size()%2==0 && V[3].size()%2==0) printf("0");
	else if(V[1].size()%2==0)
	{
		long long int s1 = func(2,3);
		long long int s2 = MAX;
		if(V[1].size()>0) s2 = func(1,2) + func(1,3);
		printf("%lld",s1<s2?s1:s2);
	}
	else if(V[2].size()%2==0)
	{
		long long int s1 = func(1,3);
		long long int s2 = MAX;
		if(V[2].size()>0) s2 = func(1,2) + func(2,3);
		printf("%lld",s1<s2?s1:s2);
	}
	else if(V[3].size()%2==0)
	{
		long long int s1 = func(1,2);
		long long int s2 = MAX;
		if(V[3].size()>0) s2 = func(1,3) + func(2,3);
		printf("%lld",s1<s2?s1:s2);
	}
}