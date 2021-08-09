#include <stdio.h>

int x[100010];
long long int s[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=0;i--) s[i] = s[i+1] + x[i];
	
	long long int S = 1;
	long long int ans = 0;
	for(int i=0;i<=a;i++)
	{
		ans += S;
		if(S<x[i])
		{
			printf("-1");
			return 0;
		}
		S -= x[i];
		S*=2;
		S = S<s[i+1]?S:s[i+1];
	}
	printf("%lld",ans);
}
