#include <stdio.h>
#include <string.h>

char x[200010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int s = 0;
	for(int i=1;i<=a;i++) s += (x[i]-'0');
	printf("%s",s%9==0?"Yes":"No");
}
