#include <stdio.h>

char x[10];
int main()
{
	scanf("%s",x+1);
	printf("%c%c%c",x[2],x[3],x[1]);
}