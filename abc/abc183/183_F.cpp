#include <stdio.h>
#include <map>

std::map<int,int> M[200010];
int x[200010];
int next[200010],height[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) M[i][x[i]] = 1;
	for(int i=1;i<=a;i++) next[i] = i, height[i] = 1;
	
	for(int i=1;i<=b;i++)
	{
		std::map<int,int> ::iterator it;
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(c==1)
		{
			while(d!=next[d]) d = next[d];
			while(e!=next[e]) e = next[e];
			if(d==e) continue;
			
			if(height[d]<height[e])
			{
				next[d] = e;
				height[e]++;
				for(it = M[d].begin();it!=M[d].end();it++) M[e][it->first] += (it->second);
			}
			else
			{
				next[e] = d;
				height[d]++;
				for(it = M[e].begin();it!=M[e].end();it++) M[d][it->first] += (it->second);
			}
		}
		else
		{
			while(d!=next[d]) d = next[d];
			printf("%d\n",M[d][e]);
		}
	}
}
