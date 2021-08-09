#include <stdio.h>
#define MAX 123456789

int check[1010][1010][3];
int x[1010],y[1010];
int a,b;
int func(int s, int t, int type)
{
	if(s>a)
	{
		if(type==0) return (b-t+1);
		else return MAX;
	}
	if(t>b)
	{
		if(type==0) return (a-s+1);
		else return MAX;
	}
	
	if(check[s][t][type]!=-1) return check[s][t][type];
	int s1 = func(s+1,t,1)+1;
	int s2 = func(s,t+1,1)+1;
	int s3 = func(s+1,t+1,0);
	if(x[s]!=y[t]) s3++;
	return check[s][t][type] = s1<s2?s1<s3?s1:s3:s2<s3?s2:s3;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) check[i][j][0] = check[i][j][1] = -1;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	printf("%d",func(1,1,0));
}
