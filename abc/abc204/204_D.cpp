#include <stdio.h>

int x[110],sum,a;
int check[110][100010];
int ans = 1234567890;
void func(int k, int C)
{
	if(k>a)
	{
		int s1 = C, s2 = sum-C;
		int t = s1>s2?s1:s2;
		ans = ans<t?ans:t;
		return;
	}
	
	if(check[k][C]) return;
	check[k][C] = 1;
	
	func(k+1,C);
	func(k+1,C+x[k]);
	
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) sum += x[i];
	func(1,0);
	printf("%d",ans);
}