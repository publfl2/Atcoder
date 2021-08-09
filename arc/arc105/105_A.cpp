#include <stdio.h>

int control = 0;
long long int x[10];
int check[110];
void func(int k)
{
	if(k==5)
	{
		long long int sum1 = 0, sum2 = 0;
		for(int i=1;i<=4;i++)
		{
			if(check[i]==0) sum1 += x[i];
			else sum2 += x[i];
		}
		if(sum1==sum2) control = 1;
		return;
	}
	check[k] = 0;
	func(k+1);
	check[k] = 1;
	func(k+1);
}

int main()
{
	for(int i=1;i<=4;i++) scanf("%lld",&x[i]);
	func(1);
	printf("%s",control==1?"Yes":"No");
}
