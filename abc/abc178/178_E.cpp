#include <stdio.h>
#include <algorithm>
int x[200010],y[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i] = b-c;
		y[i] = b+c;
	}
	std::sort(x+1,x+a+1);
	std::sort(y+1,y+a+1);
	long long int s1 = x[a]-x[1];
	long long int s2 = y[a]-y[1];
	printf("%lld",s1>s2?s1:s2);
}
