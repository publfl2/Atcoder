#include <stdio.h>

int x[110],ans[110];
int a;
void func(int k, int value, int& sum)
{
	x[k] = value;
	if(k==1)
	{
		sum++;
		if(sum==a) for(int i=1;i<=10;i++) ans[i] = x[i];
		return;
	}
	
	if(value>=1) func(k-1,value-1,sum);
	func(k-1,value,sum);
	if(value<=8) func(k-1,value+1,sum);
	
}
int main()
{
	scanf("%d",&a);
	
	int sum = 0;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=9;j++)
		{
			func(i,j,sum);
		}
	}
	
	int p = 0;
	for(int i=10;i>=1;i--)
	{
		if(ans[i]!=0)
		{
			p = i;
			break;
		}
	}
	for(int i=p;i>=1;i--) printf("%d",ans[i]);
}
