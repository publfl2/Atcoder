#include <stdio.h>

char x[110][110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	int count = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<b;j++) if(x[i][j]=='.'&&x[i][j+1]=='.') count++;
	for(int j=1;j<=b;j++) for(int i=1;i<a;i++) if(x[i][j]=='.'&&x[i+1][j]=='.') count++;
	printf("%d",count);
}
