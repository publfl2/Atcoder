#include <stdio.h>
#include <vector>

int check[300010],x[300010];
int check2[300010];
int DP[300010],next[300010];
std::vector<int> V,V2,basis;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) check[x[i]] = 1;
	for(int i=1;i<a;i++) if(check[i]==0) V.push_back(i);
	for(int i=1;i<a;i++) if(check[i]==0) V2.push_back(i);
	
	for(int i=0;i<=18;i++)
	{
		for(int j=0;j<V.size();j++)
		{
			if(check2[j]) continue;
			if((V[j]&(1<<i))!=0)
			{
				for(int k=0;k<V.size();k++)
				{
					if(j==k) continue;
					if((V[k]&(1<<i))!=0) V[k] ^= V[j];
				}
				check2[j] = 1;
				break;
			}
		}
	}
	for(int i=0;i<V.size();i++) if(V[i]!=0) basis.push_back(V2[i]);
	
	DP[0] = 1;
	for(int i=1;i<a;i++) DP[i] = -1;
	for(int i=0;i<basis.size();i++)
	{
		for(int j=0;j<a;j++)
		{
			if(DP[j]>0)
			{
				int t = (j^basis[i]);
				if(DP[t]==-1)
				{
					next[t] = j;
					DP[t] = DP[j]+1;
				}
			}
		}
	}
	
	for(int i=1;i<a;i++)
	{
		if(DP[i]==-1)
		{
			printf("-1");
			return 0;
		}
	}
	
	for(int i=1;i<a;i++) printf("%d %d\n",i,next[i]);
}