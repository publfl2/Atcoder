#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}
int check[2010];
int dist[2010][2010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<a;i++) for(int j=i+1;j<=a;j++) dist[i][j] = (j-i);
	for(int i=1;i<b;i++) for(int j=b+1;j<=a;j++) dist[i][j] = dist[i][j] < abs(b-i)+abs(j-c)+1? dist[i][j] : abs(b-i)+abs(j-c)+1;
	for(int i=b;i<c;i++) for(int j=i+1;j<=a;j++) dist[i][j] = dist[i][j] < abs(b-i)+abs(j-c)+1? dist[i][j] : abs(b-i)+abs(j-c)+1;
	for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) check[dist[i][j]]++;
	for(int i=1;i<a;i++) printf("%d\n",check[i]);
}
