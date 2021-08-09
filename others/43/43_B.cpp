#include <stdio.h>
#include <vector>
int a;
char x[1000010];
std::vector<int> V,V2;
int abs(int k)
{
	return k>0?k:-k;
}
int comb[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=2;i<=a;i++) V.push_back(abs(x[i]-x[i-1]));
	
	int C = 2;
	for(int i=0;i<V.size();i++) if(V[i]==1) C = 1;
	if(C==2) for(int i=0;i<V.size();i++) V[i]/=2;
	
	
	for(int i=0;i<V.size();i++)
	{
		int c = V.size()-1;
		while(c)
		{
			comb[i] += (c/2);
			c/=2;
		}
		c = i;
		while(c)
		{
			comb[i] -= (c/2);
			c/=2;
		}
		c = V.size()-1-i;
		while(c)
		{
			comb[i] -= (c/2);
			c/=2;
		}
	}
	int ans = 0;
	for(int i=0;i<V.size();i++)
	{
		if(comb[i]==0)
		{
			ans += V[i];
			ans %=2;
		}
	}
	
	printf("%d",ans*C);
}
