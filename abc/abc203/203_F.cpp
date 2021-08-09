#include <stdio.h>
#include <algorithm>

int x[200010],next[200010];
int check[200010][40];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	if(a==b)
	{
		printf("0 %d",b);
		return 0;
	}
	
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++)
	{
		int min = 0, max = i-1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h]<=x[i]/2)
			{
				next[i] = h;
				min = h+1;
			}
			else max = h-1;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=30;j++)
		{
			check[i][j] = check[i-1][j] > check[next[i]][j-1] + (i-next[i]) ? check[i-1][j] : check[next[i]][j-1] + (i-next[i]);
		}
	}
	
	for(int j=0;j<=30;j++)
	{
		if(a-check[a][j] <= b)
		{
			printf("%d %d",j,a-check[a][j]);
			return 0;
		}
	}
}