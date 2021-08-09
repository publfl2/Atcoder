#include <stdio.h>
#include <string.h>

char x[200010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) if(x[i]=='?') x[i] = 'D';
	for(int i=1;i<=a;i++) printf("%c",x[i]);
}
