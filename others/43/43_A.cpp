#include <stdio.h>

char x[1010][1010];
int check[1010][1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	check[1][1] = (x[1][1]=='#'?1:0);
	for(int i=1;i<=a;i++) check[i][0] = 12345;
	for(int j=1;j<=b;j++) check[0][j] = 12345;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(i==1&&j==1) continue;
			int s1 = check[i-1][j];
			if(x[i][j]=='#'&&x[i-1][j]=='.') s1++;
			int s2 = check[i][j-1];
			if(x[i][j]=='#'&&x[i][j-1]=='.') s2++;
			check[i][j] = (s1<s2?s1:s2);
		}
	}
	printf("%d",check[a][b]);
}
