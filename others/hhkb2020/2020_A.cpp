#include <stdio.h>
#include <string.h>

char x[10],y[10];
int main()
{
	scanf("%s%s",x+1,y+1);
	if(x[1]=='Y') printf("%c",y[1]+'A'-'a');
	else printf("%c",y[1]);
}
