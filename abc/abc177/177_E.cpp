#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[1000010],check[1010],check2[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int g = x[1];
	for(int i=2;i<=a;i++) g = gcd(g,x[i]);
	if(g>1)
	{
		printf("not coprime");
		return 0;
	}
	
	for(int i=2;i<=1000;i++)
	{
		if(check[i]==0)
		{
			for(int j=i;j<=1000;j+=i) check[j] = 1;
			
			int count = 0;
			for(int j=1;j<=a;j++) if(x[j]%i==0) count++;
			if(count>=2)
			{
				printf("setwise coprime");
				return 0;
			}
			for(int j=1;j<=a;j++) while(x[j]%i==0) x[j]/=i;
		}
	}
	
	for(int i=1;i<=a;i++) check2[x[i]]++;
	for(int i=2;i<=1000000;i++)
	{
		if(check2[i]>=2)
		{
			printf("setwise coprime");
			return 0;
		}
	}
	
	printf("pairwise coprime");
}
