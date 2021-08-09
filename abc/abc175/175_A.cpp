#include <stdio.h>
#include <string.h>
char x[110];
int main()
{
	scanf("%s",x+1);
	int ans = 0, c =0;
	for(int i=1;i<=strlen(x+1);i++)
	{
		if(x[i]=='S') c = 0;
		else c++;
		ans = ans>c?ans:c;
	}
	printf("%d",ans);
}
