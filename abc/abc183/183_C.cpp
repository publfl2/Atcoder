#include <stdio.h>

int p = 0;
long long int C = 0;
int x[10][10];
int a,b;

int func(int s, int bit)
{
	if(bit==p)
	{
		if(C+x[s][1]==b) return 1;
		else return 0;
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if((bit&(1<<i))==0)
		{
			C += x[s][i];
			ans += func(i,bit+(1<<i));
			C -= x[s][i];
		}
	}
	return ans;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) p += (1<<i);
	
	printf("%d",func(1,2));
}
