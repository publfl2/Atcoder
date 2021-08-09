#include <stdio.h>
#include <vector>

int x[200010],check[200010];
std::vector<int> V;
int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(b<=3*a)
	{
		int k = 1;
		for(int i=1;i<=b;i++) k = x[k];
		printf("%d",k);
		return 0;
		
	}
	
	V.push_back(1);
	int k = 1, p = 1;
	check[1] = 1;
	
	for(int i=2;;i++)
	{
		k = x[k];
		if(check[k])
		{
			p = i-check[k];
			break;
		}
		check[k] = i;
		V.push_back(k);
	}
	b %= p;
	while(b<2*a) b += p;
	
	k = 1;
	for(int i=1;i<=b;i++) k = x[k];
	printf("%d",k);
}
