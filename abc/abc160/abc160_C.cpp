#include <stdio.h>

int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	x[b+1] = a+x[1];
	
	int ans = x[2]-x[1];
	for(int i=2;i<=b;i++) ans = ans>x[i+1]-x[i]?ans:x[i+1]-x[i];
	printf("%d",a-ans);
}
