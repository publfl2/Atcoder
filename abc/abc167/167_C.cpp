#include <stdio.h>

int ans = 123456789;
int check[20];
int S = 0;
int a,b,c;
int x[20],y[20][20];
void func(int k)
{
	if(k>a)
	{
		for(int j=1;j<=b;j++) if(check[j]<c) return;
		ans = ans<S?ans:S;
		return;
	}
	
	func(k+1);
	S += x[k];
	for(int j=1;j<=b;j++) check[j] += y[k][j];
	func(k+1);
	for(int j=1;j<=b;j++) check[j] -= y[k][j];
	S -= x[k];
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&x[i]);
		for(int j=1;j<=b;j++) scanf("%d",&y[i][j]);
	}
	
	func(1);
	printf("%d",ans==123456789?-1:ans);
}
