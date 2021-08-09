#include <stdio.h>

int x[200010];
long long int check[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) check[x[i]]++;
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += check[i]*(check[i]-1)/2;
	for(int i=1;i<=a;i++)
	{
		printf("%lld\n",sum-(check[x[i]]*(check[x[i]]-1)/2)+((check[x[i]]-1)*(check[x[i]]-2)/2));
	}
}
