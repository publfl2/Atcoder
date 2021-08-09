#include <stdio.h>
#define MOD 3

int fact[400010],count[400010];
char x[400010];
int comb(int a, int b)
{
	if(count[a]>count[b]+count[a-b]) return 0;
	else return (fact[a]*fact[b]*fact[a-b])%MOD;
}
int main()
{
	fact[0] = 1;
	count[0] = 0;
	for(int i=1;i<=400000;i++)
	{
		int c = i;
		count[i] = count[i-1];
		while(c%MOD==0)
		{
			c/=MOD;
			count[i]++;
		}
		fact[i] = (fact[i-1]*c)%MOD;
	}
	
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	
	int sum = 0;
	for(int i=1;i<=a;i++)
	{
		int c;
		if(x[i]=='W') c = 0;
		if(x[i]=='B') c = 1;
		if(x[i]=='R') c = 2;
		sum += comb(a-1,i-1)*c;
		sum %= MOD;
	}
	if(a%2==1)
	{
		if(sum==0) printf("W");
		if(sum==1) printf("B");
		if(sum==2) printf("R");
	}
	else
	{
		if(sum==0) printf("W");
		if(sum==1) printf("R");
		if(sum==2) printf("B");
	}
}