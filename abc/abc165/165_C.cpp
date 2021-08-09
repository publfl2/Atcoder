#include <stdio.h>

struct str{
	int x0;
	int y0;
	int z0;
	int w0;
}x[20];
int a,b,c;
int A[20];
long long int ans = 0;
void func(int s, int t)
{
	if(s>a)
	{
		long long int count = 0;
		for(int i=1;i<=c;i++)
		{
			if(A[x[i].y0] - A[x[i].x0] == x[i].z0) count+=x[i].w0;
		}
		ans = ans>count?ans:count;
		return;
	}
	else
	{
		for(int i=t;i<=b;i++)
		{
			A[s] = i;
			func(s+1,i);
			A[s] = 0;
		}
	}
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++) scanf("%d%d%d%d",&x[i].x0,&x[i].y0,&x[i].z0,&x[i].w0);
	
	func(1,1);
	printf("%lld",ans);
}
