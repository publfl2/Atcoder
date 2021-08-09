#include <stdio.h>

int check[110];
int main()
{
	int a;
	scanf("%d",&a);
	a%=10;
	check[2] = check[4] = check[5] = check[7] = check[9] = 1;
	check[0] = check[1] = check[6] = check[8] = 2;
	check[3] = 3;
	if(check[a]==1) printf("hon");
	else if(check[a]==2) printf("pon");
	else printf("bon");
}
