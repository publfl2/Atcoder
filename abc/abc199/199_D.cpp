#include <stdio.h>
#include <vector>
int a;
std::vector<int> V[30];
int check[30],check2[30],check3[30];
int M[2000010];

int func2(int k, int C)
{
	if(check[k]==0) return 1;
	if(check2[k]!=0)
	{
		if(check2[k]!=C) return 0;
		else return 1;
	}
	check2[k] = C;
	
	for(int i=0;i<V[k].size();i++)
	{
		int t = func2(V[k][i],3-C);
		if(t==0) return 0;
	}
	return 1;
}

void func(int k)
{
	if(k>a)
	{
		for(int i=1;i<=a;i++) check2[i] = 0;
		int ans = 1;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==1 && check2[i]==0)
			{
				int t = func2(i,1);
				if(t==0) return;
				ans*=2;
			}
		}
		
		int sum = 0;
		for(int i=1;i<=a;i++) sum*=2, sum += check[i];
		M[sum] = ans;
		return;
	}
	
	func(k+1);
	check[k] = 1;
	func(k+1);
	check[k] = 0;
}

long long int func3(int k)
{
	if(k>a)
	{
		int sum = 0;
		for(int i=1;i<=a;i++) sum*=2, sum += (1-check3[i]);
		return M[sum];
	}
	
	long long int ans = 0;
	ans += func3(k+1);
	for(int i=0;i<V[k].size();i++) if(check3[V[k][i]]==1) return ans;
	
	check3[k] = 1;
	ans += func3(k+1);
	check3[k] = 0;
	return ans;
}

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	func(1);
	printf("%lld",func3(1));
}