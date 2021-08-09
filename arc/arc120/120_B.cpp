#include <stdio.h>
#define MOD 998244353
char x[510][510];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	long long int ans = 1;
	for(int i=2;i<=a+b;i++)
	{
		int control1 = 0, control2 = 0, count = 0;
		for(int j=1;j<=a;j++)
		{
			if(i-j<1) continue;
			if(i-j>b) continue;
			if(x[j][i-j]=='R') control1 = 1;
			if(x[j][i-j]=='B') control2 = 1;
			if(x[j][i-j]=='.') count++;
		}
		if(control1==1&&control2==1)
		{
			printf("0");
			return 0;
		}
		else if(control1==1);
		else if(control2==1);
		else if(count>0) ans *= 2, ans %= MOD;
	}
	printf("%lld",ans);
}