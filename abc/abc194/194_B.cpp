#include <stdio.h>

int x[1010],y[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	int ans = 12345678;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			int t = x[i]>y[j]?x[i]:y[j];
			ans = ans<t?ans:t;
			t = y[i]>x[j]?y[i]:x[j];
			ans = ans<t?ans:t;
		}
	}
	for(int i=1;i<=a;i++) ans = ans<x[i]+y[i]?ans:x[i]+y[i];
	printf("%d",ans);
}