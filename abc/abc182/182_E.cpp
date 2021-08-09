#include <stdio.h>

int x[2010][2010],check[2010][2010];
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=c;i++)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		x[e][f] = 1;
	}
	for(int i=1;i<=d;i++)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		x[e][f] = 2;
	}
	int control;
	
	for(int i=1;i<=a;i++)
	{
		control = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]==1) control = 1;
			if(x[i][j]==2) control = 0;
			if(control==1) check[i][j] = control;
		}
	}
	for(int i=1;i<=a;i++)
	{
		control = 0;
		for(int j=b;j>=1;j--)
		{
			if(x[i][j]==1) control = 1;
			if(x[i][j]==2) control = 0;
			if(control==1) check[i][j] = control;
		}
	}
	for(int j=1;j<=b;j++)
	{
		control = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]==1) control = 1;
			if(x[i][j]==2) control = 0;
			if(control==1) check[i][j] = control;
		}
	}
	for(int j=1;j<=b;j++)
	{
		control = 0;
		for(int i=a;i>=1;i--)
		{
			if(x[i][j]==1) control = 1;
			if(x[i][j]==2) control = 0;
			if(control==1) check[i][j] = control;
		}
	}
	int ans = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) ans += check[i][j];
	printf("%d",ans);
}
