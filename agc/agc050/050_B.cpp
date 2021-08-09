#include <stdio.h>
#include <vector>

int x[510];

int func(int v, int s2, int s3, int type)
{
	if(type==0)
	{
		int ans = func(v+1,0,0,0);
		int t;
		t = func(v+3,s2-1,s3-1,1)+x[v];
		ans = ans>t?ans:t;
		t = func(v+3,s2-1,s3,1)+x[v]+x[v+2];
		ans = ans>t?ans:t;
		t = func(v+3,s2,s3-1,2)+x[v]+x[v+1];
		ans = ans>t?ans:t;
		t = func(v+3,s2,s3,0)+x[v]+x[v+1]+x[v+2];
		ans = ans>t?ans:t;
	}
	else if(type==1)
	{
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				for(int k=0;k<=1;k++)
				{
					int t = func(v+3,s2+j-i,s3+k-i,type)
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
}
