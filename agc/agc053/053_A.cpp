#include <stdio.h>
#include <string.h>

int ans[110][10010];
int a;
char x[110];
int y[110];

void func(int k)
{
	printf("%d\n",k);
	for(int i=0;i<=a;i++)
	{
		int s = y[i]/k;
		int t = y[i]%k;
		for(int j=1;j<=t;j++) ans[i][j] = s+1;
		for(int j=t+1;j<=k;j++) ans[i][j] = s;
	}
	
	for(int j=1;j<=k;j++)
	{
		for(int i=0;i<=a;i++) printf("%d ",ans[i][j]);
		printf("\n");
	}
}

int main()
{
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=0;i<=a;i++) scanf("%d",&y[i]);
	
	int limit = 10000;
	for(int i=limit;i>=1;i--)
	{
		int s = y[0]/i;
		int t = y[0]%i;
		for(int j=1;j<=a;j++)
		{
			int s2 = y[j]/i;
			int t2 = y[j]%i;
			if(x[j]=='<')
			{
				if(t<t2)
				{
					if(s+1 < s2+1 && s < s2+1 && s<s2);
					else goto u;
				}
				else if(t>t2)
				{
					if(s+1 < s2+1 && s+1 < s2 && s<s2);
					else goto u;
				}
				else
				{
					if(s+1 < s2+1 && s<s2);
					else goto u;
				}
			}
			else
			{
				if(t<t2)
				{
					if(s+1 > s2+1 && s > s2+1 && s>s2);
					else goto u;
				}
				else if(t>t2)
				{
					if(s+1 > s2+1 && s+1 > s2 && s>s2);
					else goto u;
				}
				else
				{
					if(s+1 > s2+1 && s>s2);
					else goto u;
				}
			}
			s = s2;
			t = t2;
		}
		
		func(i);
		return 0;
		u:;
	}
}