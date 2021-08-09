#include <stdio.h>

int x[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);

	int s = 0;
	for(int i=1;i<=a;i++) s += x[i];
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]<=((s-1)/(4*b)));
		else count++;
	}
	printf("%s",count>=b?"Yes":"No");
}
