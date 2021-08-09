#include <stdio.h>
#include <string.h>

char x[110];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int ans = 0;
	for(int i=1;i+3<=a;i++)
	{
		if(x[i]=='Z'&&x[i+1]=='O'&&x[i+2]=='N'&&x[i+3]=='e') ans++;
	}
	printf("%d",ans);
}