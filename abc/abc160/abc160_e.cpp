#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
int x[100010],y[100010],z[100010];
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(int i=1;i<=c;i++) scanf("%d",&x[i]);
	for(int i=1;i<=d;i++) scanf("%d",&y[i]);
	for(int i=1;i<=e;i++) scanf("%d",&z[i]);
	std::sort(x+1,x+c+1);
	std::sort(y+1,y+d+1);
	std::sort(z+1,z+e+1);
	for(int i=c;i>=c-a+1;i--) Q.push(x[i]);
	for(int i=d;i>=d-b+1;i--) Q.push(y[i]);
	
	long long int ans = 0;
	for(int i=e;i>=1;i--)
	{
		int f = Q.top();
		if(f<z[i])
		{
			Q.pop();
			ans += z[i];
		}
		else break;
	}
	while(!Q.empty())
	{
		ans += Q.top();
		Q.pop();
	}
	printf("%lld",ans);
}
