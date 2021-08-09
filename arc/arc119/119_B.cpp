#include <stdio.h>
#include <vector>

std::vector<int> V1,V2;
char x[500010],y[500010];

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s%s",x+1,y+1);
	for(int i=1;i<=a;i++) if(x[i]=='0') V1.push_back(i);
	for(int i=1;i<=a;i++) if(y[i]=='0') V2.push_back(i);
	
	if(V1.size()!=V2.size())
	{
		printf("-1");
		return 0;
	}
	
	int count = 0;
	for(int i=0;i<V1.size();i++) if(V1[i]!=V2[i]) count++;
	printf("%d",count);
}