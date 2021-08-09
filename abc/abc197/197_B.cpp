#include <stdio.h>

char x[110][110];
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	int ans = 1;
	for(int i=c-1;i>=1;i--)
	{
		if(x[i][d]=='#') break;
		else ans++;
	}
	for(int i=c+1;i<=a;i++)
	{
		if(x[i][d]=='#') break;
		else ans++;
	}
	
	for(int i=d-1;i>=1;i--)
	{
		if(x[c][i]=='#') break;
		else ans++;
	}
	for(int i=d+1;i<=b;i++)
	{
		if(x[c][i]=='#') break;
		else ans++;
	}
	printf("%d",ans);
}