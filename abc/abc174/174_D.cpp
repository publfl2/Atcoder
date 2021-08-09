#include <stdio.h>

char x[200010];
int s1[200010],s2[200010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) s1[i] = s1[i-1] + (x[i]=='R'?1:0);
	for(int i=1;i<=a;i++) s2[i] = s2[i-1] + (x[i]=='W'?1:0);
	
	int ans = a;
	for(int i=1;i<=a+1;i++)
	{
		int b = s2[i-1];
		int c = s1[a] - s1[i-1];
		int d = b>c?b:c;
		ans = ans<d?ans:d;
	}
	printf("%d",ans);
}
