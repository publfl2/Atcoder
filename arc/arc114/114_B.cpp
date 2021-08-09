#include <stdio.h>
#include <vector>
#define MOD 998244353

int x[200010];
int check[200010];
std::vector<int> V;
int color[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int C = 1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]) continue;
		V.clear();
		int s = i;
		V.push_back(s);
		check[s] = 1;
		while(1)
		{
			s = x[s];
			if(check[s]==1)
			{
				int start = V.size();
				for(int j=0;j<V.size();j++)
				{
					if(V[j]==s)
					{
						start = j;
						break;
					}
					else color[V[j]] = -1;
				}
				if(start<V.size())
				{
					for(int j=start;j<V.size();j++) color[V[j]] = C;
					C++;
				}
				break;
			}
			else
			{
				V.push_back(s);
				check[s] = 1;
			}
		}
	}
	
	long long int ans = 1;
	for(int i=1;i<=C-1;i++) ans*=2, ans%=MOD;
	printf("%lld",ans-1);
}