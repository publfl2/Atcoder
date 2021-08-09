#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	int ans = 1234567890;
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		if(b>=d) continue;
		ans = ans<c?ans:c;
	}
	if(ans==1234567890) printf("-1");
	else printf("%d",ans);
}