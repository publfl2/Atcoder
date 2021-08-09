#include <stdio.h>
#include <map>
int min;
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
std::map<int,int> check[2010];
std::map<int,int> count;
int a;
int x[2010];
void func(int k, int g)
{
	if(k>a)
	{
		if(g<=min) count[g] = 1;
		return;
	}
	if(check[k][g]) return;
	check[k][g] = 1;
	func(k+1,g);
	func(k+1,gcd(g,x[k]));
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	min = x[1];
	for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
	func(1,0);
	printf("%d\n",count.size()-1);
}
