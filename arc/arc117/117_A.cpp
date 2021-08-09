#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>=b)
	{
		int S = 0;
		for(int i=1;i<=a;i++) S += i;
		for(int i=1;i<b;i++) S -= i;
		for(int i=1;i<=a;i++) V.push_back(i);
		for(int i=1;i<b;i++) V.push_back(-i);
		V.push_back(-S);
	}
	else
	{
		int S = 0;
		for(int i=1;i<a;i++) S += i;
		for(int i=1;i<=b;i++) S -= i;
		for(int i=1;i<a;i++) V.push_back(i);
		for(int i=1;i<=b;i++) V.push_back(-i);
		V.push_back(-S);
	}
	for(int i=0;i<V.size();i++) printf("%d ",V[i]);
}