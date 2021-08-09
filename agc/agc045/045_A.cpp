#include <stdio.h>

int a;
long long int x[210];
char y[210];
int z[110];

int func(int k, int level, long long int value)
{
	if(k>a)
	{
		if(value==0) return 0;
		else return 1;
	}
	
	if(level==0) return z[0];
	if(level>0)
	{
		if(y[k]=='0')
		{
			if(func(k,level-1,value)==1) return 1;
			int s1 = func(k+1,level,value);
			int s2 = func(k+1,level,value^x[k]);
			return s1*s2;
		}
		else
		{
			if(func(k,level-1,value)==1) return 1;
			int s1 = func(k+1,level,value);
			int s2 = func(k+1,level,value^x[k]);
			return 1-(1-s1)*(1-s2);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		scanf("%s",y+1);
		for(int j=0;j<=60;j++)
		{
			z[j] = 0;
			for(int i=a;i>=1;i--)
			{
				if((x[i]&(1<<j))!=0)
				{
					z[j] = y[i]-'0';
					break;
				}
			}
		}
		
		printf("%d!!\n",func(1,59,0));
		u:;
	}
}
