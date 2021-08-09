#include <stdio.h>

int a;
int check[3010][4][40];
int y[3010];
int func(int s, int t, int bit)
{
	if(t>3) return 0;
	if(s>a)
	{
		if(bit==31) return 1;
		else return 0;
	}
	if(check[s][t][bit]!=-1) return check[s][t][bit];
	int s1 = func(s+1,t,bit);
	int s2 = func(s,t+1,bit|y[s]);
	return check[s][t][bit] = 1-(1-s1)*(1-s2);
}

struct str{
	int value[6];
}x[3010];

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e,f;
		scanf("%d%d%d%d%d",&b,&c,&d,&e,&f);
		x[i].value[1] = b;
		x[i].value[2] = c;
		x[i].value[3] = d;
		x[i].value[4] = e;
		x[i].value[5] = f;
	}
	
	int min = 0, max = 1000000000;
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i=1;i<=a;i++)
		{
			int sum = 0;
			for(int j=1;j<=5;j++)
			{
				sum*=2;
				if(x[i].value[j]>=h) sum++;
			}
			y[i] = sum;
		}
		
		for(int i=1;i<=a;i++) for(int j=0;j<=3;j++) for(int k=0;k<=31;k++) check[i][j][k] = -1;
		int t = func(1,0,0);
		if(t==1)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	printf("%d",ans);
}