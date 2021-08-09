#include <stdio.h>
#define MOD 1000000007

char x[2010][2010],y[2010];
int check1[2010][2010],check2[2010][2010];
long long int power[4000010];

int main()
{
	power[0] = 1;
	for(int i=1;i<=4000000;i++) power[i] = power[i-1]*2, power[i]%=MOD;
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j]='#';
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		for(int j=1;j<=b;j++) x[i][j] = y[j];
	}
	
	for(int i=1;i<=a;i++)
	{
		int p = 1;
		for(int j=1;j<=b+1;j++)
		{
			if(x[i][j]=='#')
			{
				for(int k=p;k<j;k++) check1[i][k] = (j-p);
				p = j+1;
			}
		}
	}
	for(int j=1;j<=b;j++)
	{
		int p = 1;
		for(int i=1;i<=a+1;i++)
		{
			if(x[i][j]=='#')
			{
				for(int k=p;k<i;k++) check2[k][j] = (i-p);
				p = i+1;
			}
		}
	}
	long long int ans = 0;
	int count1 = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='.') count1++;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='.')
			{
				int count2 = check1[i][j] + check2[i][j]-1;
				long long int S = (power[count1]-power[count1-count2]+MOD)%MOD;
				ans += S;
				ans%=MOD;
			}
		}
	}
	printf("%lld",ans);
}
