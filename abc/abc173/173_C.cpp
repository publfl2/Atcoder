#include <stdio.h>

int a,b,c;
int ans = 0;
char x[110][110],y[110][110];
int check[110];
void func(int k)
{
	if(k>a+b)
	{
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = x[i][j];
		for(int i=1;i<=a;i++) if(check[i]==1) for(int j=1;j<=b;j++) y[i][j] = '.';
		for(int j=1;j<=b;j++) if(check[a+j]==1) for(int i=1;i<=a;i++) y[i][j] = '.';
		
		int count = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(y[i][j]=='#') count++;
		if(count==c) ans++;
		
		return;
	}
	
	func(k+1);
	check[k] = 1;
	func(k+1);
	check[k] = 0;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	func(1);
	printf("%d",ans);
}
