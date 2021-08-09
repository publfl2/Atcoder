#include <stdio.h>
#define MAX (long long int)1e16

int a;
int x[30];
long long int ans = MAX;
void func(int k, int val, int C)
{
	if(k==a+1)
	{
		C^=val;
		ans = ans<C?ans:C;
		return;
	}
	
	func(k+1,val|x[k],C);
	func(k+1,x[k],C^val);
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	func(1,0,0);
	printf("%lld",ans);
}