#include <stdio.h>

char x[100010];
int main()
{
	scanf("%s",x+1);
	if(x[3]==x[4]&&x[5]==x[6]) printf("Yes");
	else printf("No");
}
