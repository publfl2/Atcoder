#include <stdio.h>

char x[110][110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	int count = 0;
	for(int i=2;i<a;i++)
	{
		for(int j=2;j<b;j++)
		{
			int s = 0, t = 0;
			if(x[i][j-1]=='#'&&x[i-1][j-1]=='.') s = 1;
			if(x[i][j]=='#'&&x[i-1][j]=='.') t = 1;
			if(s==0&&t==1) count++;
		}
	}
	
	for(int i=2;i<a;i++)
	{
		for(int j=2;j<b;j++)
		{
			int s = 0, t = 0;
			if(x[i][j-1]=='#'&&x[i+1][j-1]=='.') s = 1;
			if(x[i][j]=='#'&&x[i+1][j]=='.') t = 1;
			if(s==0&&t==1) count++;
		}
	}
	
	for(int j=2;j<b;j++)
	{
		for(int i=2;i<a;i++)
		{
			int s = 0, t = 0;
			if(x[i-1][j]=='#'&&x[i-1][j-1]=='.') s = 1;
			if(x[i][j]=='#'&&x[i][j-1]=='.') t = 1;
			if(s==0&&t==1) count++;
		}
	}
	
	for(int j=2;j<b;j++)
	{
		for(int i=2;i<a;i++)
		{
			int s = 0, t = 0;
			if(x[i+1][j]=='#'&&x[i+1][j-1]=='.') s = 1;
			if(x[i][j]=='#'&&x[i][j-1]=='.') t = 1;
			if(s==0&&t==1) count++;
		}
	}
	printf("%d",count);
}
