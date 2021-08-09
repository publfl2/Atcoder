#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int a,b;
long long int check[200010][20];
long long int func(int s, int t)
{
	if(t>b) return 0;
	if(s>a)
	{
		if(t==b) return 1;
		else return 0;
	}
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s1 = t*func(s+1,t);
	long long int s2 = (16-t)*func(s+1,t+1);
	s1 %= MOD, s2 %= MOD;
	return check[s][t] = (s1+s2)%MOD;
}

char x[200010];
int y[200010];
int count[20];
int main()
{
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=1;i<=a;i++) for(int j=0;j<=16;j++) check[i][j] = -1;
	
	for(int i=1;i<=a;i++)
	{
		if('0'<=x[i]&&x[i]<='9') y[i] = (x[i]-'0');
		else y[i] = (x[i]-'A'+10);
	}
	scanf("%d",&b);
	
	long long int ans = 0;
	for(int i=2;i<=a;i++)
	{
		ans += 15*func(i+1,1);
		ans %= MOD;
	}
	
	int S = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<y[i];j++)
		{
			if(i==1&&j==0) continue;
			
			count[j]++;
			if(count[j]==1) S++;
			ans += func(i+1,S);
			ans %= MOD;
			count[j]--;
			if(count[j]==0) S--;
		}
		count[y[i]]++;
		if(count[y[i]]==1) S++;
	}
	
	if(S==b) ans++;
	
	printf("%lld",ans%MOD);
}