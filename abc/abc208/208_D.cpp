#include <stdio.h>
#define MAX 987654321

int dist[410][410],dist2[410][410];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) dist[i][j] = MAX;
	for(int i=1;i<=a;i++) dist[i][i] = 0;
	
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		dist[c][d] = e;
	}
	
	long long int ans = 0;
	for(int k=1;k<=a;k++)
	{
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) dist2[i][j] = dist[i][j]<dist[i][k] + dist[k][j]? dist[i][j] : dist[i][k] + dist[k][j];
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) dist[i][j] = dist2[i][j];
		
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if(dist[i][j]<MAX) ans += dist[i][j];
	}
	printf("%lld",ans);
}