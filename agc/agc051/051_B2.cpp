#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
int main()
{
	for(int i=1;i<=5000;i++)
	{
		for(int j=1;j<=5000;j++)
		{
			V.push_back(i*i+j);
		}
	}
	std::sort(V.begin(),V.end());
	V.erase(std::unique(V.begin(),V.end()),V.end());
	printf("%d",V.size());
}
