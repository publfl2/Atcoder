#include <stdio.h>


int x[100010],check[100010];
int ans[100010],index[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int max = 1;
	for(int i=1;i<=a;i++)
	{
		int count = 1;
		for (int j=1;j<=a;j++)
		{
			if(check[j]) continue;
			index[j] = count++;
		}
		for(int j=a;j>=1;j--)
		{
			if(check[j]) continue;
			if(x[j]==index[j])
			{
				ans[a-i+1] = x[j];
				check[j] = 1;
				goto u;
			}
		}
		printf("-1");
		return 0;
		u:;
	}
	for(int i=1;i<=a;i++) printf("%d\n",ans[i]);
}
