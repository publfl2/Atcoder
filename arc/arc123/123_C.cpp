#include <stdio.h>
#include <queue>
#include <vector>

int dist[110];
int check[110];
int func(int s, int t, int ans)
{
	//printf("%d %d %d!!\n",s,t,ans);
	if(s<0)
	{
		if(t==0) return ans;
		else return -1;
	}
	
	t = 10*t + check[s];
	if(t<ans) return -1;
	int s1 = func(s-1,0,ans>dist[t]?ans:dist[t]);
	if(s1!=-1) return s1;
	else
	{
		if(t==ans) return -1;
		else return func(s-1,1,ans>dist[t-1]?ans:dist[t-1]);
	}
	
}

int main()
{
	dist[0] = 0;
	for(int i=0;i<=20;i++) for(int j=i+1;j<=i+3;j++) if(dist[j]==0) dist[j] = dist[i]+1;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		int L;
		for(int i=0;;i++)
		{
			check[i] = a%10;
			a/=10;
			if(a==0)
			{
				L = i;
				break;
			}
		}
		
		printf("%d\n",func(L,0,0));
	}
}