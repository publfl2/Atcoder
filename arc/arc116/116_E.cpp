#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int h;
int count = 0;
int func(int s, int prev)
{
	int min = 0, max = 0;
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==prev) continue;
		int t = func(V[s][i],s);
		min = min<t?min:t;
		max = max>t?max:t;
	}
	
	if(max+min-1>=0) return max-1;
	else
	{
		if(min==-h)
		{
			count++;
			return h;
		}
		else return min-1;
	}
}


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	int min = 0, max = a;
	int ans = a;
	while(min<=max)
	{
		h = (min+max)/2;
		count = 0;
		int t = func(1,0);
		if(t<0) count++;
		
		if(count<=b)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	printf("%d",ans);
}