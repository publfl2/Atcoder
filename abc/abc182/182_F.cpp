#include <stdio.h>
#include <map>
long long int x[60];
int a;
std::map<long long int, long long int> check[60];
long long int func(int s, long long int t)
{
	if(s==a) return 1;
	if(t==0) return 1;
	if(check[s].find(t)!=check[s].end()) return check[s][t];
	
	long long int d = x[s+1]/x[s];
	long long int s1=0,s2=0;
	if(t%d!=0) s1 = func(s+1,t/d);
	s2 = func(s+1,(t-1)/d+1);
	return check[s][t] = s1+s2;
}
int main()
{
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	printf("%lld",func(1,b));
}
