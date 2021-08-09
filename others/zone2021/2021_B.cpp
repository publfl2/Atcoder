#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	double ans = 0;
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		int s = b-d;
		int t = b*e-d*c;
		ans = ans>(double)t/s?ans:(double)t/s;
	}
	printf("%.12lf",ans);
}