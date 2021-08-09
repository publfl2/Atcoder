#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	if(d<b) d += 60, c--;
	if(c<a) c+=24;
	int s = (c-a)*60 + (d-b);
	printf("%d",s<e?0:s-e);
}
