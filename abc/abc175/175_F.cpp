#include <stdio.h>
#include <string.h>

int a;
char x[60][30];
int y[60];

int isPalin[60][30][30];
int check1[60][30][30][3];
long long int check2[60][30][30][3];
long long int MAX = 1;
long long int func(int s, int L, int R, int type)
{
	if(L>R) return 0;
	if(isPalin[s][L][R]==1) return 0;
	
	if(check1[s][L][R][type]==1) return MAX;
	else if(check1[s][L][R][type]==2) return check2[s][L][R][type];
	
	check1[s][L][R][type] = 1;
	long long int ans = MAX;
	if(type==1)
	{
		for(int i=1;i<=a;i++)
		{
			long long int S = MAX;
			int b = strlen(x[i]+1);
			if(b<=R-L+1)
			{
				for(int j=1;j<=b;j++) if(x[s][L-j+b]!=x[i][j]) goto u;
				S = func(s,L+b,R,type) + y[i];
				ans = ans<S?ans:S;
			}
			else
			{
				for(int j=L;j<=R;j++) if(x[s][j]!=x[i][b-j+L]) goto u;
				S = func(i,1,b-R+L-1,3-type) + y[i];
				ans = ans<S?ans:S;
			}
			u:;
		}
	}
	else
	{
		for(int i=1;i<=a;i++)
		{
			long long int S = MAX;
			int b = strlen(x[i]+1);
			if(b<=R-L+1)
			{
				for(int j=1;j<=b;j++) if(x[s][R-j+1]!=x[i][j]) goto v;
				S = func(s,L,R-b,type) + y[i];
				ans = ans<S?ans:S;
			}
			else
			{
				for(int j=L;j<=R;j++) if(x[s][j]!=x[i][1-j+R]) goto v;
				S = func(i,R-L+2,b,3-type) + y[i];
				ans = ans<S?ans:S;
			}
			v:;
		}
	}
	check1[s][L][R][type] = 2;
	return check2[s][L][R][type] = ans;
}


int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
		scanf("%d",&y[i]);
	}
	for(int i=1;i<=a;i++)
	{
		int b = strlen(x[i]+1);
		for(int L=1;L<=b;L++)
		{
			for(int R=L;R<=b;R++)
			{
				for(int k=L;k<=R;k++) if(x[i][k]!=x[i][L-k+R]) goto u;
				isPalin[i][L][R] = 1;
				u:;
			}
		}
	}
	
	long long int ans = MAX;
	for(int i=1;i<=a;i++)
	{
		int b = strlen(x[i]+1);
		long long int s = func(i,1,b,1) + y[i];
		ans = ans<s?ans:s;
	}
	if(ans>=MAX) printf("-1");
	else printf("%lld",ans);
}
