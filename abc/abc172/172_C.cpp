#include <stdio.h>

int x[200010],y[200010];
long long int s[200010],t[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) s[i] = s[i-1] + x[i];
	for(int i=1;i<=b;i++) t[i] = t[i-1] + y[i];
	
	int ans = 0;
	for(int i=0;i<=a;i++)
	{
		if(s[i]<=c)
		{
			int min = 0, max = b;
			int C = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(s[i]+t[h]<=c)
				{
					C = h;
					min = h+1;
				}
				else max = h-1;
			}
			ans = ans>i+C?ans:i+C;
		}
	}
	printf("%d",ans);
}
