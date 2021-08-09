#include <stdio.h>
#include <vector>
#define MAX (long long int)1e18

std::vector<int> ans;
long long int fact[110];
int main()
{
	fact[0] = 0, fact[1] = 1;
	for(int i=2;i<=100;i++) fact[i] = fact[i-1] + fact[i-2];
	
	int L;
	for(int i=1;i<=100;i++)
	{
		if(fact[i]>MAX)
		{
			L = i-1;
			break;
		}
	}
	
	long long int a;
	scanf("%lld",&a);
	
	for(int i=L;i>=1;i--)
	{
		if(a>=fact[i])
		{
			a -= fact[i];
			if(i%2==0) ans.push_back(2);
			else ans.push_back(1);
		}
		if(!ans.empty())
		{
			if(i%2==0) ans.push_back(3);
			else ans.push_back(4);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
}