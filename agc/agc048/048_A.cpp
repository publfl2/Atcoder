#include <stdio.h>
#include <string.h>
int check[1010];
char x[1010],y[10];
int cost[1010];
int main()
{
	y[1]= 'a',y[2] = 't', y[3] = 'c', y[4] = 'o';
	y[5] = 'd', y[6] = 'e', y[7] = 'r';
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) check[i] = 0;
		
		int ans = 123456789;
		int S = 0;
		for(int j=1;j<=7;j++)
		{
			int p = j;
			for(int i=1;i<=a;i++)
			{
				if(check[i]) continue;
				cost[i] = p++;
			}
			for(int i=1;i<=a;i++)
			{
				if(check[i]) continue;
				if(x[i]>y[j])
				{
					ans = ans<S+cost[i]-j?ans:S+cost[i]-j;
					break;
				}
			}
			for(int i=1;i<=a;i++)
			{
				if(check[i]) continue;
				if(x[i]==y[j])
				{
					S += (cost[i]-j);
					check[i] = 1;
					goto u;
				}
			}
			goto v;
			u:;
		}
		for(int i=1;i<=a;i++) if(check[i]==0) ans = ans<S?ans:S;
		v:;
		if(ans==123456789) printf("-1\n");
		else printf("%d\n",ans);
	}
}
