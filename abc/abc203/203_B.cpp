#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int s1 = 0, s2 = 0;
	for(int i=1;i<=a;i++) s1 += i;
	for(int i=1;i<=b;i++) s2 += i;
	s1 *= b, s2 *= a;
	printf("%d",s1*100+s2);
}