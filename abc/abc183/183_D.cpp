#include <stdio.h>

long long int S[200010];
int main()
{
	int a,e;
	scanf("%d%d",&a,&e);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		S[b] += d;
		S[c] -= d;
	}
	for(int i=1;i<=200000;i++) S[i] += S[i-1];
	for(int i=0;i<=200000;i++)
	{
		if(S[i]>e)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}
