#include <stdio.h>

int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	long long int S = 0;
	for(int i=1;i<=a;i++) S += (x[i]*y[i]);
	printf("%s",S==0?"Yes":"No");
}
