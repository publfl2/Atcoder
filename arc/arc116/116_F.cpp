#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
bool cmp(std::pair<int,int> a, std::pair<int,int> b)
{
	return a.second>b.second;
}

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=b;j++) scanf("%d",&x[j]);
		if(b%2==0)
		{
			int s = x[b/2];
			int t = x[b/2 + 1];
			if(s>t) ans += t, V.push_back(s-t);
			else ans += s, V.push_back(t-s);
		}
		else if(b==1) ans += x[1];
		else
		{
			int s = x[(b+1)/2-1];
			int t = x[(b+1)/2];
			int k = x[(b+1)/2+1];
			V2.push_back({s,t,k});
			if(t>s && t>k)
			{
				if(s>k) ans += s;
				else ans += k;
			}
			else if(t<s && t<k)
			{
				if(s>k) ans += t;
				else ans += t;
			}
			else
			{
				if(s>k) ans += t;
				else ans += t;
			}
		}
	}
	if(V.size()%2==0)
	{
		
	}
	
	if(V.empty()) printf("%lld",ans);
	else
	{
		std::sort(V.begin(),V.end());
		std::reverse(V.begin(),V.end());
		for(int i=0;i<V.size();i+=2) ans += V[i];
		printf("%lld",ans);
	}
}