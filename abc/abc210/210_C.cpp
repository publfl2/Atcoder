#include <stdio.h>
#include <map>

std::map<int,int> count;
int x[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int C = 0;
	for(int i=1;i<=b;i++)
	{
		count[x[i]]++;
		if(count[x[i]]==1) C++;
	}
	int ans = C;
	for(int i=b+1;i<=a;i++)
	{
		count[x[i]]++;
		if(count[x[i]]==1) C++;
		count[x[i-b]]--;
		if(count[x[i-b]]==0) C--;
		ans = ans>C?ans:C;
	}
	printf("%d",ans);
}