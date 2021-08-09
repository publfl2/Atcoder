#include <stdio.h>

int x[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	
	int max = a, min = a;
	for(int i=a;i<=101;i++)
	{
		for(int j=1;j<=b;j++) if(i==x[j]) goto u;
		max = i;
		break;
		u:;
	}
	
	for(int i=a;i>=0;i--)
	{
		for(int j=1;j<=b;j++) if(i==x[j]) goto v;
		min = i;
		break;
		v:;
	}
	
	if(a-min<=max-a) printf("%d",min);
	else printf("%d",max);
}
