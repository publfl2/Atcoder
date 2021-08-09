#include <stdio.h>

char x[100010];
int count[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		count[x[1]-'A']++;
	}
	printf("AC x %d\n",count[0]);
	printf("WA x %d\n",count['W'-'A']);
	printf("TLE x %d\n",count['T'-'A']);
	printf("RE x %d\n",count['R'-'A']);
}
