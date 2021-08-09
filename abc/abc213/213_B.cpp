#include <stdio.h>
#include <algorithm>

std::pair<int,int> x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i].first);
	for(int i=1;i<=a;i++) x[i].second = i;
	std::sort(x+1,x+a+1);
	printf("%d",x[a-1].second);
}