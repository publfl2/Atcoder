#include <stdio.h>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#define MOD 99999971
#define MOD2 998244353
std::vector<char> V[200010];
std::vector< std::pair<long long int, long long int> > V2;
std::map< std::pair<long long int, long long int> ,int> target;

int count[30][1000010];
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
		long long int s = 0, s2 = 0;
		long long int C = 1;
		for(int j=V[i].size()-1;j>=1;j--)
		{
			s*=MOD;
			s+=V[i][j];
			s2+=V[i][j]*C;
			C*=MOD2;
			V2.push_back(std::make_pair(s,s2));
		}
	}
	V2.push_back(std::make_pair(0,0));
	std::sort(V2.begin(),V2.end());
	target[V2[0]] = 1;
	int c = 1;
	for(int i=1;i<V2.size();i++)
	{
		if(V2[i]!=V2[i-1]) c++;
		target[V2[i]] = c;
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<=26;j++) check[j] = 12345678;
		for(int j=0;j<V[i].size();j++) if(check[V[i][j]-'a']==12345678) check[V[i][j]-'a'] = j;
		
		long long int s = 0, s2 = 0;
		int t = target[std::make_pair(s,s2)];
		for(int k=0;k<=25;k++) if(check[k]<V[i].size()) count[k][t]++;
		
		long long int C = 1;
		for(int j=V[i].size()-1;j>=0;j--)
		{
			s*=MOD;
			s+=V[i][j];
			s2+=V[i][j]*C;
			C*=MOD2;
			t = target[std::make_pair(s,s2)];
			for(int k=0;k<=25;k++) if(check[k]<j) count[k][t]++;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int s = 0,s2 = 0;
		long long int C = 1;
		for(int j=V[i].size()-1;j>=1;j--)
		{
			s*=MOD;
			s+=V[i][j];
			s2+=V[i][j]*C;
			C*=MOD2;
		}
		ans += count[V[i][0]-'a'][target[std::make_pair(s,s2)]];
	}
	
	printf("%lld",ans-a);
}
