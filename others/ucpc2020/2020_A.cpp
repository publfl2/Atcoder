#include <stdio.h>
#define MAX (long long int)1e16

int x[200010],y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	x[0] = 0, y[0] = 0, x[a+1] = b;
	long long int min = 0, max = MAX, ans = MAX;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int S = h;
		for(int i=0;i<=a;i++)
		{
			S -= y[i];
			if(S<0)
			{
				min = h+1;
				goto u;
			}
			if(S>h) S = S-(x[i+1]-x[i])>h?S-(x[i+1]-x[i]):h;
			else S = S+(x[i+1]-x[i])<h?S+(x[i+1]-x[i]):h;
		}
		ans = h;
		max = h-1;
		u:;
	}
	printf("%lld",ans);
}