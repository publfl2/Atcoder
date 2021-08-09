#include <stdio.h>
#define MAX 12345678
int a,b;
int check[2010][2010],check2[2010][2010];
char x[2010][2010];

int func(int s, int t)
{
	if(s==a&&t==b) return 0;
	if(s>a) return MAX;
	if(t>b) return MAX;
	if(check2[s][t]) return check[s][t];
	
	int s1 = -func(s+1,t);
	if(x[s+1][t]=='-') s1--;
	else s1++;
	int s2 = -func(s,t+1);
	if(x[s][t+1]=='-') s2--;
	else s2++;
	
	check2[s][t] = 1;
	return check[s][t] = s1>s2?s1:s2;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	int t = func(1,1);
	if(t>0) printf("Takahashi");
	else if(t<0) printf("Aoki");
	else printf("Draw");
}