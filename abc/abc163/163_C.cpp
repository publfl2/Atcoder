#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b;
		scanf("%d",&b);
		V[b].push_back(i);
	}
	
	for(int i=1;i<=a;i++) printf("%d\n",V[i].size());
}
