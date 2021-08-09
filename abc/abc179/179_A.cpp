#include <stdio.h>
#include <string.h>

char x[1010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	printf("%s",x+1);
	if(x[a]=='s') printf("es");
	else printf("s");
}
