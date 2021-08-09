#include <stdio.h>

int check[200010];
void func(int s, int t)
{
	if(t==0) return;
	
	int k = s/2;
	func(s-2,t-1);
	
	for(int i=1;i<=2*k-1;i+=2)
	{
		if(check[i]!=0)
		{
			check[i] +=2;
			if(check[i]==s) check[i] = 2;
		}
	}
	check[s-1] = s;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	if(a%2==0)
	{
		func(a,b);
		for(int i=1;i<=a;i+=2) if(check[i]!=0) printf("%d %d\n",i,check[i]);
	}
	else
	{
		for(int i=1;i<=b;i++) printf("%d %d\n",i,a-i+1);
	}
}
