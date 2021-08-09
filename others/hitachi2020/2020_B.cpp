#include <stdio.h>

int x[100010],y[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	int min1 = x[1], min2 = y[1];
	for(int i=1;i<=a;i++) min1 = min1<x[i]?min1:x[i];
	for(int i=1;i<=b;i++) min2 = min2<y[i]?min2:y[i];
	
	int ans = min1+min2;
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		int t = x[d]+y[e]-f;
		ans = ans<t?ans:t;
	}
	printf("%d",ans);
}