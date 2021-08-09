#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	double ans = 0;
	for(int i=1;i<a;i++) ans += (double)a/(a-i);
	printf("%.12lf",ans);
}