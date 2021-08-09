#include <stdio.h>

int x[510][510],y[510],z[510];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	y[1] = 0;
	for(int j=1;j<=a;j++) z[j] = x[1][j] - y[1];
	for(int i=2;i<=a;i++) y[i] = x[i][1] - z[1];
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[i][j]!=y[i]+z[j])
			{
				printf("No");
				return 0;
			}
		}
	}
	
	int min = 0;
	for(int i=1;i<=a;i++) min = min<y[i]?min:y[i];
	for(int i=1;i<=a;i++) y[i] -= min;
	for(int j=1;j<=a;j++) z[j] += min;
	for(int j=1;j<=a;j++)
	{
		if(z[j]<0)
		{
			printf("No");
			return 0;
		}
	}
	
	printf("Yes\n");
	for(int i=1;i<=a;i++) printf("%d ",y[i]);
	printf("\n");
	for(int i=1;i<=a;i++) printf("%d ",z[i]);
}