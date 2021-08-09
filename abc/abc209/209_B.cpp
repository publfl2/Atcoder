#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum = 0;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		sum += c;
		if(i%2==0) sum--;
	}
	if(sum<=b) printf("Yes");
	else printf("No");
}