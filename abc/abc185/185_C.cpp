#include <stdio.h>

long long int check[210][210];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(s==t) return 1;
	if(check[s][t]!=0) return check[s][t];
	return check[s][t] = comb(s-1,t-1)+comb(s-1,t);
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("%lld",comb(a-1,11));
}
