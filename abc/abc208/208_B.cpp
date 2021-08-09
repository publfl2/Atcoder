#include <stdio.h>

int fact[20];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=10;i++) fact[i] = i*fact[i-1];
	
	int a;
	scanf("%d",&a);
	int ans = 0;
	for(int i=10;i>=1;i--)
	{
		ans += a/fact[i];
		a %= fact[i];
	}
	printf("%d",ans);
}