#include <stdio.h>
#include <vector>
#include <string.h>
#define MOD 99999971
std::vector<char> V[200010];

int check[30];
char x[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		for(int j=1;j<=b;j++) V[i].push_back(x[j]);
	}
	for(int i=1;i<=a;i++)
	{
		
		long long int s = 0;
		count.push_back(s,i,V[i].size());
		
		for(int j=V[i].size()-1;j>=0;j--)
		{
			s*=MOD;
			s+=V[i][j];
			count.push_back(s,i,j);
		}
	}
	std::sort(count.begin(),count.end(),cmp);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<=25;j++) check[j] = 0;
		
		for(int j=0;j<V[i].size();j++)
		{
			check[V[i][j]-'a'] = 1;
			int s = 0;
			for(int k=25;k>=0;k--) s*=2, s += check[k];
			V2.push_back(s);
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int s = 0;
		for(int j=V[i].size()-1;j>=1;j--)
		{
			s*=MOD;
			s+=V[i][j];
		}
		
		
	}
	
	printf("%lld",ans-a);
}
