#include <stdio.h>
#include <algorithm>

int a;
long long int b,c;
int x[5010];
std::pair<int,int> start[5010][5010];
long long int check[5010][5010];
long long int func(int s, int t)
{
	if(s==t) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	if(start[s][t].first==0)
	{
		if(start[s][t+1].first!=0)
		{
			for(int i=start[s][t+1].first;i<=a;i++)
			{
				if(x[i]<s) continue;
				if(x[i]>t) continue;
				start[s][t].first = i;
				break;
			}
		}
		else
		{
			for(int i=start[s-1][t].first;i<=a;i++)
			{
				if(x[i]<s) continue;
				if(x[i]>t) continue;
				start[s][t].first = i;
				break;
			}
		}
	}
	if(start[s][t].second==0)
	{
		if(start[s-1][t].second!=0)
		{
			for(int i=start[s-1][t].second;i>=1;i--)
			{
				if(x[i]<s) continue;
				if(x[i]>t) continue;
				start[s][t].second = i;
				break;
			}
		}
		else
		{
			for(int i=start[s][t+1].second;i>=1;i--)
			{
				if(x[i]<s) continue;
				if(x[i]>t) continue;
				start[s][t].second = i;
				break;
			}
		}
	}
	
	if(x[start[s][t].first]==s) return check[s][t] = func(s+1,t);
	if(x[start[s][t].second]==t) return check[s][t] = func(s,t-1);
	long long int s1 = func(s+1,t)+c;
	long long int s2 = func(s,t-1)+b;
	return check[s][t] = s1<s2?s1:s2;
}
int main()
{
	scanf("%d%lld%lld",&a,&b,&c);
	start[1][a].first = 1;
	start[1][a].second = a;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) check[i][j] = -1;
	printf("%lld",func(1,a));
}
