#include <stdio.h>


int direX[5]={1,0,-1,0},direY[5]={0,1,0,-1};
char x[110][110];
int y[110][110];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=a+1;j++) y[i][j] = -2;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[i][j]=='B') y[i][j] = 0;
			else if(x[i][j]=='W') y[i][j] = 1;
		}
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) y[i][j] += (i+j), y[i][j] %= 2;
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if(x[i][j]=='?') y[i][j] = -1;
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(y[i][j]==-1)
			{
				int count1 = 0 ,count2 = 0;
				for(int k=0;k<4;k++)
				{
					if(y[i+direX[k]][j+direY[k]]==1) count1++;
					else if(y[i+direX[k]][j+direY[k]]==2) count2++;
					if(count1>count2) y[i][j] = 1;
					else y[i][j] = 2;
				}
			}
			
			if(y[i][j]==y[i-1][j]) ans++;
			if(y[i][j]==y[i][j-1]) ans++;
		}
	}
	printf("%d",ans);
}