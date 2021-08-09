#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int S = a;
	int p = 0;
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		S -= (d-p);
		if(S<=0)
		{
			printf("No");
			return 0;
		}
		S += (e-d);
		if(S>a) S = a;
		p = e;
	}
	S -= (c-p);
	if(S<=0)
	{
		printf("No");
		return 0;
	}
	printf("Yes");
}
