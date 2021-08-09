#include <stdio.h>
#include <string.h>
#include <vector>

char x[110];
std::vector<char> ind1, ind2;
int main()
{
	int a;
	scanf("%d",&a);
	
	int max1 = 0, max2 = 0;
	
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%s%d",x+1,&b);
		int c = strlen(x+1);
		if(max1<=b)
		{
			max2 = max1;
			ind2 = ind1;
			
			max1 = b;
			ind1.clear();
			for(int j=1;j<=c;j++) ind1.push_back(x[j]);
		}
		else if(max2<=b)
		{
			max2 = b;
			ind2.clear();
			for(int j=1;j<=c;j++) ind2.push_back(x[j]);
		}
	}
	
	for(int j=0;j<ind2.size();j++) printf("%c",ind2[j]);
}