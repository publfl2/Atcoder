#include <stdio.h>
#include <vector>

int count[110];
std::pair<int,int> P[110],x[110];
int ans = 0;
int b;
void func(int k)
{
	if(k==0)
	{
		int C = 0;
		for(int i=1;i<=b;i++)
		{
			if(count[P[i].first]>=1 && count[P[i].second]>=1) C++;
		}
		ans = ans>C?ans:C;
		return;
	}
	
	count[x[k].first]++;
	func(k-1);
	count[x[k].first]--;
	count[x[k].second]++;
	func(k-1);
	count[x[k].second]--;
}
int main()
{
	int a;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i]=std::make_pair(c,d);
	}
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		x[i]=std::make_pair(d,e);
	}
	func(c);
	printf("%d",ans);
}
