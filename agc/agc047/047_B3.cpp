#include <stdio.h>
#include <vector>
#include <string.h>
int C = 2;
int count[1000010][30];
int next[1000010][30];
char x[1000010];
std::vector<char> V[200010];
int check[30];

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
		for(int j=0;j<=25;j++) check[j] = 12345678;
		for(int j=V[i].size()-1;j>=0;j--) check[V[i][j]-'a'] = j;
		
		int p = 1;
		for(int j=V[i].size();j>=1;j--)
		{
			for(int k=0;k<=25;k++) if(check[k]<j) count[p][k]++;
			if(next[p][V[i][j-1]-'a']==0) next[p][V[i][j-1]-'a'] = C++;
			p = next[p][V[i][j-1]-'a'];
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int p = 1;
		for(int j=V[i].size()-1;j>=1;j--) p = next[p][V[i][j]-'a'];
		ans += count[p][V[i][0]-'a'];
	}
	printf("%lld",ans-a);
}
