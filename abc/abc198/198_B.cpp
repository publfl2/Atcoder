#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	int a;
	scanf("%d",&a);
	if(a==0)
	{
		printf("Yes");
		return 0;
	}
	
	while(a%10==0) a/=10;
	while(a)
	{
		V.push_back(a%10);
		a/=10;
	}
	for(int i=0;i<V.size();i++)
	{
		if(V[i]!=V[V.size()-1-i])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}