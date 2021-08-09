#include <stdio.h>
#include <vector>
std::vector<int> V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		if(c!=b) V.push_back(c);
	}
	for(int i=0;i<V.size();i++) printf("%d ",V[i]);
}
