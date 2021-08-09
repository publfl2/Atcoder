#include <stdio.h>
#include <algorithm>
struct str{
	int x0;
	int y0;
}x[200010];
bool cmp1(str a, str b)
{
	if(a.x0==b.x0) return a.y0>b.y0;
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	if(a.y0==b.y0) return a.x0>b.x0;
	return a.y0<b.y0;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
	if(a%2==1)
	{
		std::sort(x+1,x+a+1,cmp1);
		int min = x[(a+1)/2].x0;
		std::sort(x+1,x+a+1,cmp2);
		int max = x[(a+1)/2].y0;
		printf("%d",max-min+1);
	}
	else
	{
		std::sort(x+1,x+a+1,cmp1);
		int min1 = x[a/2].x0, min2 = x[(a+2)/2].x0;
		std::sort(x+1,x+a+1,cmp2);
		int max1 = x[a/2].y0, max2 = x[(a+2)/2].y0;
		printf("%d",(max1+max2)-(min1+min2)+1);
	}
}
