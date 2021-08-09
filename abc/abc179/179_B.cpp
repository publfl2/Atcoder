#include <stdio.h>


int x[110],y[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
	
	for(int i=1;i<=a-2;i++)
	{
		if(x[i]==y[i]&&x[i+1]==y[i+1]&&x[i+2]==y[i+2])
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}
