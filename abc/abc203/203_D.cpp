#include <stdio.h>

int x[810][810],y[810][810];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	
	int min = 0, max = 1e9;
	int ans = max;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[i][j]<=h) y[i][j] = 1;
				else y[i][j] = 0;
			}
		}
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) y[i][j] += y[i][j-1];
		for(int j=1;j<=a;j++) for(int i=1;i<=a;i++) y[i][j] += y[i-1][j];
		
		for(int i=1;i+b-1<=a;i++)
		{
			for(int j=1;j+b-1<=a;j++)
			{
				if(y[i+b-1][j+b-1] - y[i-1][j+b-1] - y[i+b-1][j-1] + y[i-1][j-1] >= (b*b+1)/2)
				{
					ans = h;
					max = h-1;
					goto u;
				}
			}
		}
		min = h+1;
		u:;
	}
	printf("%d",ans);
}