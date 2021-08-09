#include <stdio.h>

int check[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;(long long int)i*j<=a;j++) check[i*j]++;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) for(int j=1;(long long int)i*j<=a;j++) ans += check[j];
	printf("%lld",ans);
}